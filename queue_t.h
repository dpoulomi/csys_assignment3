typedef struct node {
    void* data;
    struct node* next;
};node;

typedef struct queue_t {
    struct node* front ;
    struct node* rear;
};queue_t;

