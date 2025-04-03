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

#define BUFF_SIZE 16

static char ext_buff0[BUFF_SIZE];
static char ext_buff1[BUFF_SIZE];
PI_L1 char loc_buff[BUFF_SIZE];

static void cluster_entry(void *arg)
{
    // This structure is used by the runtime to manage a DMA command.
    //It must be instantiated once for each copy and must be kept alive until the copy is finished.

    // char loc_buff[BUFF_SIZE];

    pi_cl_dma_cmd_t copy;

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

      pi_cl_dma_cmd((int)ext_buff0, (int)loc_buff, BUFF_SIZE, PI_CL_DMA_DIR_EXT2LOC, &copy);

      pi_cl_dma_cmd_wait(&copy);

    for (int i=0; i<BUFF_SIZE; i++)
    {
      loc_buff[i] = (char )(loc_buff[i] * 3);
    }
/*
    pi_cl_dma_cmd((int)ext_buff1, (int)loc_buff, BUFF_SIZE, PI_CL_DMA_DIR_LOC2EXT, &copy);

    pi_cl_dma_cmd_wait(&copy);*/
}

static int test_entry()
{
  printf("Entering main controller\n");

  struct pi_device cluster_dev;
  struct pi_cluster_conf conf;
  struct pi_cluster_task cluster_task;
  struct pi_task task;

  pi_cluster_conf_init(&conf);

  pi_open_from_conf(&cluster_dev, &conf);
    
  pi_cluster_open(&cluster_dev);

  for (int i=0; i<BUFF_SIZE; i++)
  {
    ext_buff0[i] = i;
    printf("%d\n", ext_buff0[i]);
  }

  pi_cluster_task(&cluster_task, cluster_entry, NULL);

  pi_cluster_send_task_to_cl(&cluster_dev, &cluster_task);

  for (int i=0; i<BUFF_SIZE; i++)
  {
    if (loc_buff[i] != (char)(i * 3)) {
      printf("ERROR at index %d / addr %p: expecting 0x%x, got 0x%x\n", i, &loc_buff[i], i*3, loc_buff[i]);
      return -1;
    }
  }

  pi_cluster_close(&cluster_dev);

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
