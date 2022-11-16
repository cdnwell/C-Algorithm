#include <iostream>
#include <algorithm>
// algorithm 헤더 파일안에는 sort 함수가 정의되어 있다.

using namespace std;

int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10);
	// 처음을 가리키는 메모리 주소와, 
	// 맨 마지막을 가리키는 메모리 주소를 매개변수로 넣으면 된다.
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}