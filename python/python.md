# Python

This document is about the concept of Python

---
## Index
1. [function](#function)
2. [for문](#for)
---
<a id = "function"></a>
## 1. function  
Python은 def라는 reserved word를 통해 함수를 정의한다.  
```python
def make_teams(student, count):
	list = []
	for i in range(count):
		list.append([])
	for i in range(len(student)):
	 	list[i % count].append(student[i])

	return list
```
Python은 block단위로 짜는게 아니라서 *indentation* 을 통해 기능을 구분한다(고 배웠다)  
사용하는 방법은 다른 언어와 같다.  

<a id = "for"></a>
## 2. for문  
Python은 for in이라는 구조를 default 로 제공한다.
```python
voca = ['rose', 'candle', 'paper', 'book', 'song', 'candle', 'berry', 'paper', 'berry', 'berry', 'song', 'paper', 'rose', 'song', 'lion', 'berry', 'rose', 'book', 'rose', 'rose']
for element in voca:
	if element in dic:
		dic[element] += 1
	else:
		dic[element] = 1
```
코드를 보면 element에는 voca의 요소들이 하나씩 대응되게 된다. index로 접근하는 것이 아닌 element단위로 접근한다.

index로 접근하는 방법도 있다.
```python
voca = ['rose', 'candle', 'paper', 'book', 'song', 'candle', 'berry', 'paper', 'berry', 'berry', 'song', 'paper', 'rose', 'song', 'lion', 'berry', 'rose', 'book', 'rose', 'rose']
for element in range(len(voca)):
	if element in dic:
		dic[element] += 1
	else:
		dic[element] = 1
```
