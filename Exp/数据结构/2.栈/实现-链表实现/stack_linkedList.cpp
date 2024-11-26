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

bool isEmpty(Node* head) {
	if (head == NULL) {
		cout << "¿ÕÕ»" << endl;
		return true;
	}
	cout << "·Ç¿ÕÕ»" << endl;
	return false;
}

void Top(Node* head) {
	if (head == NULL) return;
	cout << "Õ»¶¥£º" << head -> data << " ";
}

void push(Node** head, int data) {
	Node* temp = new Node;
	temp -> data = data;
	temp -> next = NULL;
	
	temp -> next = *head;
	*head = temp;
}


void pop(Node** head) {
	
	Node* temp1 = *head;
	*head = temp1 -> next;
	delete temp1;
	return;
}


int main() {
	Node* head = NULL;
	push(&head, 10);
	push(&head, 2);
	push(&head, 3);
	print(head);
	
	cout << "\npop£º\n" << endl;
	pop(&head);
	print(head);
	
	push(&head, 100);
	print(head);
	
	Top(head);
	cout << endl;
	isEmpty(head);
	
	return 0;
}


