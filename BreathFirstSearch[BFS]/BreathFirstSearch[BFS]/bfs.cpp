#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];			//checked�� ���� - �湮�� �ߴ�.
vector<int> a[8];	//1���� 7���� �ε��� ó���ϱ����� 8�� ����

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
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

	for (int i = 1; i <= 7; i++) {
		printf("%d : ", i);
		for (int j = 0; j < a[i].size(); j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	//bfs(1);

	return 0;
}