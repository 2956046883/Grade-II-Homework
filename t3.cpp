//��Ŀ 3���ڴ�ͷ���ĵ����� L �У�ɾ������ֵΪ x �Ľ�㣬���ͷ���ռ䣬����ֵΪ x �Ľ�㲻Ψһ���Ա�д�㷨��ʵ����������
#include<iostream>
using namespace std;
int main() {
	struct Node {
		int data;
		Node* next;
	};

	int n = 8;
	typedef Node* LinkList;
	LinkList p = NULL, q = NULL;
	LinkList L = new Node;
	L->next = NULL;//L��ָ��ͷ����ָ��
	q = L;

	for (int i = 0; i < n; i++) {
		p = new Node;
		p->data = rand()%3+1 ;//1-3
		p->next = NULL;
		q->next = p;
		q = p;
	}

	Node* ptr = L;
	for (int i = 0; i < n; i++) {
		
		
			ptr = ptr->next;
			cout << ptr->data << "  ";

		
	}
	cout << endl;
	//������α�����������֪���������ɵĽ��Ϊ3  3  2  2  3  2  1  1,��������Ҫɾ�����е�2
	int flag = 2;
	ptr = L;
	while(!ptr==NULL) {
		if (ptr->next == NULL)
			break;
		if (ptr->next->data == flag) {
			LinkList temp;
			temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
			
		}
		else {
			ptr = ptr->next;
		}
	}

	ptr = L;
	while (!ptr == NULL) {
		ptr = ptr->next;
		if(ptr!=NULL)
		cout << ptr->data << "  ";
	}
}
//��ؼ��Ĳ�����ɾ��ʱ��ָ���������Ϊ��ĿҪ���ͷſռ䣬�������Ҫ��ptr->next��temp�����ݴ�������Ȼ��ptr->next��ԭ��ָ��ǰλ����һ����ָ�룩
//ָ������һ����Ҳ���������м�Ҫ��ɾ���ģ�Ȼ��ֻ��Ҫdelete temp���ɣ���������Ҫע�⣬֮ǰnew��ָ���ٱ�delete����ͷŸ�ָ��ָ��ռ���ڴ棬
//���Ǹ�ָ���ڶ����п��ٵĿռ䲻�ᱻ�ͷţ��ɴˣ����ǻ����԰����ָ��ָ�������ĵط���