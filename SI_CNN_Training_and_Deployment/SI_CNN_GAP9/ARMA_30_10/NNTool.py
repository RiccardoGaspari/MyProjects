# coding: utf-8

# # MNist using NNTool python APIs

# In[ ]:


from nntool.api import NNGraph
from nntool.api.utils import RandomIter
from tqdm import tqdm
from glob import glob
from PIL import Image
import numpy as np

path = '/home/rick/SI_CNN_GAP9/'

# In[ ]:

G = NNGraph.load_graph(path + 'ARMA_30_10_Bin_All.onnx')

G.adjust_order()
G.fusions("scaled_match_group")

G.draw()
print("Model before quantization")
print(G.show())


# ## Quantization
# In order to quantize the model we need to collect statistics on real samples

# In[ ]:

stats = G.collect_statistics(RandomIter.fake(G))

# Apply quantization options graph-wise and/or layer-wise.

# In[ ]:


G.quantize(
    stats,
    graph_options={
        "use_ne16": True,
        "hwc": True
    }
)

G.draw()
print("Model AFTER quantization")
print(G.show())

# this shows you instead of the shapes of each tensor, the quantization
G.draw(quant_labels=True)
# this shows you also the arithmetic quantization inside the expressions nodes
G.draw(expressions="quantized")
print("Quantization infos")

# for a more literal inspection
print(G.qshow())


# In[ ]:


# Inference on a single image
test_img = np.random.rand(1, 20)
qout = G.execute(test_img, quantize=True, dequantize=False)
int_test = qout[0][0]


# In[ ]:


directory = "/tmp/mytest"
res = G.execute_on_target(
    directory=directory,
    input_tensors=int_test,
    write_out_to_file=True,
    print_output=True,
    check_on_target=True,
    settings={
        "l1_size": 128000,
        "l2_size": 1300000,
        "tensor_directory": "tensors",
        "model_directory": "model_dir",
        "runner_args": "--trace=insn"
    }
)

"""
G.gen_project(
    directory=path + "ARMA_30_10",
    input_tensors=int_test,
    # output_tensors=4, # 1: constants, 2: input, 4: output, (6 = 4|2: input+output, 7: all)
    # write_out_to_file=True,
    # print_output=True,
    # check_on_target=True,
    settings={
        "l1_size": 128000,
        "l2_size": 1300000,
        "tensor_directory": "tensors",
        "model_directory": "model_dir"
    },
    output_tensors=True
)"""

# In[ ]:


print(res.stdout)


# In[ ]:


res.performance


# In[ ]:


out_gap = np.fromfile(directory + "/Output_1.bin", np.uint16)
print(f"Output from Target:\n{out_gap}")
print(f"Output from NNTool:\n{qout[-1][0]}")
if not np.allclose(out_gap, qout[-1][0]):
    raise ValueError("Outputs from NNTool and target are not the same")
else:
    print("Outputs from NNTool and target are the same")


