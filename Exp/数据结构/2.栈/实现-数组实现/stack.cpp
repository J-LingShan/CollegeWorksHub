#include <iostream> 
#define SIZE 101

using namespace std;

int top = -1;
int arr[SIZE] = {0};

bool push(int x) {
	if(top == SIZE-1) {
		cout << "ջ��" << endl;
		return false;
	}
	arr[++top] = x;
	return true;
}

bool pop() {
	
	if(top== -1) {
		cout << "pop�쳣:��ջ" << endl;
		return false;
	}
	
	top--;
	return true;
}

bool isEmpty() {
	if (top == -1) {
		cout << "��ջ" << endl;
		return true;
	}
	cout << "�ǿ�ջ" << endl;
	return false;
}

void Top() {
	if (top == -1) return;
	cout << "ջ����" << arr[top] << " ";
}

void print() {
	
	if (top==-1) {
		cout << "����쳣:��ջ" << endl;
		return;
	}
	
	cout << "ջ��";
	
	for (int i=top; i>0; i--) {
		cout << arr[i] << " ";
	}
	cout << endl;
}



int main() {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	print();
	
	pop();
	print();
	isEmpty();
	
	Top();

	
	
	
	return 0;
}
