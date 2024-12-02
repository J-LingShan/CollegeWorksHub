#include <iostream>
#include <queue>

#define MINVALUE -100
#define MAXVALUE 100

using namespace std;

struct BiThrNode {
	int data;
	BiThrNode* left;
	BiThrNode* right;
	bool leftFlag; 
	bool rightFlag;
	// leftFlag: ����� true��˵����ָ��ָ��ǰ���ڵ㣻����� false��˵����ָ��ָ����������
	// rightFlag: ����� true��˵����ָ��ָ���̽ڵ㣻����� false��˵����ָ��ָ����������

};

BiThrNode* getNewNode(int data) {
	BiThrNode* temp = new BiThrNode;
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> leftFlag = false;
	temp -> rightFlag = false;
	
	return temp;
}

void Insert(BiThrNode** BiThrNode, int data) {
	if (*BiThrNode == NULL) {
		*BiThrNode = getNewNode(data);
	}
	else if(data <= (*BiThrNode) -> data) {
		Insert(&(*BiThrNode) -> left, data);
	}
	else {
		Insert(&(*BiThrNode) -> right, data);
	}
	
}

bool Search(BiThrNode* root, int data) {
	if (root == NULL) return false;
	else if (root -> data == data) return true;
	else if (data <= root -> data) {
		return Search(root -> left, data);
	}
	else return Search(root -> right ,data);
}

int FindMin(BiThrNode* root) {
	BiThrNode* temp = root;
	if (temp == NULL) {
		cout << "����";
	}
	while (temp -> left != NULL) {
		temp = temp -> left;
	}
	return temp -> data;
} 

int FindMin2(BiThrNode* root) {
	BiThrNode* temp = root;
	if (temp == NULL) {
		cout << "����";
	}
	else if (temp -> left == NULL) {
		return temp -> data;
	}
	
	return FindMin2(temp -> left); 
} 

BiThrNode* FindMinBST(BiThrNode* root) {
	BiThrNode* temp = root;
	if (temp == NULL) {
		cout << "����";
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

int FindHeight(BiThrNode* root) {
	if (root == NULL) return -1;
	
	return MAX(FindHeight(root -> left), FindHeight(root -> right)) + 1;
	
}

void LevelOrder(BiThrNode* root) {
	if (root == NULL) return;
	queue<BiThrNode* > Q;
	Q.push(root);
	
	while(!Q.empty()) {
		BiThrNode* current = Q.front();
		cout << current -> data << " ";
		if (current -> left != NULL) Q.push(current -> left);
		if (current -> right != NULL) Q.push(current -> right);
		Q.pop();
	}
}

void Preorder(BiThrNode* root) {
	if (root == NULL) return;
	
	cout << root -> data << " ";
	Preorder(root -> left);
	Preorder(root -> right);
} 

void Inorder(BiThrNode* root) {
	if (root == NULL) return;
	
	Inorder(root -> left);
	cout << root -> data << " ";
	Inorder(root -> right);
} 

void Posorder(BiThrNode* root) {
	if (root == NULL) return;
	
	
	Posorder(root -> left);
	Posorder(root -> right);
	cout << root -> data << " ";
}

bool IsBstUtil(BiThrNode* root, int minValue, int maxValue) {
	if (root == NULL) return true;
	
	if (root -> data < maxValue && root -> data > minValue
		&& IsBstUtil(root -> left, minValue, root -> data)
		&& IsBstUtil(root -> right, root -> data, maxValue)
	) {
			return true;
	}
	
	else return false;
} 

bool IsBinarySearchTree(BiThrNode* root) {
	return IsBstUtil(root, MINVALUE, MAXVALUE);
}

BiThrNode* Delete(BiThrNode* root, int data) {
	if (root == NULL) return root;
	else if (data < root -> data) root -> left = Delete(root -> left, data);
	else if (data > root -> data) root -> right = Delete(root -> right, data);
	
	else {
//		case 1:���ӽڵ� 
	
		if (root -> left == NULL && root -> right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
//		case 2:��һ���ӽڵ㣬�ҽڵ� 
		else if (root -> left == NULL) {
			BiThrNode* temp = root;
			root = root -> right;
			delete temp;
			
		}
		
//		case 2:��һ���ӽڵ㣬��ڵ� 
		else if (root -> right == NULL) {
			BiThrNode* temp = root;
			root = root -> left;
			delete temp;
			
		}

//		case 3:�������ӽڵ� 

		else {
			BiThrNode* temp = FindMinBST(root -> right);
			root -> data = temp -> data;
			root -> right = Delete(root -> right, temp -> data);
		}
		
	}
	return root;
}

BiThrNode* Find(BiThrNode* root, int data) {
	if (root == NULL) return false;
	else if (root -> data == data) return root;
	else if (data <= root -> data) {
		return Find(root -> left, data);
	}
	else return Find(root -> right ,data);
}

BiThrNode* Getsuccessor(BiThrNode* root, int data) {
	BiThrNode* current = Find(root, data);
	if (current == NULL) return NULL;
	
	if (current -> right != NULL) {
		return FindMinBST(current -> right);
	}
	
	else {
		BiThrNode* successor = NULL;
		BiThrNode* ancestor = root;
		
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

void InThread(BiThrNode *&root, BiThrNode *&pre) {
	
	if (root == NULL) return;

	InThread(root -> left, pre);

	if (root -> left == NULL) {
		root -> left = pre;
		root -> leftFlag = true;
	}
	else {	
		root -> leftFlag = false;
	}

	if (pre != NULL && pre -> right == NULL) {
		pre -> right = root;
		pre -> rightFlag = true;
	}

	pre = root;


	InThread(root -> right, pre);

}

void InorderThreadedRecursive(BiThrNode* root) {
    if (root == NULL) return;

    BiThrNode* p = root;
    
    // �ҵ�����ڵ㣨�Ӹ��ڵ㿪ʼ��
    while (p != NULL) {
        // һֱ�����ߣ�ֱ������û���������Ľڵ�
        while (!p->leftFlag) {
            p = p->left;
        }

        // ��ӡ��ǰ�ڵ��ֵ
        cout << p->data << " ";

        // �����ǰ�ڵ�����������ֱ����ת����̽ڵ�
        while (p->rightFlag) {
            p = p->right;
            cout << p->data << " ";
        }

        // ������ת��������������ڵ�
        p = p->right;
    }
}




int main() {
	BiThrNode* node = NULL;
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
	
	cout << "ǰ�����" << endl;
	Preorder(node); 
	
	cout << endl;
	
	cout << "�������" << endl;
	Inorder(node); 
	
	cout << endl;
	
	cout << "�������" << endl;
	Posorder(node); 
	
	cout << endl;
	
	cout << "�ж��Ƿ��Ƕ���������" << endl;
	
	if (IsBinarySearchTree(node)) {
		cout << "�Ƕ���������";
	}
	else {
		cout << "���Ƕ���������";
	}
	
	cout << endl;
	
	cout << "ɾ��ֵ��16" << endl;
	
	node = Delete(node, 16);
	
	cout << "�������" << endl;
	Posorder(node); 
	
	cout << endl;
	
	cout << "�������" << endl;
	Inorder(node); 
	
	cout << endl <<"������" << endl;
	
	cout << Getsuccessor(node, 15) -> data << endl; //20����Ϊ��ǰ��ɾ����16 
	
	cout << "�������" << endl;
	Inorder(node); 
	cout << endl;
	
	BiThrNode* pre = NULL;
	
	InThread(node, pre); 

	cout << "�������������" << endl;

	InorderThreadedRecursive(node);
	
	

	return 0;
}
