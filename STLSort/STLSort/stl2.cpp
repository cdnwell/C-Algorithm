// sort 함수가 강력한 이유 : 우리가 정렬할 기준을 우리 마음대로 정의할 수 있어서.
#include <iostream>
#include <algorithm>
// algorithm 헤더 파일안에는 sort 함수가 정의되어 있다.

using namespace std;

bool compare(int a, int b) {
	return a < b;	// a가 b보다 작을 때, true 값이 반환 된다.
	// 기본적으로 sort함수는 오름 차순 정렬을 내부적으로 포함하고 있었다.
	// compare 함수를 없애도 동일한 결과가 나온다.

	// 정렬 기준을
	// return a > b;
	// 로 하면 내림차순으로 정렬이 진행된다.
;}

int main(void) {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	// 처음을 가리키는 메모리 주소와, 
	// 맨 마지막을 가리키는 메모리 주소를 매개변수로 넣으면 된다.
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}