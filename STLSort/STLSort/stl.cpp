#include <iostream>
#include <algorithm>
// algorithm ��� ���Ͼȿ��� sort �Լ��� ���ǵǾ� �ִ�.

using namespace std;

int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10);
	// ó���� ����Ű�� �޸� �ּҿ�, 
	// �� �������� ����Ű�� �޸� �ּҸ� �Ű������� ������ �ȴ�.
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}