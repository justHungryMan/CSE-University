// instr3.cpp -- get() & get() 으로 여러 단어를 읽는다
#include <iostream>

int main() {
	using namespace std;
	const int arSize = 20;
	char name[arSize];
	char dessert[arSize];
					
	cout << "이름을 입력하십시오: \n";
	cin.get(name, arSize).get();
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.get(dessert, arSize).get();
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";
	return 0;
}
