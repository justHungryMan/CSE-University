# 06. Branching Statements and Logical Operators
---
## Index
1. [The if Statement](#TheIfStatement)
2. [The if else statement](#TheIfElseStatement)
3. [String Class](#StringClass)
---
<a id="TheIfStatement"/>

## 1. The if Statement
The *if* statement directs a program to execute a statement or statement block if a test condition is true and to skip that statement or block if the condition is false

**Syntax**
```c++
statement1
if (test_expr)
  statement2
statement3
```

---

##### Listing 6.1  if.cpp
```c++
//	if.cpp	--	using the if statement
#include <iostream>
int main() {
	using std::cin;
	using std::cout;

	char ch;
	int spaces = 0;
	int total = 0;

	cin.get(ch);
	while (ch != '.') {
		if (ch == ' ')
			++spaces;
		++total;
		cin.get(ch);
	}
	cout << spaces << " spaces, " << total;
	cout << " chracters total in sentence\n";

	return 0;
}
```
##### output
Input : `Time flies like an arrow.`
```
4 spaces, 24 chracters total in sentence
```
##### Program
* `++spaces` statement is executed only when ch is a space

---
<a id="TheIfElseStatement"/>

## 2. The if else statement
Whereas an `if` statement lets a program decide whether a **particular state or block is executed**, an `if else` statement lets a program decide **which of `two` statements or blocks is executed.**

**General form**
```c++
if (test-condition)
  statement1
else
  statement2
```

##### Listing 6.2  ifelse.cpp
```c++
//	ifelse.cpp	--	using the if else statement
#include <iostream>
int main() {
	using namespace std;
	char ch;

	cout << "Type, and I shall repeat.\n";
	cin.get(ch);

	while (ch != '.') {
		if (ch == '\n')	cout << ch;
		else cout << ++ch;
		cin.get(ch);
	}
	cout << "\nPlease excuse the slight confusion.\n";
	return 0;
}

```
##### output
Input : `I'm so hungry Is that serious? Yes.`
```
Type, and I shall repeat.
J(n!tp!ivohsz
Jt!uibu!tfsjpvt@
Zft
Please excuse the slight confusion.
```  

##### Formatting `if else` Statements
If you need more than one statement, **you must use brace** to collect them into a single block statement.  
