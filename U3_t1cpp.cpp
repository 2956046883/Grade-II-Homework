#include<iostream>
#define STACK_SIZE 100
#define STACKINCREMENT 10
using namespace std;
struct Stack {
	int* base;
	int* top;
	int stacksize;
	Stack() {
		base = new int[STACK_SIZE];
		if (!base)
			cout << "create error" << endl;
		top = base;
		stacksize = STACK_SIZE;

	}
	
	
};
void Push(Stack& S, int a) {
	if (S.top - S.base >= S.stacksize)//超过了最大容量要再次进行分配，尝试用一下realloc
	{
		S.base = (int*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = a;
	S.top++;
}
void pop(Stack& S, int& e) {
	if (S.top == S.base)//现在为空栈
		cout << "现在是空栈";
	e = *--S.top;
}
struct queue {
	queue(int a){
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
void DeQueue(queue& Q, int &a) {
	if (Q.front == Q.rear)
		cout << "栈已空，无法再次弹出" << endl;
	else{
		a = Q.base[Q.front];
		
		Q.front++;

	}
}
bool isStackEmpty(Stack S) {
	if (S.top==S.base)
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
	queue Q1(100);
	Enqueue(Q1, 10);
	Enqueue(Q1, 9);
	Enqueue(Q1, 8);
	Enqueue(Q1, 7);
	Enqueue(Q1, 6);
	Enqueue(Q1, 5);
	Enqueue(Q1, 4);

	Stack S1;

	
	while (!isQueueEmpty(Q1)) {
		int temp;
		DeQueue(Q1,temp);
		Push(S1, temp);
		

	}
	
	while (!isStackEmpty(S1)) {
		int temp;
		pop(S1, temp);
		cout << temp << "  ";
	}
}