#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;

};
int main() {
	Node* n0 = new Node;
	Node* n1 = new Node;
	Node* n2 = new Node;
	Node* n3 = new Node;
	Node* n4 = new Node;
	Node* n5 = new Node;
	Node* n6 = new Node;
	Node* n7 = new Node;
	Node* n8 = new Node;
	Node* n9 = new Node;
	Node* n10 = new Node;
	
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n8->data = 8;
	n9->data = 9;
	n10->data = 10;
	
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	n10->next = NULL;

	Node* m0 = new Node;
//�������˼�룺
	//���������Ŀ�������ⷽ������ÿ���һ���ڵ㶼ȥ����һ�����������ΪҪ����n�飬ʵ�����Ӷ�ΪO(n^2)��Ȼ������ʡʱ���㷨
	//��һ�������������֪����������Ҫ����������һ����������Ҳ�����޷���ͷ������Ǵ�����˳������������λ�����һ��ȡ��������ֻ����������ָ�룬ʣ�µĹ����ͺܺý����
	//�����������飬�����뵽���Դ��м�ֳ����Σ������������ù�����Ȼ����������ָ��ֱ�ָ���һ���ڵ�����ú���ߵĵ�һ���ڵ�
	//�ֱ��ƶ�������ָ�룬ȡ�����е���ֵȻ����ӵ��ĵ�������
	Node* p = n0;
	Node* q = n0;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL)
			q = q->next;
	}//��ʱpָ�����м�ڵ㣬��qָ�������һ���ڵ�
	q = p->next;
	p->next = NULL;
	while (1) {
		Node* temp = q->next;
	
		q->next = p->next;
		p->next=q;
		
		q = temp;
		if (temp == NULL)
			break;//���tempΪ�գ�Ҳ����q����ԭ����β������ô�ͻ��˳����ѭ��

	}
	//���ˣ���벿���������ת��p֮���Ԫ������˵���
	Node* frontPTR = n0->next;//ָ��ͷ����ĵ�һ��
	Node* backPTR = p->next;//ָ��p����ĵ�һ��

	Node* q1 = m0;//Ϊ���������������õĸ����ڵ�

	//ͨ����������֪��frontptr�ߵ�·�̴��ڵ���backptr�ߵ�·�̣�������ǿ�������һ����ѭ������backptr�����Ϻ��˳�����
	while (1) {
		//������ɽ�ǰ�벿�ֵ�Ԫ����ӵ���������
		Node* p1 = new Node;
		p1->data = frontPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
		frontPTR = frontPTR->next;
		
		//�������ͬһ��ѭ���н���벿�ֵ�Ԫ����ӵ���������
		p1 = new Node;
		p1->data = backPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
		backPTR = backPTR->next;

		//���һ��:���backPTR����һ�д����б����ӣ�����ָ��NULLʱ���˳�ѭ��
		if (backPTR == NULL)
			break;
	}
	//�����Ѿ�˵���ˣ�front�߹���·��ֻ���back�������ȣ���front��Զ���ߵ�p
	cout << frontPTR->data << endl;
	if (frontPTR == p) {
		frontPTR = frontPTR->next;
		Node*p1 = new Node;
		p1->data = frontPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
	}
	//��ӡһ������
	Node* pp = m0;
	pp = pp->next;
	while (pp != NULL) {
		
		cout << pp->data << "  ";
		pp = pp->next;

	}


	
}
//˵��ʱ�临�Ӷȣ��ڸó������û�г���ѭ��Ƕ�ף�������Ѱ�����Ľڵ��Լ���ת�������Ĺ�������Ҫ�����������
//����㷨��ʱ�临�Ӷȵ�O(n)
