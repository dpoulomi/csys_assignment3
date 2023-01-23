#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_t.h"

struct process_t
{
    int identifier, priority;
    char *name;
};

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

void queue_init(struct queue_t* q, size_t dataSize)
{
    printf("Queue init starts");
    q = (struct queue_t *)malloc(sizeof(struct queue_t));
    q->blockSize = dataSize;
    q->front = NULL;
    q->rear = NULL;
    printf("Queue init finishes");
}

void enqueue(struct queue_t *queue, void *value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("block size : %d" , queue->blockSize);
    ptr->data = malloc(queue->blockSize);
    printf("size of value :: %d and value is :  %s\n", queue->blockSize, value);
    memcpy(ptr->data, value, queue->blockSize);
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
// void *dequeue(struct queue_t *queue)
// {
//     if (queue->front == NULL)
//     {
//         printf("\nUnderflow\n");
//         return -1;
//     }
//     else
//     {
//         struct queue_t *temp = queue->front;
//         int temp_data = queue->front->data;
//         queue->front = queue->front->next;
//         free(temp);
//         return temp_data;
//     }
// }

// Display all elements of the queue
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
        while (temp)
        {
            // printf("%d--->", temp-> data);
            temp = temp->next;
            count = count + 1;
        }
        printf("Number of elements in queue is: \n", count);
    }
}

// struct process_t *dequeueProcess(struct queue_t *queue)
// {
//     if (queue->front == NULL)
//     {
//         printf("\nUnderflow\n");
//         return -1;
//     }
//     else
//     {
//         struct process_t *temp = queue->front;
//         int priority_of_process;
//         int temp_data = temp->priority;
//         queue->front = queue->front->next;
//         free(temp);
//         return temp_data;
//     }
// }
