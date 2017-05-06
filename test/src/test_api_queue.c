#include <stdio.h>
#include <sdsc.h>

int main(int argc, char **argv) {
    QUEUE *queue;
    QUEUE_API *api;
    
    api = new_queue_api();

    queue = api->create_queue();

    if (api->is_empty(queue)) {
        printf("Queue is empty.\n");
    }

    api->enqueue(queue, "this");
    api->enqueue(queue, "is");
    api->enqueue(queue, "a");
    api->enqueue(queue, "test");

    if (api->is_empty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }

    int size = api->size(queue);
    int i;
    for(i = 0; i < size; i++) {
        printf("%s\n", as_str(api->dequeue(queue)));
    }

    if (api->is_empty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }

    api->destroy(&queue);

    return 0;
}
