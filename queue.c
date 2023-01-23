#include <stdio.h>
#include <stdlib.h>
// #include "queue_t.h"

struct process_t
{
    int identifier, priority;
    char *name;
};

// Structure to create a node with data and the next pointer
struct queue_t
{
    void *data;
    struct queue_t *next;
    struct queue_t *front;
    struct queue_t *rear;
};

// struct queue_t *front = NULL;
// struct queue_t *rear = NULL;

// Enqueue() operation on a queue
struct queue_t* enqueue(struct queue_t *queue, void *value)
{
    struct queue_t *ptr;
    ptr = (struct queue_t *)malloc(sizeof(struct queue_t));
    // ptr->data = (void *)malloc(sizeof(*value));
    ptr->data = value;
    // printf("hello %s", value);
    
    // temp->next
    ptr->next = NULL;
    if (queue == NULL)
    {
        ptr->front = ptr->rear = ptr;
        queue = ptr;
        printf("First node is inserted %s\n",  queue->data);
    }
    else 
    {
        queue->rear->next = ptr;
        queue->rear = ptr;
        printf("Node is Inserted %s\n", queue->data);
    }
    return queue;
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
        int temp_data = queue->front->data;
        queue->front = queue->front->next;
        free(temp);
        return temp_data;
    }
}

// Display all elements of the queue
void display(struct queue_t *queue)
{
    struct queue_t *temp;
    temp = queue;
    if (temp == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("The queue is \n");
        temp = temp->front;
        while (temp)
        {
            printf("%s--->", temp->data);
            temp = temp->next;
        }
        // printf("NULL\n\n");
    }
}

int qsize(struct queue_t *queue)
{
    struct queue_t *temp;
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

struct process_t *dequeueProcess(struct queue_t *queue)
{
    if (queue->front == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        struct process_t *temp = queue->front;
        int priority_of_process;
        int temp_data = temp->priority;
        queue->front = queue->front->next;
        free(temp);
        return temp_data;
    }
}
