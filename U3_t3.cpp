#include<iostream>
#include<string>
#define STACK_SIZE 100
#define STACKINCREMENT 10
using namespace std;
struct Stack {
	char* base;
	char* top;
	int stacksize;
	Stack() {
		base = new char[STACK_SIZE];
		if (!base)
			cout << "create error" << endl;
		top = base;
		stacksize = STACK_SIZE;

	}


};
void Push(Stack& S, char a) {
	if (S.top - S.base >= S.stacksize)//超过了最大容量要再次进行分配，尝试用一下realloc
	{
		S.base = (char*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = a;
	S.top++;
}
void pop(Stack& S, char& e) {
	if (S.top == S.base)//现在为空栈
		cout << "现在是空栈";
	e = *--S.top;
}
struct queue {
	queue(int a) {
		base = new int[a];//a是大小
		front = 0;
		rear = 0;
		size = a;
	}
	int* base;
	int front;
	int rear;
	int size;
};
void Enqueue(queue& Q, int a) {
	if (Q.rear == Q.size - 1)
		cout << "队列超出开辟的范围" << endl;
	else {

		Q.base[Q.rear] = a;
		Q.rear++;
	}


}
void DeQueue(queue& Q, int& a) {
	if (Q.front == Q.rear)
		cout << "栈已空，无法再次弹出" << endl;
	else {
		a = Q.base[Q.front];

		Q.front++;

	}
}
bool isStackEmpty(Stack S) {
	if (S.top == S.base)
		return true;
	else
		return false;
}
bool isQueueEmpty(queue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

int main() {
	//先对列表进行初始化
	string str = "lklklmzlklkl";
	//cout << str[0];
	//这里给我们的启示是string类型也可以用序列检索，如上面的string字符串，str[0]='s',str[1]='y'
	int length = str.length();
	int times = length / 2;  //这里的times指的是需要压入栈的最多次数
	Stack S1;
	for (int i = 0; i < times; i++) {
		char temp = str[i];
		Push(S1, temp);
		cout << temp << endl ;


		
	}
	cout << endl;
	//如果为偶数，从索引为times开始核查，一直核查到length-1个
	//如果为奇数，从索引为times+1开始核查，一直核查到length-1个
	int midterm_index = 0;
	if (length % 2 == 0)
		midterm_index = times;
	else
		midterm_index = times + 1;

	int FLAG = 1;
	cout << midterm_index << endl;
	for (int i = midterm_index; i <= length - 1; i++) {
		char temp;
		pop(S1, temp);
		cout << "pop:" << temp ;
		cout << "  str[i]" << str[i] << endl;
		if (str[i] != temp) {
			FLAG = 0;
			break;
		}

	}
	if (FLAG == 1)
		cout << "是对称的" << endl;
	else
		cout << "不是对称的" << endl;

}