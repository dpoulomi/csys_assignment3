#include "queue.h"
#include "queue_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getDataTypeSize(char *dataTypeName);
struct queue_t *createQueue();
struct queue_t *removeElements(struct queue_t *queue);
struct queue_t *createProcessQueue();
// void display(struct queue_t *queue);
void display(struct queue_t *queue);
void displayProcess(struct queue_t *queue);

int main()
{
    struct queue_t *queue;
    queue = NULL;
    // queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    // queue->front = NULL;
    // queue->rear = NULL;
    queue = createQueue();
    printf("A queue has been created. The elements in the queue are as follows:\n");
    display(queue);
    qsize(queue);
    
    queue = removeElements(queue);
    printf("Calling dequeue function.\n");
    printf("The front of the queue gets deleted and the next element becomes the new front.");
    display(queue);
    queue = removeElements(queue);
    printf("Calling dequeue function again.\n");
    printf("The front node of the queue gets deleted and the next element becomes the new front.");
    display(queue);
    qsize(queue);
    //operations on process_t
    queue = NULL;
    queue = createProcessQueue();
    // qsize(queue);
    // displayProcess(queue);
    // displayProcessQueue(queue);
}

struct queue_t *createProcessQueue()
{
    printf("createProcessQueue\n");
    struct queue_t *queue;
    struct process_t *process1;
    struct process_t *process2;
    struct process_t *process3;

    queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    queue->front = NULL;
    queue->rear = NULL;
    queue->blockSize = sizeof(process_t);

    process3 = (struct process_t *)malloc(sizeof(struct process_t));
    process3->name = "Process_3";
    process3->identifier = 3;
    process3->priority = 3;
    queue->blockSize = sizeof(process3);
    enqueue(queue, process3);

    process2 = (struct process_t *)malloc(sizeof(struct process_t));
    process2->name = "Process_2";
    process2->identifier = 2;
    process2->priority = 2;
    queue->blockSize = sizeof(process2);
    enqueue(queue, process2);

    process1 = (struct process_t *)malloc(sizeof(struct process_t));
    process1->name = "Process_1";
    process1->identifier = 1;
    process1->priority = 1;
    queue->blockSize = sizeof(process1);
    enqueue(queue, process1);

    displayProcess(queue);
    
    dequeueProcess(queue);

    displayProcess(queue);

    qsize(queue);
    return queue;
}


void displayProcess(struct queue_t *queue) {
    if (queue == NULL) {
        printf("\nQueue is Empty\n");
    } else {
        struct node *temp;
        struct process_t* prc;
        temp = queue->front;
        printf("The queue is \n");
        while (temp != NULL) {
            prc = (struct process_t *)(temp->data);
            printf("( %d , %d , %s )--->", prc->identifier, prc->priority, prc->name);
            temp = temp->next;
        }
        printf("NULLLLLLLLL\n\n");
    }
}


 struct queue_t *removeElements(struct queue_t *queue)
{
    printf("Popped element is :%s\n", dequeue(queue));
    if (queue == NULL)
    {
        queue = (struct queue_t *)malloc(sizeof(struct queue_t));
        queue->front = NULL;
        queue->rear = NULL;
        // enqueue(queue, &value);
    }
}

 struct queue_t *createQueue()
{
    struct queue_t *queue;
    queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    char *value = "AB";
    queue->front = NULL;
    queue->rear = NULL;
    void* p = value;
    
    queue->blockSize = strlen(value);
    enqueue(queue, p);
    printf("First element AB added\n");
    display(queue);
    value = "BCD";
    queue->blockSize = strlen(value);
    enqueue(queue, value);
    printf("Second element BCD added at the rear end of the queue\n");
    display(queue);
    value = "CEDF";
    queue->blockSize = strlen(value);
    enqueue(queue, value);
    value = "EDFGH";
    queue->blockSize = strlen(value);
    enqueue(queue, value);
    printf("Two more elements CEDF and EDFGH are added at the rear end of the queue\n");
    display(queue);
   
   
    return queue;
}

void display(struct queue_t *queue)
{
    struct node *temp;
    if (queue == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp = queue->front;
        printf("The queue is \n");
        while (temp != NULL)
        {
            printf("%s--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

// Write a main function in a separate file queuetest.c that exercises all of the functions created above.
// It must create and add several process_t elements to thoroughly exercise the queue. In order to show this,
// you must print a one-line description of what must be in the queue along with the contents of the queue in between steps.
// int main1()
// {
//     int choice;
//     void *value;

//     int identifier;
//     int priority;
//     char name[100];
//     // char *yesno;
//     // int identifier, priority;
//     // char* name;
//     // name = (char *)malloc( sizeof(*name));
//     // char* yes;
//     // char* no;
//     // yesno = (char *)malloc(sizeof(*yesno));
//     // yes = (char *)malloc( sizeof(*yes));
//     // no = (char *)malloc( sizeof(*no));

//     struct queue_t *queue;
//     struct queue_t *process_queue;
//     struct process_t *process;
//     queue = NULL;
//     process_queue = NULL;

//     printf("\nImplementation of Queue using Linked List\n");
//     while (choice != 7)
//     {
//         printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Enqueue Process\n5.Data Type name\n6.Dequeue process\n7.Exit\n");
//         printf("\nEnter your choice : ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:

//             // printf("\nDo you want to insert a process? ");
//             // printf("Yes or No\n");
//             // printf("\nEnter your choice : ");
//             // scanf("%99s", &yesno);

//             // if (strcmp(&yesno, "Yes") == 0)
//             // {

//             // int identifier, priority;
//             // char *name;
//             // name = (char *)malloc(sizeof(*name));
//             // process = (struct process_t *)malloc(sizeof(struct process_t));
//             // printf("\nEnter the identifier: ");
//             // scanf("%d", &identifier);
//             // process->identifier = identifier;
//             // printf("\nEnter the priority: ");
//             // scanf("%d", &priority);
//             // process->priority = priority;
//             // printf("\nEnter the name: ");
//             // scanf("%99s", &name);
//             // printf("test");
//             // process->name = name;
//             // printf(process->identifier);
//             // printf(process->priority);
//             // printf(process->name);
//             // value = process;

//             // enqueue(queue, &value);
//             // }
//             // else if (strcmp(&yesno, "No") == 0)
//             // {
//             printf("\nEnter the value to insert: ");
//             scanf("%s", &value);
//             // }

//             // printf("\nEnter the value to insert: ");
//             // scanf("%s", &value);
//             if (queue == NULL)
//             {
//                 // queue_init(queue, dataTypeSize);
//                 queue = (struct queue_t *)malloc(sizeof(struct queue_t));
//                 queue->front = NULL;
//                 queue->rear = NULL;
//                 enqueue(queue, &value);
//             }
//             else
//             {
//                 enqueue(queue, &value);
//             }
//             break;
//         case 2:
//             printf("Popped element is :%s\n", dequeue(queue));
//             if (queue == NULL)
//             {
//                 // queue_init(queue, dataTypeSize);
//                 queue = (struct queue_t *)malloc(sizeof(struct queue_t));
//                 queue->front = NULL;
//                 queue->rear = NULL;
//                 enqueue(queue, &value);
//             }
//             break;
//         case 3:
//             display(queue);
//             break;
//         case 4:

//             // name = (char *)malloc(sizeof(*name));
//             process = (struct process_t *)malloc(sizeof(struct process_t));
//             printf("\nEnter the identifier: ");
//             scanf("%d", &identifier);
//             process->identifier = identifier;
//             printf("\nEnter the priority: ");
//             scanf("%d", &priority);
//             process->priority = priority;
//             printf("\nEnter the name: ");
//             scanf("%99s", name);
//             printf("test");
//             process->name = name;
//             printf(process->identifier);
//             printf(process->priority);
//             printf(process->name);
//             value = process;
//             if (process_queue == NULL)
//             {
//                 // queue_init(queue, dataTypeSize);
//                 process_queue = (struct queue_t *)malloc(sizeof(struct queue_t));
//                 process_queue->front = NULL;
//                 process_queue->rear = NULL;
//                 enqueue(process_queue, &value);
//             }
//             else
//             {
//                 enqueue(queue, &value);
//             }
//             break;
//         case 6:
//             printf("Popped process is :%s\n", dequeueProcess(queue));
//             break;
//         case 7:
//             exit(0);
//             break;
//         default:
//             printf("\nWrong Choice\n");
//         }
//     }
//     return 0;
// }
