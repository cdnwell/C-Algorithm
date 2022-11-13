#include <stdio.h>

//�θ� ��带 ã�� �Լ�
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
		//x��� ���� �ش� �θ��� ���� �����ϴٸ� 
		//x��ü�� ��ȯ�� �� �ֵ��� ������ش�.
		//����Լ��� ����κ�
	//���� �ڱ��ڽ��� ����Ű���ִ� �θ����� ���� �ڱ� �ڽ��� �ٸ��ٸ�
	//���� �θ� ã�� ���ؼ�
	//��������� �Լ��� �����Ѵ�.
	return parent[x] = getParent(parent, parent[x]);
	//3�� 2�� ����Ű�� ���� �� �ٽ� 2�� ����Ű���ִ� 1�� ã�Ƴ��� ������
	//getParent��� �Լ���� �� �� �ִ�.
}

//�� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b) {
	//a�� b�� �Է� �޾Ƽ� ������ �θ��� ���� �ڿ�
	a = getParent(parent, a);
	b = getParent(parent, b);
	//�� ���� �� ������ �θ� ������
	if (a < b) parent[b] = a;
	else parent[a] = b;
	//b�� �� ū ���̶�� b�� �θ� a�� �ɼ� �ֵ��� ������ �ش�.
	//�׷��� �ʴٸ� a�� �� ū ��쿡�� a�� �θ� ������ b�� �־��� �� �ֵ��� ����
	//�׻� �θ� ��ĥ ���� �� ���� ������ ��ģ��.
}

//���� �θ� �������� Ȯ���ϴ� �Լ�
//���� �׷����� �����ִ��� ����� �Ͱ� ����.
//���� �ΰ��� �׷����� ������ �׷����� �����ִ���
int findParent(int parent[], int a, int b) {
	//�θ� ���� �̿��ؼ� Ȯ���� ��
	a = getParent(parent, a);
	b = getParent(parent, b);
	//a�� b�� ���ؼ� ���ٸ� ���� �θ� ������ ���� -> 1�� ��ȯ
	if (a == b) return 1;
	else return 0;
	//�׷��� �ʴٸ� 0�� ��ȯ�ؼ� ���� �ٸ� �θ� �ٸ� �׷����� �����ִٴ� ���� �˷���
}

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
		//�⺻������ �ڱ� �ڽ��� �θ�� ����Ű���� ����� �ֱ�
	}
	//�� ���� ���Ҹ� ���ĺ�
	//�׷���1
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	//�׷���2
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	//findParent�� �̿��ؼ� 1�� 5�� ���� �׷����� �����ִ��� Ȯ��
	//1�� 5�� �ٸ� �׷����� �����ִ�.
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	printf("����� �� [1] : %d\n", getParent(parent, 1));
	printf("����� �� [5] : %d\n", getParent(parent, 5));
	unionParent(parent, 1, 5);
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	printf("����� �� [1] : %d\n", getParent(parent, 1));
	printf("����� �� [5] : %d\n", getParent(parent, 5));

	return 0;
}