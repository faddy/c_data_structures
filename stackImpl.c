#include <stdio.h>
#include <malloc.h>

/*the node to the linked list of the stack*/
typedef struct NodeStruct {
    int data;
    struct NodeStruct* next;
} node;

/*the struct for the stack*/
typedef struct StackStruct{
    node* top;
} Stack;

/*the method to create a new node for the stack*/
node* newNode(int d){
    node* p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->data = d;
    return p;
}

/*initialize a Stack*/
Stack* initStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}

void destroyStack(Stack** s){

    if(*s==NULL){
	printf("The stack is already null\n");
	return;
    }
    if( (*s)->top == NULL){
	
    }

    node* temp;    
    while( ((*s)->top)!=NULL ){
	temp = (*s)->top;
	(*s)->top = (*s)->top->next;
	free(temp);
    }
    free(*s);
}

/*create a new node and push it on the stack*/
void push(Stack* s, int d){
    if(s==NULL){
	printf("Stack is NULL!!\n");
	return;
    }
    node* p = newNode(d);
    if(s->top==NULL) {
	s->top = p;
	return;
    }
    p->next = s->top;
    s->top = p;
}

/*return the data in the node on top of the stack*/
int pop(Stack* s, int* d){
    if(s==NULL) {
	printf("Null stack!!\n");
	return -1;
    }
    if(s->top==NULL) {
	printf("the stack is empty\n");
	return 0;
    }
    *d = s->top->data;
    s->top = s->top->next;
    return 1;
}

int main(){
    Stack* stack = initStack();
    push(stack, 5);
    push(stack, 6);

    int poppedValue=0;
    int success = pop(stack, &poppedValue);
    if(success>0) printf("popped value: %d\n", poppedValue);
    success = pop(stack, &poppedValue);
    if(success>0) printf("popped value: %d\n", poppedValue);
    success = pop(stack, &poppedValue);
    if(success>0) printf("popped value: %d\n", poppedValue);

    destroyStack(&stack);

    push(stack, 2);
    
    return 1;
}
