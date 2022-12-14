// 자주 나오는 알고리즘임. 
// 문제의 종류가 많고 컴퓨터적인 사고방식을 시험하기 좋음
// DP -> 한 번 해결한 문제는 한 번 만 풀기.

// DP는 다음의 가정 하에 사용 가능하다.
// 1번 가정. 큰 문제를 작은 문제로 나눌 수 있습니다.
// 2번 가정. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일합니다.

// 이미 구한 답을 잠시 기억하는 것을 메모이제이션이라고 합니다.

#include <stdio.h>

int d[100];	// 이미 구한 값이라면 구한 값 자체를 반환 하도록 함

int dp(int x) {
	if (x == 1) return 1;	// 재귀 함수가 종료되는 조건
	if (x == 2) return 1;	// 1, 1, 2, 3, ... 피보나치 수열
	if (d[x] != 0) return d[x];		// 초기값이 아닌 저장된 값이 있다면 반환한다.
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
	printf("%d", dp(30));
}