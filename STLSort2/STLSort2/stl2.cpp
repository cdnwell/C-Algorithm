// �̸�, ����, ������ϱ��� ���� �� �л����� ���� ������� ����
// ���� ������ ���ٸ� ���̰� �� � �л��� �켱������ ������ ������ ��Ŵ
// �̷� ������ Vector�� Pair ���� �̿��ؼ� ������, Pair�� ���� ���� ��� ����

// ��� �ȿ� �� �� ���� ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
		// ������ ���ٸ� ��������� �� �����л� (� �л��� �켱������ ������ �ȴ�.)
	}
	else {
		// ������ �� �ٸ��ٸ� ������ �� ���� �л��� �켱������ ����.
		return a.second.first > b.second.first;
	}
	// �� �Լ��� �־��ָ� ���� ������ �ؼ��ϰ� �˾Ƽ� �۵���.
}

int main(void) {
	vector <pair<string, pair<int, int>>> v;
	// �̸� ������ ���� 90 ������� 1991222;
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("���ѿ�", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("�̻��", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(88, 19900302)));

	sort(v.begin(), v.end(), compare);	// compare��� ���� ������ �˷��־�� �Ѵ�.
	// ������ ���ٸ� ������ �л��� �̻�� �л� �� �� ������ �� �����л�(� �л�)�� 
	// �� ���� �켱������ ������ �ȴ�.

	// pair�� �������� ���ļ� ���� �Ǹ��� ������ �ΰ��� ��쿡�� ȿ�������� ������
	// ������ �� �ִ�.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	// ������ ������ 3���� �Ѿ�� ��쿡�� pair�� ���°� �� ������ �� �� �ְ�
	// �׷� ���� Ŭ������ �����ؼ� Ǯ���ִ°� �� ȿ������ �� �ִ�.
	// 2�� ������ ��쿡�� pair�� vector�� ������ ���� ������.

	return 0;
}