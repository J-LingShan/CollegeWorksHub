// 设有n个人站成一排，
// 从左向右的编号分别为1～n，
// 现在从左往右报数“1，2，1，2，…”，数到“1”的人出列，
// 数到“2”的立即站到队伍的最右端。
// 报数过程反复进行，直到n个人都出列为止。要求给出他们的出列顺序。
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