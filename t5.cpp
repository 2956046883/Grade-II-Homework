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
//基本设计思想：
	//看到这个题目最暴力的求解方法就是每添加一个节点都去遍历一遍这个链表，因为要遍历n遍，实践复杂度为O(n^2)显然不是最省时的算法
	//进一步分析问题可以知道，问题主要出在了这是一个单向链表，也就是无法回头，如果是从两个顺序的链表中依次或跳过一个取出，我们只需设置两个指针，剩下的工作就很好解决了
	//有了上述经验，我们想到可以从中间分成两段，并将后半段逆置过来，然后设置两个指针分别指向第一个节点和逆置后后半边的第一个节点
	//分别移动着两个指针，取出其中的数值然后添加到心得链表中
	Node* p = n0;
	Node* q = n0;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL)
			q = q->next;
	}//此时p指向了中间节点，而q指向了最后一个节点
	q = p->next;
	p->next = NULL;
	while (1) {
		Node* temp = q->next;
	
		q->next = p->next;
		p->next=q;
		
		q = temp;
		if (temp == NULL)
			break;//如果temp为空，也就是q到了原来的尾部，那么就会退出这个循环

	}
	//至此，后半部分完成了逆转，p之后的元素完成了倒置
	Node* frontPTR = n0->next;//指向头结点后的第一个
	Node* backPTR = p->next;//指向p后面的第一个

	Node* q1 = m0;//为新链表进行添加设置的辅助节点

	//通过尝试我们知道frontptr走的路程大于等于backptr走的路程，因此我们可以设置一个死循环，当backptr添加完毕后退出程序
	while (1) {
		//以下完成将前半部分的元素添加到新链表中
		Node* p1 = new Node;
		p1->data = frontPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
		frontPTR = frontPTR->next;
		
		//以下完成同一次循环中将后半部分的元素添加到新链表中
		p1 = new Node;
		p1->data = backPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
		backPTR = backPTR->next;

		//检查一下:如果backPTR在上一行代码中被增加，进而指向NULL时，退出循环
		if (backPTR == NULL)
			break;
	}
	//上面已经说明了，front走过的路程只会比back多或者相等，而front最远能走到p
	cout << frontPTR->data << endl;
	if (frontPTR == p) {
		frontPTR = frontPTR->next;
		Node*p1 = new Node;
		p1->data = frontPTR->data;
		p1->next = NULL;
		q1->next = p1;
		q1 = p1;
	}
	//打印一下试试
	Node* pp = m0;
	pp = pp->next;
	while (pp != NULL) {
		
		cout << pp->data << "  ";
		pp = pp->next;

	}


	
}
//说明时间复杂度：在该程序的中没有出现循环嵌套，但是在寻找中心节点以及翻转后半链表的过程中需要遍历链表操作
//因此算法的时间复杂度的O(n)
