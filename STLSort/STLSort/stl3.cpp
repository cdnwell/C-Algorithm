// 일반적으로 프로그램을 지칭할 때는 객체 지향 프로그래밍
#include <iostream>
#include <algorithm>

// 시험 성적을 기준으로 오름차순 정렬

using namespace std;

class Student {	
	// 클래스는 여러개의 변수를 하나로 묶기 위해 주로 사용 한다.
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 작은 순서'
	// 다른 학생과 비교를 할 때 내 점수가 더 낫다면 우선순위가 더 높다.
	// 점수가 작은 순서부터 출력하겟다.
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}