#include "pmsis.h"

// Shared data
int shared_data;

// Synchronization
pi_task_t sync_event;

void cluster_entry(void *arg)
{
    for(uint8_t i=0; i<10; i++)
        printf("Cluster\n");
    
    // Signal completion
    pi_task_push(&sync_event);
}

// Main function running on the Fabric Controller
static int test_entry() {
    // Initialize the cluster configuration
    struct pi_device cluster_dev;
    struct pi_cluster_conf conf;
    pi_cluster_conf_init(&conf);

    // Open the cluster
    pi_open_from_conf(&cluster_dev, &conf);
    if (pi_cluster_open(&cluster_dev)) {
        printf("Cluster open failed!\n");
        pmsis_exit(-1);
    }

    // Define the cluster task
    struct pi_cluster_task task;
    pi_cluster_task(&task, cluster_entry, NULL);

    // Initialize the event
    pi_task_block(&sync_event);

    // Perform operations on shared data
    shared_data = 50;

    // Send the task to the cluster for asynchronous execution
    pi_cluster_send_task_async(&cluster_dev, &task, &sync_event);

    for(uint8_t i=0; i<10; i++)
        printf("FC\n");

    // Wait for the cluster to finish processing
    pi_task_wait_on(&sync_event);

    // Print the result
    printf("Shared data: %d\n", shared_data);

    // Close the cluster
    pi_cluster_close(&cluster_dev);

    pmsis_exit(0);

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