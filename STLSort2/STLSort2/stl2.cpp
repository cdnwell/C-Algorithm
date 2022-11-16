// 이름, 성적, 생년월일까지 있을 때 학생들을 성적 순서대로 나열
// 만약 성적이 같다면 나이가 더 어린 학생이 우선순위가 높도록 정렬을 시킴
// 이럴 때에는 Vector와 Pair 만을 이용해서 가능함, Pair는 이중 페어로 사용 가능

// 페어 안에 또 페어가 들어가는 식

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
		// 성적이 같다면 생년월일이 더 느린학생 (어린 학생이 우선순위를 가지게 된다.)
	}
	else {
		// 성적이 더 다르다면 성적이 더 높은 학생이 우선순위가 높다.
		return a.second.first > b.second.first;
	}
	// 이 함수를 넣어주면 정렬 기준을 준수하게 알아서 작동함.
}

int main(void) {
	vector <pair<string, pair<int, int>>> v;
	// 이름 나동빈 성적 90 생년월일 1991222;
	v.push_back(pair<string, pair<int, int>>("나동빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("이태일", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("박한울", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("이상욱", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("강종구", pair<int, int>(88, 19900302)));

	sort(v.begin(), v.end(), compare);	// compare라는 정렬 기준을 알려주어야 한다.
	// 성적이 같다면 나동빈 학생과 이상욱 학생 중 더 생일이 더 느린학생(어린 학생)이 
	// 더 높은 우선순위를 가지게 된다.

	// pair를 이중으로 겹쳐서 쓰게 되면은 정렬이 두개인 경우에도 효과적으로 정렬을
	// 수행할 수 있다.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	// 정렬할 기준이 3개를 넘어가는 경우에는 pair를 쓰는게 더 복잡할 수 도 있고
	// 그럴 때는 클래스를 정의해서 풀어주는게 더 효과적일 수 있다.
	// 2개 이하일 경우에는 pair와 vector로 간단히 정렬 가능함.

	return 0;
}