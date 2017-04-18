#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    QUEUE *queue;

    queue = queue_create();

    if (queue_is_empty(queue)) {
        printf("Queue is empty.\n");
    }

    queue_enqueue(queue, "this");
    queue_enqueue(queue, "is");
    queue_enqueue(queue, "a");
    queue_enqueue(queue, "test");

    if (!queue_is_empty(queue)) {
        printf("Queue is not empty.\n");
    }

    int size = queue_size(queue);
    int i;
    for(i = 0; i < size; i++) {
        printf("%s\n", queue_dequeue(queue));
    }

    if (queue_is_empty(queue)) {
        printf("Queue is empty.\n");
    }

    queue_destroy(&queue);
    
    return 0;
}
