// instr1.cpp -- 여러 개의 문자열을 읽는다.
#include <iostream>

int main() {
	using namespace std;
	const int arSize = 20;
	char name[arSize];
	char dessert[arSize];

	cout << "이름을 입력하십시오: \n";
	cin >> name;
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin >> dessert;
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";
	return 0;
}
