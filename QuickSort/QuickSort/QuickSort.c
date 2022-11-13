#include <stdio.h>

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	// start = ������ �����ϴ� �κ������� ù��°
	// end = ������
	if (start >= end) {	// ���Ұ� 1���� ���
		return;
	}

	int key = start;	// Ű�� ù��° ����
	int i = start + 1;	// i�� ���ʺ��� �ϳ��� �⺻ ���Ҹ� ã��
	// Ű ���� �ٷ� ������
	int j = end;
	int temp;

	while (i <= j) {	// ������ �� ���� �ݺ�, �������� ��� �� ���ʿ� �ִ� ����
		// �ǹ� ���� �ٲ���
		while (data[i] <= data[key]) {	// Ű ������ ū ���� ���� �� ���� ���������� �̵�
			i++;
			// �������� �� ��ü�� �� �� ���ʿ� �ִ� ���� ��ü�� �ϱ� ������
			// ���� ������ �Ȱɾ �ȴ�.
		}// 1. ������ data[i] >= data[key]�� �ٲٰ�
		while (data[j] >= data[key] && j > start) {	// Ű ������ ���� ���� ���� �� ���� �ݺ�
			j--;
		}// 2. data[j] <= data[key]�� �ٲٸ�
		// 3. ������������ ������ �ȴ�.
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
			// �����Ͱ� �������� �� ������ ���� key���� �ٲ��ְ�
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			// �������� �ʾҴٸ� ū ���� ���� ���� �ٲ���
		}
	}

	quickSort(data, start, j - 1);
	// j <- ������ ���� �迭 ��ȣ
	// j - 1 <- �ٷ� ����
	// j + 1 <- �ٷ� ������
	quickSort(data, j + 1, end);
}

int main(void) {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}// ���� ������ �ȴٸ� ���� �̽� Ÿ������ Ȯ���� ����.

	return 0;
}