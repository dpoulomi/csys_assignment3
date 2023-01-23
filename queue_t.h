struct queue_t {
   void *data;
    struct queue_t *next;
    struct queue_t *front ;
    struct queue_t *rear;
};