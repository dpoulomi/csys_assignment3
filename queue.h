void queue_init(struct queue_t* q, size_t dataSize);
void enqueue(struct queue_t* queue, void* value);
// void* dequeue(struct queue_t* queue);
// struct process_t* dequeueProcess(struct queue_t* queue);
int qsize(struct queue_t *queue);
void display(struct queue_t *queue);
