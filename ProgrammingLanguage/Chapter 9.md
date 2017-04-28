# Chaper 9
#### Subprograms
1. [Introduction](https://github.com/jun-Sogang/CSE-University/blob/master/ProgrammingLanguage/Chapter%209.md)
2. [FundamentalsOfSubprograms](https://github.com/jun-Sogang/CSE-University/blob/master/ProgrammingLanguage/Chapter%209.md)
3. Design Issues for Subprograms
4. Local Referencing Environments
5. Parameter Passing Methods
6. Parameters That are Subprogram Names
7. Overloaded Subprograms
8. Generic Subprograms
9. Design Issues for Functions
10. Accessing Nonlocal Environments
11. User-Defined Overloaded Operators
12. Coroutine

> Subprograms are the fundamental building blocks of programs and are therefore among the most important concepts in programming language design.

---

#### 9.1 Introduction

+ **Two fundamental abstraction facilities**
  * Process abstraction : (subprogram)
    * <-> procedure call: an abstraction of a collection of statements
  * Data abstraction :
    * <-> abstract data type
+ **In a modern programming language, a collection of statement is [reused](#reused) and ends up as a collection of machine instructions in memory**
  * memory space saving, coding time saving
  * such reuse is also an abstraction if the collection is placed in a program by a statement that "calls" that collection
  * Instead of explaining how some computation is to be done, that explanation (the collection of statement) is enacted by a "call" statement, effectively abstracting away the details
  * caller vs callee
* **Procedure vs [Macro](#macro)**

> reused : 한 번만 적고 reuse, 함수크기만큼만 메모리 사용. <a id="reused"></a>
>

***Procedure Example***

```
function factorial (n) {
  ---
}
main() {
  x = fac(4)
  y = fac(5)
}
```
> Macro : Copy해서 적는 것, 카피하니까 memory가 커진다. <a id="macro"></a>

***caller vs callee***

```
main() {
  sub(1);     // caller
}

sub(1) {
  ;           // callee
}
```

---

#### 9.2 Fundamentals of Subprograms

1. **General Subprogram Characteristics**
* **Basic characteristics of subprograms**
  * Each subprogram has a [single entry point](#singleEntryPoint)
  * the calling program unit is suspended during the execution of the called subprogram, which implies that there is ***only one subprogram in execution at any given time***
  * controls ***always returns to the caller*** when the subprogram execution terminates
2. **Basic Definitions**
* Basic Definitions
  * Subprogram definition describes the action of the subprogram abstraction
> Sing entry point : 하나로 들어가고 하나로 나감 <a id="singleEntryPoint"></a>
