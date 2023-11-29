#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int main(){
	Node* head;
	Node* p1;
	Node* p2;
	int i;
	
	head = NULL;

/*uncommnet one of the loop (not both) and notice the output and you will understand what LIFO and FIFO means

//LIFO
	/*for(i=0;i<10;i++){
		p1 = (Node*) malloc(sizeof(Node));
		p1->data=i;
		p1->next=head;
		head=p1;
	}*/
	
//FIFO
	for(i=0;i<10;i++){
		p1 = (Node*) malloc(sizeof(Node));
		p1->data=i;
		p1->next=NULL;
		
		if(head==NULL){
			head=p1;
			p2=p1;
		}else{
			p2->next=p1;
			p2=p1;
		}	}

	
//AFICHAGE
	p1=head;
	while(p1!=NULL){
		printf("%d\n",p1->data);
		p1=p1->next;
	}
}
