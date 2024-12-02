#include <iostream>
#include <limits>  // Ϊ��ʹ�� std::numeric_limits

using namespace std;

struct HTNode {
    int weight;  // �ڵ�Ȩ��
    int parent;  // ���ڵ�����
    int left;    // ���ӽڵ�����
    int right;   // ���ӽڵ�����
};

// ѡ��������СȨ�صĽڵ�
void Select(HTNode* nodes, int n, int &s1, int &s2) {  // ʹ�����ô���
    s1 = -1;  // ��ʼ��Ϊ-1����ʾ��û���ҵ����ʵĽڵ�
    s2 = -1;
    int min1 = std::numeric_limits<int>::max();  // ʹ�����������Ϊ��ʼ��Сֵ
    int min2 = std::numeric_limits<int>::max();

    for (int i = 1; i <= n; ++i) {
        if (nodes[i].parent == 0) {  // ֻ������Щû�и��ڵ�Ľڵ�
            if (nodes[i].weight < min1) {
                min2 = min1;  // ���µڶ�С��ֵ
                s2 = s1;      // ���µڶ�С������
                min1 = nodes[i].weight;  // ������С��ֵ
                s1 = i;     // ������С������
            } else if (nodes[i].weight < min2) {
                min2 = nodes[i].weight;  // �����ǰ�ڵ�ȵڶ�С��С������µڶ�С
                s2 = i;                 // �����¶�Ӧ������
            }
        }
    }
}

// ������������
void CreateHT(HTNode* &root, int n) {
    if (n <= 1) return;

    int allE = 2 * n - 1;  // �ܹ���Ҫ�Ľڵ���
    root = new HTNode[allE + 1];  // �����ڴ�

    for (int i = 1; i <= allE; ++i) {
        root[i].left = 0;
        root[i].right = 0;
        root[i].parent = 0;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> root[i].weight;  // ����ǰn���ڵ��Ȩ��
    }

    for (int i = n + 1; i <= allE; ++i) {
        int s1, s2;
        Select(root, i-1, s1, s2);

        root[s1].parent = i;
        root[s2].parent = i;

        root[i].left = s1;
        root[i].right = s2;

        root[i].weight = root[s1].weight + root[s2].weight;
    }
}

// ���������ӡ��������
void PreOrderTraversal(HTNode* nodes, int index) {
    if (index == 0) return;  // ����ǿսڵ��򷵻�

    cout << "Node: " << index << " Weight: " << nodes[index].weight 
         << " Parent: " << nodes[index].parent
         << " Left: " << nodes[index].left
         << " Right: " << nodes[index].right << endl;

    // ����������
    if (nodes[index].left != 0) {
        PreOrderTraversal(nodes, nodes[index].left);
    }

    // ����������
    if (nodes[index].right != 0) {
        PreOrderTraversal(nodes, nodes[index].right);
    }
}

int main() {
    int n;  // ����ڵ�����
    cout << "������ڵ�����: ";
    cin >> n;

    HTNode* root = nullptr;
    CreateHT(root, n);

    // ��ӡ��������
    cout << "���������ṹ���£�" << endl;
    PreOrderTraversal(root, 2 * n - 1);  // �����һ���ڵ㿪ʼ�������ڵ�

    delete[] root;  // �ͷŷ�����ڴ�
    return 0;
}

