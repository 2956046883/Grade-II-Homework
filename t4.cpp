//��Ŀ 4���� A �� B ��������������ͷ��㣩������Ԫ�ص����������һ���㷨�� A �� B �еĹ���Ԫ�ز��������� C��Ҫ���ƻ� A��B �Ľ�㡣
#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int main(){
	Node* na0 = new Node;
	Node* na1 = new Node;
	Node* na2 = new Node;
	Node* na3 = new Node;
	Node* na4 = new Node;
	Node* na5 = new Node;
	Node* na6 = new Node;
	Node* na7 = new Node;
	Node* na8 = new Node;
	Node* na9 = new Node;
	Node* na10 = new Node;

	Node* nb0 = new Node;
	Node* nb1 = new Node;
	Node* nb2 = new Node;
	Node* nb3 = new Node;
	Node* nb4 = new Node;
	Node* nb5 = new Node;
	Node* nb6 = new Node;
	Node* nb7 = new Node;
	Node* nb8 = new Node;
	Node* nb9 = new Node;
	Node* nb10 = new Node;

	na1->data = 1;
	na2->data = 2;
	na3->data = 3;
	na4->data = 4;
	na5->data = 5;
	na6->data = 6;
	na7->data = 7;
	na8->data = 8;
	na9->data = 9;
	na10->data = 10;
	
	nb1->data = 7;
	nb2->data = 8;
	nb3->data = 9;
	nb4->data = 10;
	nb5->data = 11;
	nb6->data = 12;
	nb7->data = 13;
	nb8->data = 14;
	nb9->data = 15;
	nb10->data = 16;

	na0->next = na1;
	na1->next = na2;
	na2->next = na3;
	na3->next = na4;
	na4->next = na5;
	na5->next = na6;
	na6->next = na7;
	na7->next = na8;
	na8->next = na9;
	na9->next = na10;
	na10->next = NULL;

	nb0->next = nb1;
	nb1->next = nb2;
	nb2->next = nb3;
	nb3->next = nb4;
	nb4->next = nb5;
	nb5->next = nb6;
	nb6->next = nb7;
	nb7->next = nb8;
	nb8->next = nb9;
	nb9->next = nb10;
	nb10->next = NULL;

	
	//���������ǲ�֪����A��B�ֱ��ж��ٸ�Ԫ��
	Node* ptr=na0;
	int counter1 = 0,counter2=0;//����ͷ���
	while (ptr != NULL) {
		ptr = ptr->next;
		counter1++;
	};
	counter1--;
	ptr = nb0;
	while (ptr != NULL) {
		ptr = ptr->next;
		counter2++;
	};
	counter2--;
	cout << counter1 << " " << counter2<<endl;
	Node* nc0 = new Node;
	Node* ptr1 = na0, *ptr2 = nb0;
		
	ptr1 = ptr1->next;
	ptr2 = ptr2->next;
	Node* q = nc0;
	while (ptr1->next != NULL && ptr2->next != NULL) {
		
		if (ptr1->data == ptr2->data) {
			Node* p = new Node;
			
			p->data = ptr1->data;
			p->next = NULL;
			q->next = p;
			q=p;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;

		}
		else if (ptr1->data > ptr2->data) {
			while (1) {
				ptr2 = ptr2->next;
				if (ptr2->data >= ptr1->data)
					break;
			}

		}
		else {
			while (1) {
				ptr1 = ptr1->next;
				if (ptr1->data >= ptr2->data)
					break;
			}

		}
	}
	//�����������ͬʱ�������һ��
	/*Node* kk = nc0;
	while (kk != NULL) {
		if(kk->next!=NULL){
			kk = kk->next;
			cout << kk->data << " ";
		}
			
	}*/
	cout << endl;
	if (ptr1->next == NULL && ptr2->next == NULL) {
		if (ptr1->data == ptr2->data) {
			Node* p = new Node;
			p->data = ptr1->data;
			p->next = NULL;
			q->next = p;
			q = p;

		}
	}
	

	//���������������ptr1�ȵ������һ����ptr2û������ʱ�õ�ptr1Ȼ�����α�����ptr2���Ƿ���
	else if (ptr1->next == NULL) {
		int temp = ptr1->data;
		while (ptr2 != NULL) {
			if (ptr2->data == temp) {
				Node* p = new Node;
				p->data = temp;
				p->next = NULL;
				q->next = p;
				q = p;
				break;
			}
			ptr2 = ptr2->next;
			
		}
	}
	/*Node* kk = nc0;
	while (kk != NULL) {
		if (kk->next != NULL) {
			kk = kk->next;
			cout << kk->data << " ";
		}

	}
	cout << endl;*/
	//���������������ptr2�ȵ������һ����ptr1û������ʱ�õ�ptr2Ȼ�����α�����ptr1���Ƿ���
	else if(ptr2->next==NULL){
		int temp = ptr2->data;
		while (ptr1 != NULL) {
			if (ptr1->data == temp) {
				Node* p = new Node;
				p->data = temp;
				p->next = NULL;
				q->next = p;
				q = p;
				break;
			}
			ptr1 = ptr1->next;

		}
	}
	Node* kk = nc0;
	while (kk != NULL) {
		if (kk->next != NULL) {
			kk = kk->next;
			cout << kk->data << " ";
		}

	}
	Node* cc = nc0;
	while (cc != NULL) {
		cout << cc->next->data << "  ";
		cc = cc->next;

	}

	//if (ptr1->next == NULL && ptr2->next == NULL) {
	//	if (ptr1->next->data == ptr2->next->data) {
	//		Node* p = new Node;
	//		
	//		p = new Node;
	//		p->data = ptr1->next->data;
	//		p->next = NULL;
	//		q->next = p;
	//		q = p;
	//	}
	//}

	//else if (ptr2->next == NULL) {
	//	ptr1 = ptr1->next;
	//	if (ptr2->data < ptr1->data) {
	//		//2�����Ķ�С��1���м�����Ǿ�û�м����ı�Ҫ��
	//	}
	//	else if (ptr1->data == ptr2->data) {
	//		Node* p = new Node;
	//		
	//		p = new Node;
	//		p->data = ptr1->data;
	//		p->next = NULL;
	//		q->next = p;
	//		q = p;
	//	}
	//	else if (ptr2->data > ptr1->data) {
	//		
	//		while (ptr1!=NULL) {
	//			if(ptr1->next!=NULL){
	//				ptr1 = ptr1->next;
	//				if (ptr1->data > ptr2->data) {
	//					break;
	//				}
	//				else if (ptr1->data == ptr2->data) {
	//					Node* p = new Node;
	//					
	//					p = new Node;
	//					p->data = ptr1->data;
	//					p->next = NULL;
	//					q->next = p;
	//					q = p;
	//					break;
	//				}
	//			
	//			}
	//			
	//		}
	//	}
	//}


	////na�����һ��Ԫ��ʱ
	//else if (ptr1->next == NULL) {
	//	ptr2 = ptr2->next;
	//	if (ptr1->data < ptr2->data);
	//		
	//	else if (ptr1->data == ptr2->data) {
	//		Node* p = new Node;
	//		
	//		p->data = ptr1->data;
	//		p->next = NULL;
	//		q->next = p;
	//		q = p;
	//	}
	//	else {
	//		while (ptr2!=NULL) {
	//			if(ptr2->next!=NULL){
	//				ptr2 = ptr2->next;
	//				if (ptr1->data == ptr2->data) {
	//					Node* p = new Node;
	//					p->data = ptr1->data;
	//					p->next = NULL;
	//					q->next = p;
	//					q=p;
	//					break;
	//				}
	//				else if (ptr1->data < ptr2->data) {
	//					break;
	//				}
	//			}
	//			

	//			
	//		}
	//	}

	//}
	///*Node* pp = nc0;
	//while (pp!=NULL) {
	//	pp = pp->next;
	//	cout << pp->data << "  ";
	//}*/

	//return 0;
}