#include <iostream>
#include <queue>

#define MINVALUE -100
#define MAXVALUE 100

using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int data) {
	BstNode* temp = new BstNode;
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	
	return temp;
}

void Insert(BstNode** bstNode, int data) {
	if (*bstNode == NULL) {
		*bstNode = getNewNode(data);
	}
	else if(data <= (*bstNode) -> data) {
		Insert(&(*bstNode) -> left, data);
	}
	else {
		Insert(&(*bstNode) -> right, data);
	}
	
}

bool Search(BstNode* root, int data) {
	if (root == NULL) return false;
	else if (root -> data == data) return true;
	else if (data <= root -> data) {
		return Search(root -> left, data);
	}
	else return Search(root -> right ,data);
}

int FindMin(BstNode* root) {
	BstNode* temp = root;
	if (temp == NULL) {
		cout << "空树";
	}
	while (temp -> left != NULL) {
		temp = temp -> left;
	}
	return temp -> data;
} 

int FindMin2(BstNode* root) {
	BstNode* temp = root;
	if (temp == NULL) {
		cout << "空树";
	}
	else if (temp -> left == NULL) {
		return temp -> data;
	}
	
	return FindMin2(temp -> left); 
} 

BstNode* FindMinBST(BstNode* root) {
	BstNode* temp = root;
	if (temp == NULL) {
		cout << "空树";
	}
	else if (temp -> left == NULL) {
		return temp;
	}
	
	return FindMinBST(temp -> left); 
}

int MAX(int a, int b) {
	if (a <= b) return b;
	else return a;
}

int FindHeight(BstNode* root) {
	if (root == NULL) return -1;
	
	return MAX(FindHeight(root -> left), FindHeight(root -> right)) + 1;
	
}

void LevelOrder(BstNode* root) {
	if (root == NULL) return;
	queue<BstNode* > Q;
	Q.push(root);
	
	while(!Q.empty()) {
		BstNode* current = Q.front();
		cout << current -> data << " ";
		if (current -> left != NULL) Q.push(current -> left);
		if (current -> right != NULL) Q.push(current -> right);
		Q.pop();
	}
}

void Preorder(BstNode* root) {
	if (root == NULL) return;
	
	cout << root -> data << " ";
	Preorder(root -> left);
	Preorder(root -> right);
} 

void Inorder(BstNode* root) {
	if (root == NULL) return;
	
	Inorder(root -> left);
	cout << root -> data << " ";
	Inorder(root -> right);
} 

void Posorder(BstNode* root) {
	if (root == NULL) return;
	
	
	Posorder(root -> left);
	Posorder(root -> right);
	cout << root -> data << " ";
}

bool IsBstUtil(BstNode* root, int minValue, int maxValue) {
	if (root == NULL) return true;
	
	if (root -> data < maxValue && root -> data > minValue
		&& IsBstUtil(root -> left, minValue, root -> data)
		&& IsBstUtil(root -> right, root -> data, maxValue)
	) {
			return true;
	}
	
	else return false;
} 

bool IsBinarySearchTree(BstNode* root) {
	return IsBstUtil(root, MINVALUE, MAXVALUE);
}

BstNode* Delete(BstNode* root, int data) {
	if (root == NULL) return root;
	else if (data < root -> data) root -> left = Delete(root -> left, data);
	else if (data > root -> data) root -> right = Delete(root -> right, data);
	
	else {
//		case 1:无子节点 
	
		if (root -> left == NULL && root -> right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
//		case 2:有一个子节点，右节点 
		else if (root -> left == NULL) {
			BstNode* temp = root;
			root = root -> right;
			delete temp;
			
		}
		
//		case 2:有一个子节点，左节点 
		else if (root -> right == NULL) {
			BstNode* temp = root;
			root = root -> left;
			delete temp;
			
		}

//		case 3:有两个子节点 

		else {
			BstNode* temp = FindMinBST(root -> right);
			root -> data = temp -> data;
			root -> right = Delete(root -> right, temp -> data);
		}
		
	}
	return root;
}

BstNode* Find(BstNode* root, int data) {
	if (root == NULL) return false;
	else if (root -> data == data) return root;
	else if (data <= root -> data) {
		return Find(root -> left, data);
	}
	else return Find(root -> right ,data);
}

BstNode* Getsuccessor(BstNode* root, int data) {
	BstNode* current = Find(root, data);
	if (current == NULL) return NULL;
	
	if (current -> right != NULL) {
		return FindMinBST(current -> right);
	}
	
	else {
		BstNode* successor = NULL;
		BstNode* ancestor = root;
		
		while(ancestor != current) {
			if (current -> data < ancestor -> data) {
				successor = ancestor;
				ancestor = ancestor -> left;
			}
			
			else {
				ancestor = ancestor -> right;
			}
		}
		return successor;
	}
}

int main() {
	BstNode* node = NULL;
	Insert(&node, 15);
	Insert(&node, 16);
	Insert(&node, 9);
	Insert(&node, 4);
	Insert(&node, 3);
	Insert(&node, 20);
	if (Search(node, 20)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	
	cout << FindMin2(node) << endl;
	
	cout << FindHeight(node) << endl;
	
	LevelOrder(node);
	
	cout << endl;
	
	cout << "前序遍历" << endl;
	Preorder(node); 
	
	cout << endl;
	
	cout << "中序遍历" << endl;
	Inorder(node); 
	
	cout << endl;
	
	cout << "后序遍历" << endl;
	Posorder(node); 
	
	cout << endl;
	
	cout << "判断是否是二叉搜索树" << endl;
	
	if (IsBinarySearchTree(node)) {
		cout << "是二叉搜索树";
	}
	else {
		cout << "不是二叉搜索树";
	}
	
	cout << endl;
	
	cout << "删掉值：16" << endl;
	
	node = Delete(node, 16);
	
	cout << "后序遍历" << endl;
	Posorder(node); 
	
	cout << endl;
	
	cout << "中序遍历" << endl;
	Inorder(node); 
	
	cout << endl <<"中序后继" << endl;
	
	cout << Getsuccessor(node, 15) -> data << endl; //20是因为，前面删掉了16 
	
	

	return 0;
}
