
// 대표적인 비선형 자료구조 : 그래프, 이진 트리
// 데이터의 탐색 속도 증진을 위해 사용하는 구조
// 힙 정렬(Heap Sort)를 구현 할 때 포인터를 사용하지 않아도 되었지만 이진 트리에서는 포인터를 사용해야 함.
// 
// 이진 트리가 왜 더 빠른 탐색을 가능하게 해주는 지 -> 트리가 많이 구성되었을 때 특정 데이터를 찾고자 하면
// 제일 위에서 왼쪽 -> 왼쪽 ... 두 번 만에 찾음. 한 번 내려 갈 때마다 1/2 씩 데이터량이 줄어듦 log2N
// 트리 구조는 불규칙하게 구현 되있을 수 있음. heap 정렬 일 때는 완전 이진 트리, 이진 트리는 배열로 표현하기 힘듦
//
// 계속 오른쪽으로만 가는 경우 완전 이진트리 -> 문제가 생긴다.
// 데이터의 낭비를 줄이기 위해 포인터 사용, 노드의 개수 4개 -> 포인터 4개, 배열은 14개까지도 ...
// 
// 자료 구조를 포인터로 만든 이후 데이터 탐색 방법 3가지
// 1. 전위 순회
//  자기 자신을 처리하고 - 왼쪽 - 오른쪽 처리
// 2. 중위 순회
//  왼쪽 처리 - 자기 처리 - 오른쪽 처리
// 3. 후위 순회
//  왼쪽 - 오른쪽 - 자기 자신 처리
//  후위 순회가 자주 사용 됨 수식 -> 컴퓨터가 계산하기 좋은 방식으로 바꿀 때 후위 순회가 많이 사용 된다.
// 전위 순회, 중위 순회, 후위 순회 확실히 이해하고 가기

#include <iostream>

using namespace std;

int number = 15;	// 노드의 개수 15개 (1부터 15까지 들어가게 이진트리 만듦)

// 구조체 사용, 클래스와 상당히 흡사함. 구조체에서 함수를 추가한 것이 클래스
// 구조체가 클래스보다 더 하위 계층의 문법이라고 할 수 있다.

// 하나의 노드 정보를 선언함.
typedef struct node* treePointer;	// node라는 구조체를 treePointer라는 이름으로 포인터 형식으로 사용하겠다.
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;	// node라는 이름으로 사용 할 수 있도록 만듦

// 전위 순회 구현
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회 구현
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회 구현
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[16];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;	// 데이터는 1부터 15까지 자기 자신이 들어갈 수 잇도록 만듦.
		nodes[i].leftChild = NULL;	// 왼쪽 자식 NULL
		nodes[i].rightChild = NULL;	// 오른쪽 자식 NULL
	}
	for (int i = 1; i <= number; i++) {	// 연결
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];	//2는 부모에서 왼쪽 노드로.. 홀수
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];	//3은 부모에서 오른쪽으로.. 짝수
		}
	}

	//preorder(&nodes[1]);
	//inorder(&nodes[1]);
	postorder(&nodes[1]);

	return 0;
}