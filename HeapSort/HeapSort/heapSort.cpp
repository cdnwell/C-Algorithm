#include <stdio.h>

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
	for (int i = 01; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;	// 가장 큰 값을 맨 뒤로 보낸다.
		int root = 0;
		int c = 1;	// c를 이용해서 반복적으로 힙을 구성
		do {
			c = 2 * root + 1;
			// 자식 중에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;	// 왼쪽과 오른쪽 중에서 더 큰값을 c에 답는다.
			}
			// 루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
			// 계속해서 재귀적으로 연산해서 힙구조를 만듦
		} while (c < i);
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
	// 항상 N * log N을 보장, 단순히 이론상으로는 퀵 정렬이나 병합 정렬보다 더 효율적이다.

	return 0;
}