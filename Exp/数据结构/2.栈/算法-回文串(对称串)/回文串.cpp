#include <iostream>
#include <stack>
#include <string> 
using namespace std;

// 时间复杂度大 

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
	
	if (flag) cout << "该字符串为对称串";
	else cout << "该字符串不是对称串";
	
	
	return 0;
}




