#include<iostream>
using namespace std;
#include<vector>
int main() {
	vector <int>L;
	L = { 1,2,3,4,5,6,7,8,9,10 };

	//---------------------------------�㷨����------------------------------
	int len = L.size();
	int times = len / 2;
	int temp = 0;
	int counter1 = 0;
	int counter2 = len - 1;
	for (int i = 0; i < times; i++) {
		temp = L[counter1];//��Ӧѭ��һ����Ӱ��ʱ�临�Ӷȣ�����һ��Ӱ��ռ临�Ӷȣ����������ѭ����ÿһ�ζ�������һ���ı����򲻻�Ӱ��ռ临�Ӷ�
		L[counter1] = L[counter2];
		L[counter2] = temp;
		counter1++;
		counter2--;

	}
	//------------------------------------------------------------------------


	//������֤һ�����ú�Ľ��
	for (int i = 0; i < len; i++) {
		cout << L[i] << "  ";
	}

	





}