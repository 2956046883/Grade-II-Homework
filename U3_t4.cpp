#include<iostream>
using namespace std;
#define QueneLenth 10
struct SqQuene {
	
	int* base;
	int front;
	int rear;
	int tag;
	SqQuene() {
	//tag=1ʱδ����tag=0ʱ����
		front = 0;
		rear = 0;
		base = new int[QueneLenth];
		for (int i = 0; i < QueneLenth; i++) {
			base[i] = 0;
		}
		tag = 1;//tag=1ʱδ����tag=0ʱ����

	}

};
void TravelQuene(SqQuene a) {
	for (int i = 0; i < QueneLenth; i++) {
		cout << "[" << i << "] : " << a.base[i] << endl;
	}

}
void Enquene(SqQuene& Q, int a) {
	if (Q.tag == 1)//δ��
	{
		Q.base[Q.rear] = a;
		Q.rear =(Q.rear+1)%QueneLenth;
		/*cout << Q.front << endl;
		cout << Q.rear << endl;*/
		if (Q.front == Q.rear)
			Q.tag = 0;
	}
	else
		cout << "�����Ѿ����ˣ��޷��������" << endl;
	//���Ҫ�ټ�һ���ı�tag��if�ж�
}

void Dequene(SqQuene& Q, int& a) {
	if (Q.tag == 1 && Q.rear == Q.front) {
		cout << "�����ǿյ��޷�����" << endl;
	}
	else//���в��ǿյ�
	{
		a = Q.base[Q.front];
		Q.base[Q.front] = -0;
		Q.front = (Q.front + 1) % QueneLenth;
		Q.tag = 1;
	}
}
int main() {
	cout << (-2) % 3 << endl;
	SqQuene S1;
	Enquene(S1, 1);
	Enquene(S1, 2);
	
	Enquene(S1, 3);
	Enquene(S1, 4);
	Enquene(S1, 5);
	Enquene(S1, 6);
	Enquene(S1, 7);
	Enquene(S1, 8);
	Enquene(S1, 9);
	Enquene(S1, 10); TravelQuene(S1); cout << S1.front << " " << S1.rear <<"  " << endl;
	
	int a;
	Dequene(S1, a); TravelQuene(S1); cout << "a= " << a << endl;
	Dequene(S1, a); cout << S1.front << " " << S1.rear << "  " << endl;
	Dequene(S1, a); cout << S1.front << " " << S1.rear << "  " << endl;
	Dequene(S1, a); cout << S1.front << " " << S1.rear << "  " << endl;
	Dequene(S1, a); cout << S1.front << " " << S1.rear << "  " << endl;
	Dequene(S1, a);
	Dequene(S1, a); TravelQuene(S1); cout << "a= " << a << endl;
}