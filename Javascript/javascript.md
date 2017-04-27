# Javascript

This document is about the core concept of Javascript

---
### Index
1. [Scope](https://github.com/jun-Sogang/CSE-Sogang-University/blob/master/Javascript/javascript.md#1-scope-)
2. [Closure](https://github.com/jun-Sogang/CSE-Sogang-University/blob/master/Javascript/javascript.md#2-closure-)

---

#### 1. Scope
* The scope of a program variable is **the range of statement in which the variable is visible**
* A variable is visible in a statement if it can be referenced in that statement
* The scope rules of a language determine **how references to names are associated with variables**

##### _Example_

* `javascript의 scope는 함수단위`
* `변수 명의 중복`
* `var keyword 생략`
* `hoisting 1`
* `hoisting 2`

###### 1. Javascript has a function unit scope

Since javascript has a **function unit scope**, the following example is satisfied.
```
var example = function scopeTest() {  
    var a = 0;
    for (var b = 0; b < 5; b += 1) {
      console.log("b = " + b);
      if (b === 4){
        var c= true;
        console.log("c =" + c);
      }
    }
    console.log("b = " + b);
    console.log("c = " + c);
}
example();  
```
######result
```b = 0
b = 1
b = 2
b = 3
b = 4
c =true
b = 5
c = true
```

###### 2.Duplicated variable names

In JavaScript, if the variable name is duplicated, the other duplicated variable has a **different scope**.

```
var a = 10;  
var example = function scopeExam(){  
    var a = 20;
    console.log("a = " +a);
}
example();  
```

###### result
```
a = 20
```

###### 3. Var keyword omitted
If the var keyword is omitted, it is assumed to be a **global variable**.
```
var example1 = function scopeExam(){  
    a = 10;
    console.log("a = " + a);
}

var example2 = function scopeExam(){  
    console.log("a = " + a);
}
example1();  
example2();  
```

###### result
```
a = 10
a = 10
```

###### 4. [Hoisting]($https://developer.mozilla.org/en-US/docs/Glossary/Hoisting)
Hoisting means that **variable and function declarations are physically moved to the top of your coding**

```
var example = function hoistingExam(){  
    console.log("a = " + a);
    var a =10;
    console.log("a =" + a);
}
example();
```

###### result
```
a = undefined
a = 10
```

###### 5. Hoisting in duplicated variables names
```
var a = 20;  
var example = function hoistingExam(){  
    console.log("a = " + a);
    var a = 10;
    console.log("a = " + a);
}
example();
```

###### result
```
a = undefined
a = 10
```
---
#### 2. Closure

* Closures are functions that refer to independent (free) variables. In other words, these functions **remember the environment** in which they were created.
* Lifetime : the period of time beginning when the procedure is entered and ending when execution of the procedure reaches the end
* **Accessing a variable with a lifetime terminated is called a closure.**

##### _Example_

* `Closure Example`
* `Different Closure`

###### Closure Example
```
var example = function scopeExam(){  
    var a= 0;
    return {
        plusOne : function() {
            a += 1;
        },
        plusTwo : function() {
            a += 2;
        },
        print : function() {
          console.log("a : " + a);
        }
    };
}
var plus = example();  
plus.plusOne();  
plus.print();
plus.plusTwo();  
plus.print();
plus.plusOne();
plus.print();  
plus.plusTwo();
plus.print();
```

###### result

```
a : 1
a : 3
a : 4
a : 6
```

##### Different Closure

```
var example = function scopeExam(){  
    var a= 0;
    return {
        plusOne : function() {
            a += 1;
        },
        plusTwo : function() {
            a += 2;
        },
        print : function() {
          console.log("a : " + a);
        }
    };
}
var plusFirst = example();  
var plusSecond = example();  
plusFirst.plusOne();  
plusFirst.print();
plusFirst.plusTwo();  
plusFirst.print();
plusSecond.plusOne();
plusSecond.print();  
plusSecond.plusTwo();
plusSecond.print();
```

###### result
```
a : 1
a : 3
a : 1
a : 3
```
