#include <iostream>
#include <stack>
#include <string> 
using namespace std;

// ʱ�临�Ӷȴ� 

int main() {
	
	stack<char> strStack;
	string str = "aa";
	
	for (int i = 0; i < str.length(); i++) {
		strStack.push(str[i]);
	}
	
	int flag = 1; 
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != strStack.top()) {
			flag = 0;
		}
		strStack.pop();
	}
	
	if (flag) cout << "���ַ���Ϊ�Գƴ�";
	else cout << "���ַ������ǶԳƴ�";
	
	
	return 0;
}




