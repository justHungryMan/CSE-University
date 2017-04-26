# Javascript

This document is about the core concept of Javascript

---
### Index
1. [Scope](https://github.com/jun-Sogang/CSE-Sogang-University/blob/master/Javascript/javascript.md#1-scope-)
2. [Closure](https://github.com/jun-Sogang/CSE-Sogang-University/blob/master/Javascript/javascript.md#2-closure-)

---

#### 1. Scope <a id = "Scope"></a>
* The scope of a program variable is the range of statement in which the variable is visible
* A variable is visible in a statement if it can be referenced in that statement
* The scope rules of a language determine how references to names are associated with variables

***ex 1) javascript의 scope는 함수단위***
```
function scopeTest() {  
    var a = 0;
    if (true) {
        var b = 0;
        for (var c = 0; c < 5; c++) {
            console.log("c=" + c);
         }
         console.log("c=" + c);
    }
    console.log("b=" + b);
}
scopeTest();  
```

***ex 2) 변수 명의 중복***
```
var scope = 10;  
function scopeExam(){  
    var scope = 20;
    console.log("scope = " +scope);
}
scopeExam();  
```

***ex 3) var keyword 생략***
```
function scopeExam(){  
    scope = 20;
    console.log("scope = " +scope);
}

function scopeExam2(){  
    console.log("scope = " + scope);
}
scopeExam();  
scopeExam2();  
```

***ex 4) hoisting 1***
```
function hoistingExam(){  
    console.log("value="+value);
    var value =10;
    console.log("value="+value);
}
hoistingExam();
```
***ex 5) hoisting 2***
```
var value=30;  
function hoistingExam(){  
    console.log("value="+value);
    var value =10;
    console.log("value="+value);
}
hoistingExam();
```

---
#### 2. Closure <a id = "Closure"></a>

* Closures are functions that refer to independent (free) variables. In other words, these functions 'remember' the environment in which they were created.
* Lifetime : the period of time beginning when the procedure is entered and ending when execution of the procedure reaches the end

***ex 1)***
```
function outerFunc(){  
    var a= 0;
    return {
        innerFunc1 : function(){
            a+=1;
            console.log("a :"+a);
        },
        innerFunc2 : function(){
            a+=2;
            console.log("a :"+a);
        }
    };
}
var out = outerFunc();  
out.innerFunc1();  
out.innerFunc2();  
out.innerFunc2();  
out.innerFunc1();
```

***ex 2)***
```
function outerFunc(){  
    var a= 0;
    return {
        innerFunc1 : function(){
            a+=1;
            console.log("a :"+a);
        },
        innerFunc2 : function(){
            a+=2;
            console.log("a :"+a);
        }
    };
}
var out = outerFunc();  
var out2 = outerFunc();  
out.innerFunc1();  
out.innerFunc2();  
out2.innerFunc1();  
out2.innerFunc2();
```
