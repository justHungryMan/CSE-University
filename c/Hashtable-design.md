# Hashtable-design

C언어로 Hashtable을 설계하던 중 포인터에 관한 문제가 발생하여 천천히 설계부터 다시 시작하려고 이 문서를 작성한다.

### 문제점
hashtable을 가리키는 포인터 `(이하 table)` 를 동적할당하고 이를 table-doubling 하는 과정에서 table을 메모리 해제 시키고 다시 동적 할당하는 것이 c언어에서는 불가능하다는 것을 깨달았다.
- 이는 메모리 해제가 선언 시점에서 이루어지는 것이 아님을 깨닫게 되었다. 이와 관련된 내용은 나중에 알아볼 예정이다.

### 해결방안
double pointer 을 이용해 hashTable을 구상한다. 그러면 pointer 자체를 free할 일이 없으므로 자유롭게 hashTable을 free할 수 있다.

### 구현해야할 사항
1. hashTable을 가리키는 double pointer
2. hashTable의 chaining node
3. hashTable 생성함수
4. hashTable table doubling 함수
5. hashTable destroy 함수
6. hash 함수
7. hashTable chain add 함수
8. hashTable add 함수
9. hashTable value exist 함수
10. hashTable value get by key 함수
11. hashTable key remove 함수
12. hashTable show 함수
