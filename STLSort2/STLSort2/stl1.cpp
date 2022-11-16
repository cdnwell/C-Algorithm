#include <iostream>
#include <vector>
#include <algorithm>
// 실제로 c++을 이용해서 각종 프로그래밍을 할 때에는 vector를 많이 사용함
// 단순한 배열을 사용할 것이냐 vector를 사용할 것이냐는 프로그래밍을 하면서 알게 됨
// 단순 배열과 vector는 큰 차이가 없다고 생각하면 된다.

using namespace std;

int main(void) {
	vector<pair<int, string>> v;
	// pair는 한 쌍의 데이터를 다루기 위해서 사용할 수 있는 라이브러리
	// 첫번째 데이터 형 : int, 두번째 데이터 형 string
	// 단순히 정렬을 하면 앞의 int를 기준으로 정렬하게 됨
	v.push_back(pair<int, string>(90, "박한울"));
	v.push_back(pair<int, string>(85, "이태일"));
	v.push_back(pair<int, string>(82, "나동빈"));
	v.push_back(pair<int, string>(98, "강종구"));
	v.push_back(pair<int, string>(79, "이상욱"));

	// sort함수를 이용해서 벡터의 첫번째 값부터 마지막값까지 정렬을 해라라는 의미
	sort(v.begin(), v.end());

	// 벡터로 만든 하나의 리스트에 접근하기 위해서는 벡터에 붙어있는 다양한 함수를 사용
	// 가능하다.
	// push_back 같은 경우는 단순히 리스트의 마지막에 삽입하겠다는 의미이다.
	// size()는 현재 삽입이 이루어져서 벡터안에 총 몇개의 데이터가 들어있는지를 반환하는 함수
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
		// seconde 는 두번째 값을 의미, first, second 두 가지 값을 가지도록 설정 -> pair
	}

	// 벡터와 페어는 이런식으로 사용 가능하다. 
	// 벡터안에 담길 데이터가 하나의 한쌍 데이터가 차례대로 벡터에 들어간다는 의미
	// 학생들의 정보가 한쌍 한쌍으로 들어감

	// 일반적으로 이렇게 짧게 코딩을 하는 것을 숏코딩이라 한다.
	// 같은 알고리즘 효율이면 소스코드가 짧을 수록 유리할 것임.
	// 배열의 원소를 뒤에서부터 삭제하거나 삽입이 쉬워진다.

	// 알고리즘 대회에서 STL을 얼마나 많이 알고 있는지도 중요한 지표가 된다. 
	return 0;
}