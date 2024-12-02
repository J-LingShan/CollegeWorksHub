#include <iostream>
#include <limits>  // 为了使用 std::numeric_limits

using namespace std;

struct HTNode {
    int weight;  // 节点权重
    int parent;  // 父节点索引
    int left;    // 左子节点索引
    int right;   // 右子节点索引
};

// 选择两个最小权重的节点
void Select(HTNode* nodes, int n, int &s1, int &s2) {  // 使用引用传递
    s1 = -1;  // 初始化为-1，表示还没有找到合适的节点
    s2 = -1;
    int min1 = std::numeric_limits<int>::max();  // 使用最大整数作为初始最小值
    int min2 = std::numeric_limits<int>::max();

    for (int i = 1; i <= n; ++i) {
        if (nodes[i].parent == 0) {  // 只考虑那些没有父节点的节点
            if (nodes[i].weight < min1) {
                min2 = min1;  // 更新第二小的值
                s2 = s1;      // 更新第二小的索引
                min1 = nodes[i].weight;  // 更新最小的值
                s1 = i;     // 更新最小的索引
            } else if (nodes[i].weight < min2) {
                min2 = nodes[i].weight;  // 如果当前节点比第二小还小，则更新第二小
                s2 = i;                 // 并更新对应的索引
            }
        }
    }
}

// 创建哈夫曼树
void CreateHT(HTNode* &root, int n) {
    if (n <= 1) return;

    int allE = 2 * n - 1;  // 总共需要的节点数
    root = new HTNode[allE + 1];  // 分配内存

    for (int i = 1; i <= allE; ++i) {
        root[i].left = 0;
        root[i].right = 0;
        root[i].parent = 0;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> root[i].weight;  // 读入前n个节点的权重
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

// 先序遍历打印哈夫曼树
void PreOrderTraversal(HTNode* nodes, int index) {
    if (index == 0) return;  // 如果是空节点则返回

    cout << "Node: " << index << " Weight: " << nodes[index].weight 
         << " Parent: " << nodes[index].parent
         << " Left: " << nodes[index].left
         << " Right: " << nodes[index].right << endl;

    // 遍历左子树
    if (nodes[index].left != 0) {
        PreOrderTraversal(nodes, nodes[index].left);
    }

    // 遍历右子树
    if (nodes[index].right != 0) {
        PreOrderTraversal(nodes, nodes[index].right);
    }
}

int main() {
    int n;  // 输入节点数量
    cout << "请输入节点数量: ";
    cin >> n;

    HTNode* root = nullptr;
    CreateHT(root, n);

    // 打印哈夫曼树
    cout << "哈夫曼树结构如下：" << endl;
    PreOrderTraversal(root, 2 * n - 1);  // 从最后一个节点开始，即根节点

    delete[] root;  // 释放分配的内存
    return 0;
}

