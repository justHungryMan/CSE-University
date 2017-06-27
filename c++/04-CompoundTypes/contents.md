# 04. Compound types
---
## Index
1. [Array](#Array)
2. [String](#String)
3. [String Class](#StringClass)
---
<a id="Array"/>

## 1. Array
배열은 **데이터형이 같은 여러 개의 값을 연속적으로 저장할 수 있는 데이터 구조** 이다. 배열에서 각 값은 배열 원소라는 개별 공간에 저장된다. 컴퓨터는 이 모든 원소들을 메모리에 연속적으로 배치한다.  
배열 선언 구문은 다음 세 가지를 선언한다.  
* 각 원소에 저장될 값의 데이터형
* 배열의 이름
* 배열 원소의 개수  

```c++
short months[12];     // 12개의 short형 값을 넣을 수 있는 배열을 생성
```

일반적인 형식 : `typeName arrayName[arraySize]`

---

##### Listing 4.1  
배열을 선언하고, 배열 원소에 값을 대입하며, 배열을 초기화하는 것과 같은 배열에 관련된 몇 가지 사항을 보여준다.  

```c++
// arrayone.cpp -- 정수 형의 작은 배열
#include <iostream>
int main() {
	using namespace std;
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = {200, 300, 50};

	cout << "고구마 합계 = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "개가 들어 있는 포장은 ";
	cout << "개당 " << yamcosts[1] << "원씩입니다. \n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "세 포장의 총 가격은 " << total << "원입니다.\n";
	cout << "\nyams 배열의 크기는 " << sizeof yams;
	cout << "바이트 입니다.\n";
	cout << "원소 하나의 크기는 " << sizeof yams[0];
	cout << "바이트 입니다.\n";
	return 0;
}
```
##### 출력
```
고구마 합계 = 21
8개가 들어 있는 포장은 개당 300원씩입니다.
세 포장의 총 가격은 4100원입니다.

yams 배열의 크기는 12바이트 입니다.
원소 하나의 크기는 4바이트 입니다.
```
##### 프로그램 분석  
* Listing 4.1은 3개의 원소를 가진 yams라는 배열을 생성한다.
* yams의 각 배열 원소는 int형이므로 int형의 모든 특성을 그대로 가진다.  
* 다음과 같이 배열 원소를 초기화할 수 있다.  
  `int yamcosts[3] = {200, 300, 50};`
* 배열을 초기화하지 않으면, 배열 원소의 값들은 미확정 상태로 남는다.
* 배열 이름에 sizeof 연산자를 적용하면 그 배열의 전체 크기가 바이트 단위로 리턴된다.  

##### 배열 초기화 규칙
C++은 배열을 초기화하는 데 몇 가지 규칙을 적용한다. 이 규칙은 **배열 초기화를 할 수 있는 시기** 를 제한한다. 또한 **배열 원소의 개수와 초기화 리스트에 제시된 값의 개수가 일치하지 않을 때** 어떻게 할 것인지를 결정한다.  
```c++
int card[4] = {3, 6, 8, 10}   //  OK
int hand[4];                  //  OK
hand[4] = {5, 6, 7, 8};       //  NO
hand = cards;                 //  NO
```  
배열을 초기화할 때, 초기화 값의 개수를 배열 원소의 개수보다 모자라게 제공할 수도 있다.
```c++
float hotelTips[5] = {5.0, 2.5};
```
배열을 부분적으로 초기화하면, 컴파일러가 나머지 원소들을 모두 0으로 설정한다.
###### 다른 예시
```c++
long totals[500] = {0};
```
배열을 초기화할 떄 대괄호 속을 비워 두면, 컴파일러가 초기화 값의 개수를 세어 배열의 원소 갯수를 결정한다.
```c++
short things[] = {1, 5, 3, 8};
```
##### C++11 배열 초기화
배열을 초기화할 때, = 부호를 사용하지 않아도 된다.
```c++
double earnings[4] {1.2e4, 1.6e4, 1.1e4, 1.7e4};
```
중괄호를 공백으로 하여 모든 배열을 0으로 초기화할 수 있다.
```c++
unsigned int counts[10] = {};
float balances[100] {};
```
리스트 초기화시에 narrowing을 방지할 수 있다.
```c++
long plifs[] = {25, 92, 3.0};   //  NO
char slif[4] = {'h', 'i', 1122011, '\0'}; //  NO
char tlifs[4] {'h', 'i', 112, '\0'};    // OK
```  
---
<a id="String"/>

## 2. String
String이란 **메모리에 바이트 단위로 연속적으로 저장되어 있는 문자** 들을 말한다. 문자들이 메모리에 바이트 단위로 연속적으로 저장된다는 것의 의미는 문자열을 char형의 배열에 저장할 수 있다는 것을 의미한다.  
모든 문자열의 마지막 문자는 반드시 null(\0)문자여야 한다.  
```c++
char dog[8] = {'b', 'e', 'a', 'u', 'x', '', 'i', 'i'};    //  문자열이 아니다.
char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'};  //  문자열이다.
```
C++에서 cout은 null 문자를 만날 때까지 문자 단위로 문자열을 처리한다. dog를 cout으로 처리하면 우연히 null 문자를 만날 때까지 이어진다.  
위의 선언이 번거로워 **문자열 상수** 방법으로 초기화한다.
```c++
char bird[10] = "Mr. Cheeps";   //  \0을 저장한다
char fish[] = "Bubbles";        //  컴파일러가 알아서 처리한다.
```  
문자열을 저장할 char형의 배열은 그 크기가 **null 문자까지 포함하여** 그 문자열에 들어 있는 모든 문자들을 다 넣을 수 있을 만큼 충분히 커야한다. 위의 bird에서 남는 공간은 모두 "\0"로 채워진다.  
```c++
char shirt_size = 'S';		//	OK
char shirt_size = "S";		//	NO
```
문자열 상수와 문자 상수는 서로 바꾸어 쓸 수 없다. "S"는 S와 \0로 구성된 문자열을 뜻한다. "S"는 내부적으로 그 문자열이 저장되어 있는 메모리 주소를 의미한다.  

##### 문자열 상수의 결합
다음과 같은 표현이 가능하다.
```c++
cout << "I'd give my right arm to be" " a great violinist. \n";
cout << "I'd give my right arm to be a great violinist. \n";
cout << "I'd give my right ar" "m to be a great violinists. \n";
```

##### 배열에 문자열 사용
```c++
// strings.cpp -- 배열에 문자열을 저장한다.
#include <iostream>
#include <cstring>

int main() {
	using namespace std;
	const int size = 15;
	char name1[size];
	char name2[size] = "C++owboy";

	cout << "안녕하세요! 저는 " << name2;
	cout << "입니다! 실례지만 성함이?\n";
	cin >> name1;
	cout << "아, " << name1 << " 씨! 당신의 이름은 ";
	cout << strlen(name1) << "자입니다만 \n";
	cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
	cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';
	cout << "제 이름의 처음 세 문자는 다음과 같습니다. ";
	cout << name2 << endl;
	return 0;
}
```
##### 출력
```
안녕하세요! 저는 C++owboy입니다! 실례지만 성함이?
sungjun
아, sungjun 씨! 당신의 이름은 7자입니다만
15바이트 크기의 배열에 저장되었습니다.
이름이 s자로 시작하는군요.
제 이름의 처음 세 문자는 다음과 같습니다. C++
```
##### 프로그램 분석
* `strlen()` 함수는 배열에 저장된 문자열의 크기를 리턴한다.
* 인덱스를 사용해 배열에 저장되어 있는 문자에 개별적으로 접근이 가능하다.

```c++
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
```
##### 출력
```
이름을 입력하십시오:
Sungjun lee
좋아하는 디저트를 입력하십시오:
맛있는 lee 디저트를 준비하겠습니다. Sungjun 님!
```
##### 프로그램 분석
* 디저트를 입력하라는 프롬프트에 응답할 기회를 주지 않는다.
* `cin`은 빈칸, 텝, 캐리지 리턴을 문자열의 끝이라 간주한다.
* `cin`은 `Sungjun`을 첫 번째 문자열로 읽어 name 배열에 저장한다.
* `lee`는 입력 큐에 그대로 남긴다.
* 좋아하는 디저트에 대한 응답을 얻기 위한 `cin`이 `lee`를 두 번째 문자열로 읽어 dessert 배열에 저장한다.

##### 한 번에 한 행의 문자열 입력 읽기
###### getline()을 이용한 행 단위 입력
* `getline()` 함수는 enter 키에 의해 전달되는 개행 문자를 입력의 끝으로 간주하여 한 행 전체를 읽는다.
* 첫 번째 매개변수는 입력한 행을 저장할 배열의 이름
* 두 번째 매개변수는 입력받은 문자들의 한계
	`cin.getline(name, 20)`

```c++
// instr2.cpp -- getline() 함수로 한 행을 읽는다.
#include <iostream>

int main() {
	using namespace std;
	const int arSize = 20;
	char name[arSize];
	char dessert[arSize];

	cout << "이름을 입력하십시오: \n";
	cin.getline(name, arSize);
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.getline(dessert, arSize);
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";
	return 0;
}
```
##### 출력
```
이름을 입력하십시오:
Sungjun lee
좋아하는 디저트를 입력하십시오:
Red velvet
맛있는 Red velvet 디저트를 준비하겠습니다. Sungjun lee 님!
```

###### get() 을 이용한 행 단위 입력
* 개행 문자를 읽어서 버리지 않고 입력 큐에 그대로 남겨 둔다.

```c++
cin.get(name, arSize);
cin.get(dessert, arSize);		//	문제 발생
```
첫 번째 호출이 입력 큐에 개행 문자를 그대로 남겨 두기 때문에, 두 번째 호출은 그 개행 문자를 첫 문자로 만나게 된다. 따라서 get()은 읽을 것도 없이 곧 바로 행의 끝에 도달했다고 결론을 내린다.
```c++
cin.get(name, arSize);			// 첫 번째 행을 읽는다.
cin.get();									// 개행 문자를 읽는다.
cin.get(dessert, arSize);		// 두 번째 행을 읽는다.
```
`cin.get()`을 사용하여 개행 문자를 처리해 해결할 수 있다.
```c++
cin.get(name, arSize).get();	// 멤버 함수들을 결합한다.
```
이와 같이 사용하면 cin.get(name, arSize)가 cin 객체를 리턴한다. 리턴된 cin 객체는 뒤에 결합된 get() 함수를 호출하는 객체로 사용된다.
```c++
cin.getline(name1, arSize).getline(name2, arSize);
```
이 것은 `cin.getline()`을 두 번 호출하는 것과 같다.

```c++
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
```
##### 출력
```
이름을 입력하십시오:
Sungjun lee
좋아하는 디저트를 입력하십시오:
Red velvet
맛있는 Red velvet 디저트를 준비하겠습니다. Sungjun lee 님!
```
* `cin.get(name, arSize)`는 문자열을 읽어 배열에 저장하라는 의미
* `cin.get()`은 문자 하나를 읽으라는 의미 (overloading)
* 개행 문자를 확인해 Error checking을 한다.

###### 빈 행과 기타 문제점
getlin()이나 get()이 빈 행을 읽으면 `failbit`이라는 것이 설정되는데 이는 입력을 막는다는 의미이다. 입력을 복원하려면 다음과 같은 명령어를 사용해야 한다.  
`cin.clear();`

##### 문자열과 수치의 혼합 입력
```c++
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
```
##### 출력
```
지금 사시는 아파트에 언제 입주하셨습니까?
2016
사시는 도시를 말씀해 주시곘습니까?
아파트 입주 연도: 2016
도시:
등록이 완료되었습니다!
```
이 프로그램은 주소를 입력할 기회를 주지않는다. `Enter` 키가 만들어 내는 개행 문자를 입력 큐에 남겨 두기 때문이다. `cin.getline()` 은 입력 큐에 남겨진 개행 문자를 빈 행으로 받아들이고 `address`배열에 널 문자열을 대입한다.
```c++
// 첫 번째 해결방법
cin >> year;
cin.get();
// 두 번째 해결방법
(cin >> year).get();
```
---
<a id="StringClass"/>

## 3. String Class
ISO/ANSI C++ 표준은 string class를 추가해 C++ library를 확장시켰다.  
string는 std 이름 공간에 속해 있으므로, using 지시자를 사용하거나 `std::string`을 사용하여 그 클래스를 참조해야 한다.

```c++
// strtype1.cpp -- C++ string class를 사용한다
#include <iostream>
#include <string>
int main() {
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "고양이과의 동물 한 종을 입력하시오: ";
	cin >> charr1;
	cout << "고양이과의 또 다른 동물 한 종을 입력하시오: ";
	cin >> str1;
	cout << "아래 동물들은 모두 고양이과입니다:\n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
	cout << charr2 << "에서 세 번째 글자: " << charr2[2] << endl;
	cout << str2 << "에서 세 번째 글자: " << str2[2] << endl;

	return 0;
}
```
##### 출력
```
고양이과의 동물 한 종을 입력하시오: ocelot
고양이과의 또 다른 동물 한 종을 입력하시오: tiger
아래 동물들은 모두 고양이과입니다:
ocelot jaguar tiger panther
jaguar에서 세 번째 글자: g
panther에서 세 번째 글자: n
```
* C 스타일 문자열로 string 객체를 초기화할 수 있다.
* cin을 사용해 string 객체에 키보드 입력을 저장할 수 있다.
* cout을 사용해 string 객체를 display 할 수 있다.
* 배열 표기를 사용해 string 객체에 저장되어 있는 개별적인 문자들에 접근 할 수 있다.
```c++
string str1;
string str2 = "panther";
```
이 클래스 설계는 크기 문제를 프로그램이 자동으로 처리해준다.
```c++
cin >> str1;		//	str1은 입력에 맞게 크기가 조절된다.
```
##### C++11 문자열 초기화
```c++
char first_date [] = {"Le Chapon Dodu"};
char second_date [] = {"The Elegant Plate"};
string third_date = {"The Bread Bowl"};
string fourth_date = {"Hank's Fine Eats"};
```
##### 대입, 결합, 추가
```c++
char charr1[20];						//	빈 배열을 생성한다.
char char22[20] = "jaguar";				//	초기화된 배열을 생성한다.
string str1;							//	빈 string 객체를 생성한다.
string str2 = "pantehr";			 	//	초기화된 string 객체를 생성한다.
charr2 = charr2;						//	No, 배열 대입 X
str1 = str2;							//	Ok, 객체 대입 O
```
위와 같이 string 객체는 쉽게 조작이 가능하다.
```c++
// strtype2.cpp	-- 대입, 추가, 첨부
#include <iostream>
#include <string>
int main() {
	using namespace std;
	string s1 = "penguin";
	string s2, s3;

	cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "string 객체에 C 스타일 문자열을 대입할 수 있다. \n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string 객체들을 추가할 수 있다.\n";
	s1 += s2;
	cout <<"s1 += s2 --> s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;

	return 0;
}
```
##### 출력
```
string 객체를 string 객체에 대입할 수 있다: s2 = s1
s1: penguin, s2: penguin
string 객체에 C 스타일 문자열을 대입할 수 있다.
s2 = "buzzard"
s2: buzzard
string 객체들을 결합할 수 있다: s3 = s1 + s2
s3: penguinbuzzard
string 객체들을 추가할 수 있다.
s1 += s2 --> s1 = penguinbuzzard
s2 += " for a day" --> s2 = buzzard for a day
```
##### string class의 조작
string 객체에 사용되는 테크닉과 문자 배열에 사용되는 테크닉을 비교한다.
```c++
// strtype3.cpp -- string 클래스의 기타 기능
#include <iostream>
#include <string>
#include <cstring>
int main() {
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " paste";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << str1 << " 문자열에는 " << len1 << "개의 문자가 들어 있다.\n";
	cout << charr1 << " 문자열에는 " << len2 << "개의 문자가 들어 있다.\n";

	return 0;
}
```
##### 출력
```
panther paste 문자열에는 13개의 문자가 들어 있다.
jaguar juice 문자열에는 12개의 문자가 들어 있다.
```

##### string class의 입출력
```c++
// strtype4.cpp -- 행 단위 입력
#include <iostream>
#include <string>
#include <cstring>

int main() {
	using namespace std;
	char charr[20];
	string str;

	cout << "입력 이전에 charr에 있는 문자열의 길이: " << strlen(charr) << endl;
	cout << "입력 이전에 str에 있는 문자열의 길이: " << str.size() << endl;
	cout << "텍스트 한 행을 입력하시오:\n";
	cin.getline(charr, 20);
	cout << "입력한 텍스트: " << charr << endl;
	cout << "또 다른 텍스트 한 행을 입력하시오:\n";
	getline(cin, str);
	cout << "입력한 텍스트: " << str << endl;
	cout << "입력 이후에 charr에 있는 문자열의 길이: " << strlen(charr) << endl;
	cout << "입력 이후에 str에 있는 문자열의 길이: " << str.size() << endl;

	return 0;
}
```
##### 출력
```
입력 이전에 charr에 있는 문자열의 길이: 0
입력 이전에 str에 있는 문자열의 길이: 0
텍스트 한 행을 입력하시오:
I'm so hungry
입력한 텍스트: I'm so hungry
또 다른 텍스트 한 행을 입력하시오:
Really?
입력한 텍스트: Really?
입력 이후에 charr에 있는 문자열의 길이: 13
입력 이후에 str에 있는 문자열의 길이: 7
```
* `getline()` 은 클래스 메서드가 아니다.
* `string`이 도입되기 전에 istream이 존재해서 string 객체를 처리하는 istream 클래스 메서드는 없다.
