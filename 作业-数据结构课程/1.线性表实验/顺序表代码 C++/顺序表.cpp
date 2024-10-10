#include <iostream>
#include <vector>

#define TYPE int 
#define SIZE 100

struct line{
	int data[SIZE];
	int len;
};

bool create(line** list ,int* arr, int len) {
	
	for (int i=0; i<len; i++) {
		(*list) -> data[i] = *(arr+i);
		
	}
	
	(*list) -> len = len;
	
	return true;
}

void print(line* list) {
	int count = list -> len;
	std::cout << "data：";
	for (int i=0; i<count; i++) {
		std::cout << (*list).data[i] << " ";
	}
	std::cout << std::endl;
}

void isEmpty(line* list) {
	if (list -> len != 0) std::cout << "data存在数据";
	else std::cout << "data是空的";
}

void pstFind(line * list,int pst) {
	
	if (pst > list -> len || pst < 1) {
		std::cout << "该位置不存在元素" << std::endl;;
		return;
	}
	std::cout << list -> data[pst-1] << std::endl ;
	
}

void elemFind(line* list, int num) {
	std::vector<int> arr;
	
	for(int i=0; i<list -> len; i++) {
		if(list -> data[i] == num) {
			arr.push_back(i+1);
		}
	}
	std::cout << "元素：" << num << "，的下标位置：";
	for(int i=0;i<arr.size();i++) {
		std::cout << arr[i] << " ";
	}
	
	std::cout << std::endl;
		
}

void insert(line** list, int data, int pst) {
	int len = (*list) -> len;
	
	if (len+1 > SIZE) std::cout << "数据存储已满" << std::endl;
	
	for(int i=len-1+1;i>pst-1;i--) {
		(*list) -> data[i] = (*list) -> data[i-1];
	}
	(*list) -> data[pst-1] = data;
	(*list) -> len++;
	
	std::cout << "数据插入成功" << std::endl;
	
}

void delPst(line** list, int pst) {
	int len = (*list) -> len;
	
	if(pst > len || pst < 1) {
		std::cout << "删除失败" << std::endl;
		return;
	}
	
	for(int i=pst-1;i<len-1;i++) {
		(*list) -> data[i] = (*list) -> data[i+1];
	}
	(*list) -> len--;
}
 

int main() {
	
	line* list = new line;
	int arr[5] = {1, 9, 3, 4, 5};
	
	create(&list, arr, 5);
	
	print(list);
	
	pstFind(list, 6);
	
	elemFind(list, 1);
	
	insert(&list, 10,5);
	
	print(list);
	
	delPst(&list, 5);
	
	print(list);
	
	delete list; 
	
	return 0;
}
