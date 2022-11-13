#include <stdio.h>

//부모 노드를 찾는 함수
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
		//x라는 값이 해당 부모의 값과 동일하다면 
		//x자체를 반환할 수 있도록 만들어준다.
		//재귀함수의 종료부분
	//현재 자기자신이 가리키고있는 부모노드의 값과 자기 자신이 다르다면
	//실제 부모를 찾기 위해서
	//재귀적으로 함수를 수행한다.
	return parent[x] = getParent(parent, parent[x]);
	//3이 2를 가리키고 있을 때 다시 2가 가리키고있는 1을 찾아내는 과정이
	//getParent라는 함수라고 할 수 있다.
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
	//a와 b를 입력 받아서 각각의 부모값을 구한 뒤에
	a = getParent(parent, a);
	b = getParent(parent, b);
	//더 작은 값 쪽으로 부모를 합쳐줌
	if (a < b) parent[b] = a;
	else parent[a] = b;
	//b가 더 큰 값이라면 b의 부모가 a가 될수 있도록 설정해 준다.
	//그렇지 않다면 a가 더 큰 경우에는 a의 부모 값으로 b를 넣어줄 수 있도록 해줌
	//항상 부모를 합칠 때는 더 작은 값으로 합친다.
}

//같은 부모를 가지는지 확인하는 함수
//같은 그래프에 속해있는지 물어보는 것과 같다.
//현재 두개의 그래프가 동일한 그래프에 속해있는지
int findParent(int parent[], int a, int b) {
	//부모 값을 이용해서 확인을 함
	a = getParent(parent, a);
	b = getParent(parent, b);
	//a와 b를 비교해서 같다면 같은 부모를 가지는 구나 -> 1을 반환
	if (a == b) return 1;
	else return 0;
	//그렇지 않다면 0을 반환해서 서로 다른 부모 다른 그래프에 속해있다는 것을 알려줌
}

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
		//기본적으로 자기 자신을 부모로 가리키도록 만들어 주기
	}
	//몇 개의 원소를 합쳐봄
	//그래프1
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	//그래프2
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	//findParent를 이용해서 1과 5가 같은 그래프에 속해있는지 확인
	//1과 5는 다른 그래프에 속해있다.
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	printf("연결된 값 [1] : %d\n", getParent(parent, 1));
	printf("연결된 값 [5] : %d\n", getParent(parent, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	printf("연결된 값 [1] : %d\n", getParent(parent, 1));
	printf("연결된 값 [5] : %d\n", getParent(parent, 5));

	return 0;
}