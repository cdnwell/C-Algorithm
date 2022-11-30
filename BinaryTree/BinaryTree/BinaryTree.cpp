
// ��ǥ���� ���� �ڷᱸ�� : �׷���, ���� Ʈ��
// �������� Ž�� �ӵ� ������ ���� ����ϴ� ����
// �� ����(Heap Sort)�� ���� �� �� �����͸� ������� �ʾƵ� �Ǿ����� ���� Ʈ�������� �����͸� ����ؾ� ��.
// 
// ���� Ʈ���� �� �� ���� Ž���� �����ϰ� ���ִ� �� -> Ʈ���� ���� �����Ǿ��� �� Ư�� �����͸� ã���� �ϸ�
// ���� ������ ���� -> ���� ... �� �� ���� ã��. �� �� ���� �� ������ 1/2 �� �����ͷ��� �پ�� log2N
// Ʈ�� ������ �ұ�Ģ�ϰ� ���� ������ �� ����. heap ���� �� ���� ���� ���� Ʈ��, ���� Ʈ���� �迭�� ǥ���ϱ� ����
//
// ��� ���������θ� ���� ��� ���� ����Ʈ�� -> ������ �����.
// �������� ���� ���̱� ���� ������ ���, ����� ���� 4�� -> ������ 4��, �迭�� 14�������� ...
// 
// �ڷ� ������ �����ͷ� ���� ���� ������ Ž�� ��� 3����
// 1. ���� ��ȸ
//  �ڱ� �ڽ��� ó���ϰ� - ���� - ������ ó��
// 2. ���� ��ȸ
//  ���� ó�� - �ڱ� ó�� - ������ ó��
// 3. ���� ��ȸ
//  ���� - ������ - �ڱ� �ڽ� ó��
//  ���� ��ȸ�� ���� ��� �� ���� -> ��ǻ�Ͱ� ����ϱ� ���� ������� �ٲ� �� ���� ��ȸ�� ���� ��� �ȴ�.
// ���� ��ȸ, ���� ��ȸ, ���� ��ȸ Ȯ���� �����ϰ� ����

#include <iostream>

using namespace std;

int number = 15;	// ����� ���� 15�� (1���� 15���� ���� ����Ʈ�� ����)

// ����ü ���, Ŭ������ ����� �����. ����ü���� �Լ��� �߰��� ���� Ŭ����
// ����ü�� Ŭ�������� �� ���� ������ �����̶�� �� �� �ִ�.

// �ϳ��� ��� ������ ������.
typedef struct node* treePointer;	// node��� ����ü�� treePointer��� �̸����� ������ �������� ����ϰڴ�.
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;	// node��� �̸����� ��� �� �� �ֵ��� ����

// ���� ��ȸ ����
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ ����
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ ����
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
		nodes[i].data = i;	// �����ʹ� 1���� 15���� �ڱ� �ڽ��� �� �� �յ��� ����.
		nodes[i].leftChild = NULL;	// ���� �ڽ� NULL
		nodes[i].rightChild = NULL;	// ������ �ڽ� NULL
	}
	for (int i = 1; i <= number; i++) {	// ����
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];	//2�� �θ𿡼� ���� ����.. Ȧ��
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];	//3�� �θ𿡼� ����������.. ¦��
		}
	}

	//preorder(&nodes[1]);
	//inorder(&nodes[1]);
	postorder(&nodes[1]);

	return 0;
}