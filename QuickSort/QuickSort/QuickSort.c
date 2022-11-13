#include <stdio.h>

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	// start = 정렬을 수행하는 부분집합의 첫번째
	// end = 마지막
	if (start >= end) {	// 원소가 1개인 경우
		return;
	}

	int key = start;	// 키는 첫번째 원소
	int i = start + 1;	// i는 왼쪽부터 하나씩 기본 원소를 찾음
	// 키 값의 바로 오른쪽
	int j = end;
	int temp;

	while (i <= j) {	// 엇갈릴 때 까지 반복, 엇갈리는 경우 더 왼쪽에 있는 값과
		// 피벗 값을 바꿔줌
		while (data[i] <= data[key]) {	// 키 값보다 큰 값을 만날 때 까지 오른쪽으로 이동
			i++;
			// 엇갈렸을 때 교체를 할 때 왼쪽에 있는 값과 교체를 하기 때문에
			// 굳이 조건을 안걸어도 된다.
		}// 1. 조건을 data[i] >= data[key]로 바꾸고
		while (data[j] >= data[key] && j > start) {	// 키 값보다 작은 값을 만날 때 까지 반복
			j--;
		}// 2. data[j] <= data[key]로 바꾸면
		// 3. 내림차순으로 정리가 된다.
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
			// 데이터가 엇갈렸을 때 왼쪽의 값과 key값을 바꿔주고
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			// 엇갈리지 않았다면 큰 값과 작은 값을 바꿔줌
		}
	}

	quickSort(data, start, j - 1);
	// j <- 정렬이 끝난 배열 번호
	// j - 1 <- 바로 왼쪽
	// j + 1 <- 바로 오른쪽
	quickSort(data, j + 1, end);
}

int main(void) {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}// 무한 루프가 된다면 거의 미스 타이핑일 확률이 높다.

	return 0;
}