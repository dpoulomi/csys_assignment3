struct queue_t* enqueue(struct queue_t* queue, void* value);
void* dequeue(struct queue_t* queue);
struct process_t* dequeueProcess(struct queue_t* queue);
int qsize(struct queue_t *queue);
void display(struct queue_t *queue);