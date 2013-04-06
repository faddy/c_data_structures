#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* newNode(int d){
    node* x = (node*)malloc(sizeof(node));
    x->data = d;
    x->next = NULL;
    return x;
}

void append(node** head, int d){
    node* nodeToAdd = newNode(d);
    if (isEmpty(*head)) {
	*head = nodeToAdd;
    }
    else {
	node* temp = *head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next = nodeToAdd;
    }
    
}

int isEmpty(node* head){
    if(head==NULL) return 1;
    else return 0;
}

node* deleteLastNode(node** head){
    if(isEmpty(*head)){
	printf("Cannot delete anything, list is already empty\n");
	return NULL;
    }
    else{
	node* temp = *head;
	while(temp->next->next!=NULL) temp=temp->next;
	node* removed = temp->next;
	temp->next = NULL;
	return removed;
    }
}

void printList(node* head){
    if(head==NULL){
	printf("the list is empty\n");
	return;
    }
    node* temp = head;
    while(temp!=NULL){
	printf("%d  ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}

/* 
    n: the number of node where the loop starts from. 
       n=1 means the loop starts at the first node.
*/
void makeCircularList(node** head, int n){
    if(*head==NULL) return;
    if( (*head)->next==NULL ) return;

    node* temp = *head;
    node* beginning_of_loop = NULL; 

    int count=1;
    while(temp->next!=NULL){
	if(count==n){
	    beginning_of_loop = temp;
	    printf("beginning of loop is at node: %d\n", beginning_of_loop->data);
	}
	temp=temp->next;
	count++;
    }

    if(beginning_of_loop==NULL || beginning_of_loop->next==NULL) return;

    temp->next = beginning_of_loop;
    printf("%d\n", temp->next->data);
}

int findStartOfCircularList(node* head){
    node* t_fast = head;
    node* t_slow = head;

    while(t_slow!=NULL){
	t_fast = t_fast->next->next;
	t_slow = t_slow->next;
	printf("t_fast: %d ",t_fast->data);
	printf("t_slow: %d\n",t_slow->data);
	if(t_slow==t_fast) break;
    }

    node* temp = head;
    while(t_fast!=temp){
	printf("t_fast: %d ",t_fast->data);
	printf("temp: %d\n",temp->data);
	temp = temp->next;
	t_fast = t_fast->next;
    }
    
    return temp->data;
}


int main(){

    node *p = (node*) malloc(sizeof(node));
    p = NULL;
    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    append(&p, 5);
    append(&p, 6);
    append(&p, 7);
    append(&p, 8);
//    append(&p, 9);
    printList(p);

    makeCircularList(&p, 3);

    printf("the loop starting node's data node is: %d\n", findStartOfCircularList(p) );

    return 1;
}
