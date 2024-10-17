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
	if (S.top - S.base >= S.stacksize)//�������������Ҫ�ٴν��з��䣬������һ��realloc
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
	if (S.top == S.base)//����Ϊ��ջ
		cout << "�����ǿ�ջ";
	e = *--S.top;
}
struct queue {
	queue(int a) {
		base = new int[a];//a�Ǵ�С
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
		cout << "���г������ٵķ�Χ" << endl;
	else {

		Q.base[Q.rear] = a;
		Q.rear++;
	}


}
void DeQueue(queue& Q, int& a) {
	if (Q.front == Q.rear)
		cout << "ջ�ѿգ��޷��ٴε���" << endl;
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
	//�ȶ��б���г�ʼ��
	string str = "lklklmzlklkl";
	//cout << str[0];
	//��������ǵ���ʾ��string����Ҳ���������м������������string�ַ�����str[0]='s',str[1]='y'
	int length = str.length();
	int times = length / 2;  //�����timesָ������Ҫѹ��ջ��������
	Stack S1;
	for (int i = 0; i < times; i++) {
		char temp = str[i];
		Push(S1, temp);
		cout << temp << endl ;


		
	}
	cout << endl;
	//���Ϊż����������Ϊtimes��ʼ�˲飬һֱ�˲鵽length-1��
	//���Ϊ������������Ϊtimes+1��ʼ�˲飬һֱ�˲鵽length-1��
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
		cout << "�ǶԳƵ�" << endl;
	else
		cout << "���ǶԳƵ�" << endl;

}