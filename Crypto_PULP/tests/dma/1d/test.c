/* 
 * Copyright (C) 2017 ETH Zurich, University of Bologna and GreenWaves Technologies
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 * Authors: Germain Haugou, ETH (germain.haugou@iis.ee.ethz.ch)
 */

#include "pmsis.h"
#include "pmsis/cluster/dma/cl_dma.h"
#include "stdio.h"

#define BUFF_SIZE 2048
#define NB_COPY   4
#define NB_ITER   8
#define COPY_SIZE (BUFF_SIZE/NB_ITER/NB_COPY)
#define ITER_SIZE (BUFF_SIZE/NB_ITER)

static char ext_buff0[BUFF_SIZE];
static char ext_buff1[BUFF_SIZE];
static char *loc_buff;

static void cluster_entry(void *arg)
{
  //printf("(%d, %d) Entered cluster got ptr %p\n", cl_cluster_id(), cl_core_id(), loc_buff);

  for (int j=0; j<NB_ITER; j++)
  {
    // This structure is used by the runtime to manage a DMA command.
    //It must be instantiated once for each copy and must be kept alive until the copy is finished.
    pi_cl_dma_cmd_t copy[NB_COPY];
    for (int i=0; i<NB_COPY; i++)
    // This enqueues a 1D DMA memory transfer (classic memory copy)
    // with simple completion based on transfer identifier.
    // Parameters:
    // -ext:	Address in the external memory where to access the data.
    // -loc:	Address in the cluster memory where to access the data.
    // -size:	Number of bytes to be transferred.
    // -dir:	Direction of the transfer:
    // PI_CL_DMA_DIR_EXT2LOC: external to cluster memory
    // PI_CL_DMA_DIR_LOC2EXT: opposite
    // -cmd:	A pointer to the structure for the copy. This can be used with pi_cl_dma_wait to wait for the completion of this transfer.
      pi_cl_dma_cmd((int)ext_buff0 + COPY_SIZE*i + ITER_SIZE*j, (int)loc_buff + COPY_SIZE*i + ITER_SIZE*j, COPY_SIZE, PI_CL_DMA_DIR_EXT2LOC, &copy[i]);
    // OBS: the L1 memory, although it's a global memory, is physically located
    // inside the cluster, so it can be used as second argument of the function
    // (L1 memory is also preferable wrt L2 when using cluster, considering that
    // it's directly accessible by the cluster cores w.o. needing to go through the FC)
    for (int i=0; i<NB_COPY; i++)
    // Blocks the core until the specified transfer is finished.
    // The transfer must be described trough the identifier given to the copy function.
      pi_cl_dma_cmd_wait(&copy[i]);

    for (int i=0; i<BUFF_SIZE; i++)
    {
      loc_buff[i] = (char )(loc_buff[i] * 3);
    }

    for (int i=0; i<NB_COPY; i++)
      pi_cl_dma_cmd((int)ext_buff1 + COPY_SIZE*i + ITER_SIZE*j, (int)loc_buff + COPY_SIZE*i + ITER_SIZE*j, COPY_SIZE, PI_CL_DMA_DIR_LOC2EXT, &copy[i]);

    for (int i=0; i<NB_COPY; i++)
      pi_cl_dma_cmd_wait(&copy[i]);
  }
}

static int test_entry()
{
  printf("Entering main controller\n");

#if 1 //ef ARCHI_HAS_FC

  struct pi_device cluster_dev;
  struct pi_cluster_conf conf;
  struct pi_cluster_task cluster_task;
  struct pi_task task;

  pi_cluster_conf_init(&conf);

  pi_open_from_conf(&cluster_dev, &conf);
    
  pi_cluster_open(&cluster_dev);

  loc_buff = pmsis_l1_malloc(BUFF_SIZE);

  for (int i=0; i<BUFF_SIZE; i++)
  {
    ext_buff0[i] = i;
  }

  pi_cluster_task(&cluster_task, cluster_entry, NULL);

  pi_cluster_send_task_to_cl(&cluster_dev, &cluster_task);

  for (int i=0; i<BUFF_SIZE; i++)
  {
    if (ext_buff1[i] != (char)(i * 3)) {
      printf("ERROR at index %d / addr %p: expecting 0x%x, got 0x%x\n", i, &ext_buff1[i], i*3, ext_buff1[i]);
      return -1;
    }
  }

  pi_cluster_close(&cluster_dev);

#else

  loc_buff = pmsis_l1_malloc(BUFF_SIZE);

  for (int i=0; i<BUFF_SIZE; i++)
  {
    ext_buff0[i] = i;
  }

  cluster_entry(NULL);
  
  for (int i=0; i<BUFF_SIZE; i++)
  {
    if (ext_buff1[i] != (char)(i * 3)) {
      printf("ERROR at index %d / addr %p: expecting 0x%x, got 0x%x\n", i, &ext_buff1[i], i*3, ext_buff1[i]);
      return -1;
    }
  }

#endif

  printf("TEST SUCCESS\n");

  return 0;
}

static void test_kickoff(void *arg)
{
  int ret = test_entry();
  pmsis_exit(ret);
}

int main()
{
  return pmsis_kickoff((void *)test_kickoff);
}
