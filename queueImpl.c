#include <stdio.h>
#include <malloc.h>


typedef struct NodeStruct{
    int data;
    struct NodeStruct* next;
} Node;

typedef struct QueueStruct{
    Node* first;
    Node* last;
} Queue;

Node* newNode(int d){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = d;
    p->next = NULL;
    return p;
}

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->first = NULL;
    q->last = NULL;
    return q;
}

void enqueue(Queue* q, int d){
    if(q==NULL){
	printf("Null Queue!!!\n");
	return;
    }

    Node* new = newNode(d);
    if(q->first == NULL){
	q->first = new;
	q->last = new;
	return;
    }
    q->last->next = new;
    q->last = new;
}

void dequeue(Queue* q, int* d){
    if(q==NULL){
	printf("Null Queue!!!\n");
	return;
    }
    if(q->first==NULL){
	printf("The queue is empty\n");
	return;
    }
    Node* temp = q->first;
    *d = temp->data;
    if(q->first == q->last)
	q->first = q->last = NULL;
    else
	q->first = q->first->next;

    free(temp);
}

int main(){

    Queue* q = initQueue();
    int data;
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    dequeue(q, &data);
    printf("dequeued value = %d\n", data);
    dequeue(q, &data);
    printf("dequeued value = %d\n", data);
    return 1;
}
