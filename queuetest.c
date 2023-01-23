#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"

int main() {
    int choice;
    void* value;
    struct queue_t* queue;
    queue = NULL;
    // queue = (struct queue_t *)malloc(sizeof(struct queue_t));

    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 5) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Dequeue Process\n5.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%s", &value);
                queue = enqueue(queue, &value);
                break;
            case 2:
                printf("Popped element is :%d\n", dequeue(queue));
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Popped process is :%d\n", dequeueProcess(queue));
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
