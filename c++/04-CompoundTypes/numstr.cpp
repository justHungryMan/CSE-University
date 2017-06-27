// numstr.cpp -- 수치 입력 뒤에 오는 문자열 입력
#include <iostream>
int main() {
	using namespace std;
	cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
	int year;
	cin >> year;
	cout << "사시는 도시를 말씀해 주시곘습니까?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "아파트 입주 연도: " << year << endl;
	cout << "도시: " << address << endl;
	cout << "등록이 완료되었습니다!\n";
	return 0;
}
