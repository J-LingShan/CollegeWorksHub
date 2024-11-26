#include <iostream>
#define N 10

using namespace std;

int A[N] = {0};

int front = -1;
int rear = -1;

bool isEmpty() {
	if (front == -1 && rear == -1) {
//		cout << "队列为空" << endl;
		return true;
	}
	
	else {
//		cout << "队列未满" << endl;
		return false;
	}
}

void enQueue(int x) {
	if ((rear+1) % N == front) {
		cout << "error:对列已满，入队失败" << endl;
		return;
	}
	
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	
	else {
		rear = (rear+1) % N;
	}
	A[rear] = x;
}

void deQueue() {
	if (isEmpty()) {
		return ;
	}
	
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	
	else  {
		front = (front + 1) % N;
	}
	
}

void print() {
	if (isEmpty()) return;
	
	int temp = front;
	
	while (true) {
		
		cout << A[temp] << " ";
		
		if (temp == rear) {
			break;
		}
		
		temp = (temp+1) % N;
	}
	cout << endl;

}
	
	






int main() {
    deQueue();
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	enQueue(6);
	enQueue(7);
	enQueue(8);
	enQueue(9);
	enQueue(10);
	enQueue(8);
	print();
	deQueue();
	print();
	enQueue(8);
	print();
	deQueue();
	enQueue(100);print();enQueue(100);print();
	return 0;
} 
