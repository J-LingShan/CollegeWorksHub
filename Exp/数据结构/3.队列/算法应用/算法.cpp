// ����n����վ��һ�ţ�
// �������ҵı�ŷֱ�Ϊ1��n��
// ���ڴ������ұ�����1��2��1��2��������������1�����˳��У�
// ������2��������վ����������Ҷˡ�
// �������̷������У�ֱ��n���˶�����Ϊֹ��Ҫ��������ǵĳ���˳��
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int > vec;

void func(int n) {
    deque<int> queue;
    

    for (int i = 1; i<=n; i++) {
        queue.push_back(i);
    }

    while(!queue.empty()) {
        vec.push_back(queue.front());
        queue.pop_front();

        if(!queue.empty()) {
            queue.push_back(queue.front());
            queue.pop_front;
        }
    }

    for (int i = 0;i<vec.size();i++) {
        cout << vec[i] << " ";
    }

    cout << endl;

}

int main() {
    func(5);



    return 0;
}