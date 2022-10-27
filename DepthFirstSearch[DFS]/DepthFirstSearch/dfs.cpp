#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];	//방문처리용
vector<int> a[8];	//총 7개의 노드가 각각 인접한 노드를 가질수 있도록 만듦

void dfs(int x) { 
	//스택을 사용하지않고 재귀함수로 사용하는 것이 더 일반적인 dfs 구현방식
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {	
		//인접한 노드를 계속해서 반복적으로 dfs를 수행한다.
		//깊이 우선 탐색이 안정적으로 이루어짐
		int y = a[x][i];
		dfs(y);
	}
}


int main(void) {
	//2와 1을 연결
	a[1].push_back(2);
	a[2].push_back(1);
	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);
	//2와 3을 연결
	a[2].push_back(3);
	a[3].push_back(2);
	//2와 4를 연결
	a[2].push_back(4);
	a[4].push_back(2);
	//2와 5를 연결
	a[2].push_back(5);
	a[5].push_back(2);
	//3과 6을 연결
	a[3].push_back(6);
	a[6].push_back(3);
	//3과 7을 연결
	a[3].push_back(7);
	a[7].push_back(3);

	dfs(1);
	
	return 0;
}