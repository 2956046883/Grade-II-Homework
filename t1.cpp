#include<iostream>
using namespace std;
#include<vector>
int main() {
	vector <int>L;
	L = { 1,2,3,4,5,6,7,8,9,10 };

	//---------------------------------算法部分------------------------------
	int len = L.size();
	int times = len / 2;
	int temp = 0;
	int counter1 = 0;
	int counter2 = len - 1;
	for (int i = 0; i < times; i++) {
		temp = L[counter1];//适应循环一定会影响时间复杂度，但不一定影响空间复杂度，如果不是再循环内每一次都创建不一样的变量则不会影响空间复杂度
		L[counter1] = L[counter2];
		L[counter2] = temp;
		counter1++;
		counter2--;

	}
	//------------------------------------------------------------------------


	//以下验证一下逆置后的结果
	for (int i = 0; i < len; i++) {
		cout << L[i] << "  ";
	}

	





}