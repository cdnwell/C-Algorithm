// sort �Լ��� ������ ���� : �츮�� ������ ������ �츮 ������� ������ �� �־.
#include <iostream>
#include <algorithm>
// algorithm ��� ���Ͼȿ��� sort �Լ��� ���ǵǾ� �ִ�.

using namespace std;

bool compare(int a, int b) {
	return a < b;	// a�� b���� ���� ��, true ���� ��ȯ �ȴ�.
	// �⺻������ sort�Լ��� ���� ���� ������ ���������� �����ϰ� �־���.
	// compare �Լ��� ���ֵ� ������ ����� ���´�.

	// ���� ������
	// return a > b;
	// �� �ϸ� ������������ ������ ����ȴ�.
;}

int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	// ó���� ����Ű�� �޸� �ּҿ�, 
	// �� �������� ����Ű�� �޸� �ּҸ� �Ű������� ������ �ȴ�.
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}