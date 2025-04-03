# coding: utf-8

# # MNist using NNTool python APIs

# In[ ]:


from nntool.api import NNGraph
from nntool.api.utils import RandomIter
from tqdm import tqdm
from glob import glob
from PIL import Image
import numpy as np

# CAL_DATASET = "../mnist_dataset/calibration/*"
# TEST_DATASET = "../mnist_dataset/test/*"

# Load the .npy file
path = '/home/rick/SI_CNN_GAP9/'

# Load the model in NNTool and apply static optimizations

# In[ ]:


G = NNGraph.load_graph(path + 'ARMA_50_30_Bin_All.onnx')

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

G.gen_at_model(
    write_constants=True,
    directory= path + "ARMA_50_30/build",
    settings={
        "l1_size": 128000,
        "l2_size": 1300000,
        "tensor_directory": "tensors",
        "model_directory": "model_dir"
    }
)