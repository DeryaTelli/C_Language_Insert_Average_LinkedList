#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;



Node* insertLast(Node* head, int value){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL){
    	head=temp;
	}
	else{
		Node* last=head;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
	}
	return head;
}


Node* insertFront(Node* head, int value) {
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=value;
	temp ->next=head;
	head=temp;
	return head;
  
}

double calculateAverage(Node* head) {
    if (head == NULL) {
        return 0.0;
    }

    int sum = 0;
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }

    return (double)sum / count;
}


Node* insertAverageLast(Node* head) {
    double avg = calculateAverage(head);
    head = insertLast(head, (int)avg);
    return head;
}
Node* insertAverage(Node* head) {
    double avg = calculateAverage(head);
    head = insertFront(head, (int)avg);
    return head;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}



Node* delete(Node* head, int key) {
   if(head ==NULL){
   	return head;
   }else{
   	Node* temp=head;
   	if(head ->data==key){
   		head=head->next;
   		free(temp);
	   }else{
	   	while(temp->next!=NULL && temp->next->data!=key){
	   		temp = temp->next;
	   		if(temp->next==NULL){
	   			return head;
			   }
		
		     
            }
		   Node* delete=temp->next;  
		   temp->next=delete ->next;
		   free(delete);   
	   }
	   return head;
   }
}


int main() {
    Node* head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);
    head = insertFront(head, 40);
    
    printf("Original list: ");
    displayList(head);
    head = insertAverage(head);
    printf("List after insert front: ");
    displayList(head);
    head = insertAverageLast(head);
    printf("List after insert last: ");
    displayList(head);
    int key;
    printf("\nEnter a key: ");
    scanf("%d", &key);
    head = delete(head, key);
    printf("List after delete value: ");
    displayList(head);
    return 0;
}

