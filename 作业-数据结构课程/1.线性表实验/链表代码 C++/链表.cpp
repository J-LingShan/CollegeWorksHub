#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void print(Node* head) {
	Node* temp = head;
	while(temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;

}

void insert_bg(Node** head, int data) {
	Node* temp = new Node;
	temp -> data = data;
	temp -> next = NULL;
	
	temp -> next = *head;
	*head = temp;
}

void insert_aw(Node** head, int data, int pst) {
	Node* temp = new Node;
	temp -> data = data;
	temp -> next = NULL;
	
	Node* temp2 = *head;
	
	if (pst == 1) {
		temp -> next = *head;
		*head = temp;
		return;
	}
	
	for (int i=0; i<pst-1-1; i++) {
		temp2 = temp2 -> next;
	}
	
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
}

void del_pst(Node** head, int pst) {
	
	Node* temp1 = *head;
	
	if (pst==1) {
		*head = temp1 -> next;
		delete temp1;
		return;
	}
	
	for(int i=0;i<pst-1-1;i++) {
		temp1 = temp1 -> next;
	}
	
	Node* temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next;
	delete temp2;
	
}


int main() {
	Node* head = NULL;
	insert_bg(&head, 10);
	insert_bg(&head, 30);
	insert_bg(&head, 20);
	print(head);
	
	insert_aw(&head, 100, 3);
	print(head);
	insert_aw(&head, 200, 1);
	print(head);
	
	del_pst(&head, 3);
	print(head);
	
	del_pst(&head, 1);
	print(head);
	
	




	return 0;
}


