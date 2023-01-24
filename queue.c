#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_t.h"

// struct process_t
// {
//     int identifier, priority;
//     char *name;
// };

// Structure to create a node with data and the next pointer
// struct queue_t
// {
//     void *data;
//     struct queue_t *next;
//     struct queue_t *front;
//     struct queue_t *rear;
// };

// struct queue_t *front = NULL;
// struct queue_t *rear = NULL;

// Enqueue() operation on a queue

void enqueue(struct queue_t *queue, void *value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    int blockSize = queue->blockSize; // strlen((char *)value);

    ptr->data = malloc(blockSize);
    printf("size of value :: %d and value is :  %s\n", blockSize, value);
    memcpy(ptr->data, value, blockSize);
    ptr->next = NULL;
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = ptr;
        queue->rear = ptr;
        printf("First node is:  %s\n", ptr->data);
    }
    else
    {
        // printf("Queue %s",queue->data );
        // printf("Queue fromt %s", queue->front->data);
        // printf("Queue rear %s", queue->rear->data);
        queue->rear->next = ptr;
        queue->rear = ptr;
        printf("Next node is:  %s\n", ptr->data);
        printf("Queue front %s\n", queue->front->data);
        printf("Queue rear %s\n", queue->rear->data);
    }
}

// Dequeue() operation on a queue
void *dequeue(struct queue_t *queue)
{
    if (queue->front == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        struct queue_t *temp = queue->front;
        void *temp_data = queue->front->data;
        printf("Popped node is:  %s\n", temp_data);
        queue->front = queue->front->next;
        free(temp);
        return temp_data;
    }
}

// Display all elements of the queue
// void display(struct queue_t *queue)
// {
//     struct node *temp;
//     if (queue == NULL)
//     {
//         printf("\nQueue is Empty\n");
//     }
//     else
//     {
//         temp = queue->front;
//         printf("The queue is \n");
//         while (temp != NULL)
//         {
//             printf("%s--->", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n\n");
//     }
// }

// Display all elements of the queue
// void displayProcessQueue(struct queue_t *queue)
// {
//     struct process_t *temp;
//     if (queue == NULL)
//     {
//         printf("\nQueue is Empty\n");
//     }
//     else
//     {
//         temp = queue->front;
//         printf("The queue is \n");
//         while (temp != NULL)
//         {
//             printf("%s--->", temp->name);
//             printf("\n");
//             printf("%d--->", temp->identifier);
//             printf("\n");
//             printf("%d--->", temp->priority);
//             temp = temp->next;
//         }
//         printf("NULL\n\n");
//     }
// }

int qsize(struct queue_t *queue)
{
    struct node *temp;
    int count = 0;
    if ((queue->front == NULL) && (queue->rear == NULL))
    {
        printf("\nQueue is Empty\n");
        return 0;
    }
    else
    {

        temp = queue->front;
        while (temp!= NULL)
        {
            // printf("%d--->", temp-> data);
            count = count + 1;
            temp = temp->next;
            
        }
        printf("Number of elements in queue is: %d\n", count);
    }
}

struct process_t *dequeueProcess(struct queue_t *queue)
{
    printf("Whats wrong0?");
    if (queue == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        struct node *temp;
        struct process_t *prc;
        struct node *nodeToDelete;
        int priority_of_process;
        printf("Whats wrong0?");
        temp = queue->front;

        prc = (struct process_t *)(temp->data);
        priority_of_process = prc->priority;
        printf("Whats wrong?");
        nodeToDelete = temp;
        printf("Whats wrong?1");
        //         printf("The queue is \n");
        while (temp != NULL)
        {
            prc = (struct process_t *)(temp->data);
            if (priority_of_process < prc->priority)
            {
                priority_of_process = prc->priority;
                nodeToDelete = temp;
                printf("test");
            }
            temp = temp->next;
        }

        // start code
        temp = queue->front;
        if (nodeToDelete->data == queue->front->data)
        {
            queue->front = queue->front->next;
        }
        else
        {
            while (temp->next != nodeToDelete)
            {
                
                temp = temp->next;
            }
            if(temp->next->data == queue->rear->data)
            {
                queue->rear = temp;
                queue->rear->next = nodeToDelete->next;
                 
            }
             temp->next = temp->next->next;
          
            
        }

        // end code
        // if (queue->rear->data == nodeToDelete->data)
        // {
        //     printf("test2");
        //     temp->next = NULL;
        // }
        // else
        // {
        //     printf("test3");
        //     temp = queue->front;
        //     if (queue->front == nodeToDelete)
        //     {
        //         printf("test4");
        //         queue->front = queue->front->next;
        //     }
        //     else
        //     {
        //         while (temp->next != nodeToDelete)
        //         {

        //             temp = temp->next;
        //         }
        //         printf("test5");
        //         temp->next = temp->next->next;
        //     }
        // }
        // queue->front = queue->front->next;
        free(temp);
        return nodeToDelete;
    }
}

// void enqueue(struct queue_t *queue, void *value)
// {
//     struct node *ptr;
//     ptr = (struct node *)malloc(sizeof(struct node));

//     int blockSize = strlen((char *)value);
//     printf("block size : %d" , blockSize);

//     ptr->data = malloc(blockSize);
//     printf("size of value :: %d and value is :  %s\n", blockSize, value);
//     memcpy(ptr->data, value, blockSize);
//     ptr->next = NULL;
//     if (queue->front == NULL && queue->rear == NULL)
//     {
//         queue->front = ptr;
//         queue->rear = ptr;
//         printf("First node is:  %s\n", ptr->data);
//     }
//     else
//     {
//         // printf("Queue %s",queue->data );
//         // printf("Queue fromt %s", queue->front->data);
//         // printf("Queue rear %s", queue->rear->data);
//         queue->rear->next = ptr;
//         queue->rear = ptr;
//         printf("Next node is:  %s\n", ptr->data);
//         printf("Queue front %s\n", queue->front->data);
//         printf("Queue rear %s\n", queue->rear->data);
//     }
// }
