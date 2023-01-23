#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"
#include "queue_t.h"

int getDataTypeSize(char* dataTypeName);

int main() {
    int choice;
    void* value;
    struct queue_t* queue; 
    // queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    queue = NULL;
    // queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    int dataTypeSize = 0;
    char *dataTypeName;

    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 6) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Dequeue Process\n5.Data Type name\n6.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                dataTypeSize = 4;
                if (dataTypeSize == 0) {
                    printf("Please define the dataType first\n");
                    break;
                }
                printf("\nEnter the value to insert: ");
                scanf("%s", &value);
                if (queue == NULL) {
                    // queue_init(queue, dataTypeSize);
                    queue = (struct queue_t *)malloc(sizeof(struct queue_t));
                    queue->blockSize = dataTypeSize;
                    queue->front = NULL;
                    queue->rear = NULL;
                    enqueue(queue, &value);
                } else {
                    enqueue(queue, &value);
                }
                break;
            // case 2:
            //     printf("Popped element is :%d\n", dequeue(queue));
            //     break;
            case 3:
                display(queue);
                break;
            // case 4:
            //     printf("Popped process is :%d\n", dequeueProcess(queue));
            //     break;
            // case 5:
            //     printf("\nEnter datatype name");
            //     scanf("%s", &dataTypeName);
            //     dataTypeSize = getDataTypeSize(&dataTypeName);
            //     break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}

int getDataTypeSize(char* dataTypeName) {
    printf("data type name : %s", *dataTypeName);
    if (*dataTypeName == "int") {
        return 1;
    }
    return 4;
}
