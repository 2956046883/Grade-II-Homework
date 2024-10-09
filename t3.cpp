//题目 3：在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点不唯一，试编写算法以实现上述操作
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
	L->next = NULL;//L是指向头结点的指针
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
	//由于是伪随机数，我们知道上述生成的结果为3  3  2  2  3  2  1  1,假设我们要删除其中的2
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
//最关键的操作是删除时的指针操作，因为题目要求释放空间，因此我们要将ptr->next用temp变量暂存起来，然后将ptr->next（原本指向当前位置下一个的指针）
//指向再下一个，也就是跳过中间要被删掉的，然后只需要delete temp即可，这里我们要注意，之前new的指针再被delete后会释放该指针指向空间的内存，
//但是该指针在堆区中开辟的空间不会被释放，由此，我们还可以把这个指针指向其他的地方。