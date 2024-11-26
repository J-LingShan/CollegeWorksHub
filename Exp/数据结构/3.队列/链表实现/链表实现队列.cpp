#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

int rear = -1;

bool isEmpty(Node* front) {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void enQueue(Node** head, int data) {
	Node* temp = new Node;
	temp -> data = data;
	temp -> next = NULL;
	
	Node* temp2 = *head;
	
	if (isEmpty(* head)) {
		rear = 1;
	}
	
	if (rear == 1) {
		temp -> next = *head;
		*head = temp;
		rear++;
		return;
	}
	
	for (int i=0; i<rear-1-1; i++) {
		temp2 = temp2 -> next;
	}
	
	temp -> next = temp2 -> next;
	temp2 -> next = temp;
	rear++;
}

void deQueue(Node** front) {
	
	if (isEmpty(*front)) {
		cout << "对列是空的" << endl;
		return;
	}
	
	Node* temp1 = *front;
	
	*front = temp1 -> next;
	delete temp1;
	
	
}

void Print(Node* front) {
	
	while(front != NULL) {
		cout << front -> data << "\t";
		front = front -> next;
	}
	cout << endl;
	
}

int main() {
	Node* front = NULL;
	
	enQueue(&front, 2);
	Print(front);
	enQueue(&front, 1);
	Print(front);
	enQueue(&front, 3);
	
	Print(front);
	
	deQueue(&front);
	
	Print(front);
	
	
	return 0;
}
