#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];	//�湮ó����
vector<int> a[8];	//�� 7���� ��尡 ���� ������ ��带 ������ �ֵ��� ����

void dfs(int x) { 
	//������ ��������ʰ� ����Լ��� ����ϴ� ���� �� �Ϲ����� dfs �������
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {	
		//������ ��带 ����ؼ� �ݺ������� dfs�� �����Ѵ�.
		//���� �켱 Ž���� ���������� �̷����
		int y = a[x][i];
		dfs(y);
	}
}


int main(void) {
	//2�� 1�� ����
	a[1].push_back(2);
	a[2].push_back(1);
	//1�� 3�� ����
	a[1].push_back(3);
	a[3].push_back(1);
	//2�� 3�� ����
	a[2].push_back(3);
	a[3].push_back(2);
	//2�� 4�� ����
	a[2].push_back(4);
	a[4].push_back(2);
	//2�� 5�� ����
	a[2].push_back(5);
	a[5].push_back(2);
	//3�� 6�� ����
	a[3].push_back(6);
	a[6].push_back(3);
	//3�� 7�� ����
	a[3].push_back(7);
	a[7].push_back(3);

	dfs(1);
	
	return 0;
}