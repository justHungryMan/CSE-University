# Javascript

This document is about the core concept of Javascript

---
## Index
1. [Scope](#Scope)
2. [Closure](#Closure)
3. [This](#This)

---

## 1. Scope <a id="Scope"></a>
* The scope of a program variable is **the range of statement in which the variable is visible**
* A variable is visible in a statement if it can be referenced in that statement
* The scope rules of a language determine **how references to names are associated with variables**

##### _Example_

* `Javascript has a function unit scope`
* `Duplicated variable names`
* `Var keyword omitted`
* `Hoisting`
* `Hoisting in duplicated variables names`

###### 1. Javascript has a function unit scope

Since javascript has a **function unit scope**, the following example is satisfied.
```javascript
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

###### result

```javascript
b = 0
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

```javascript
var a = 10;  
var example = function scopeExam(){  
    var a = 20;
    console.log("a = " +a);
}
example();  
```

###### result
```javascript
a = 20
```

###### 3. Var keyword omitted
If the var keyword is omitted, it is assumed to be a **global variable**.
```javascript
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
```javascript
a = 10
a = 10
```

###### 4. [Hoisting MDN](https://developer.mozilla.org/en-US/docs/Glossary/Hoisting)
Hoisting means that **variable and function declarations are physically moved to the top of your coding**

```javascript
var example = function hoistingExam(){  
    console.log("a = " + a);
    var a =10;
    console.log("a =" + a);
}
example();
```

###### result
```javascript
a = undefined
a = 10
```

###### 5. Hoisting in duplicated variables names
```javascript
var a = 20;  
var example = function hoistingExam(){  
    console.log("a = " + a);
    var a = 10;
    console.log("a = " + a);
}
example();
```

###### result
```javascript
a = undefined
a = 10
```
---
## 2. Closure <a id="Closure"></a>

* Closures are functions that refer to independent (free) variables. In other words, these functions **remember the environment** in which they were created.
* Lifetime : the period of time beginning when the procedure is entered and ending when execution of the procedure reaches the end
* **Accessing a variable with a lifetime terminated is called a closure.**

##### _Example_

* `Closure Example`
* `Different Closure`

###### Closure Example
```javascript
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

```javascript
a : 1
a : 3
a : 4
a : 6
```

##### Different Closure

```javascript
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
```javascript
a : 1
a : 3
a : 1
a : 3
```


## 3. This  <a id="This"></a>
My friend [jiseung](https://github.com/rohjs) has already created the material on this and this material is amazingly good. So I decided to use my friend's material.

[reference](https://github.com/rohjs/TIL/blob/master/JavaScript/javascript.md)

`this` is a property that is created automatically when a function is executed. The keyword `this` refers to **the object that invokes the very function, _not the object that defines the function_**.  
But what makes us _really_ confused is to figure out when exactly _invocation_ happens when we execute functions or methods. [This article](https://rainsoft.io/gentle-explanation-of-this-in-javascript/#2functioninvocation) well explains when the function/method invocation really happens and helped me organize the key principle of `this`.

There are mainly three types of invocation of functions.

1. Function Invocation
2. Method Invocation
3. Constructor Invocation

#### 1) Function Invocation
**Function invocation** simply means executing normal functions with parenthesis and arguments, if necessary.

```javascript
function hello(msg) {
  console.log(msg);
  return this;
}

var bye = function(msg) {
  console.log(msg);
  return this;
}

var a = hello('hello'); // a = Window Object
var b = bye('bye'); // b = Window Object
```

No matter where the function is located, whether it is inside the other function, inside method, etc, if the function is executed purely as the form of function expression, `this` inside the very function will refer to **global object**, in this case, the `Window Object`.

To give you a more clear idea, I made another example.

```javascript
var obj = {
  fruits: {
    apple: true,
    banana: false
  },
  doSomething: {
    eatFruits: function() {
      var innerFunction = function() {
        console.log(this);
      };
      innerFunction();
    }
  }
};

obj.doSomething.eatFruits();
// Window Object
```
Even though `innerFunction` is inside the `obj.doSomething.eatFruits()` method, it is executed as the _function invocation_. This is why the returned value of it is the global object, not `obj.doSomething` nor `obj`.

#### 2) Method Invocation
Method means function stored as a value of an object property. **Method invocation** is performed when an expression in a form of property accessor that evaluates to a function object is followed by parenthesis.

```javascript
var obj = {
  sayHello: function() {
    console.log('Hello');
  },
  sayBye: function() {
    console.log('Bye');
  }
};

obj.sayHello(); // Method Invocation
obj.sayBye(); // Method Invocation
```

When the function expression is called in the form of method, the owner of `this` inside the function is the _actual owner object_ of the very method.

```javascript
var obj = {
  fruits: {
    apple: true,
    banana: false
  },
  doSomething: {
    eatFruits: function() {
      console.log(this);
      // when executed, this follows method invocation rules
      // this === obj.methods
      return this.apple, this.banana;
    }
  }
};

obj.doSomething.eatFruits();
// log obj.doSomething
// Error
```

When you execute `eatFruits()` method, you might get `ReferenceError`. `this` inside the `eatFruits()` method refers to `obj.doSomething`, not 'obj' object. Since `doSomething` doesn't have `apple` or  `banana` as its property, it gets error.  

In order to fix this error:

```javascript
var obj = {
  fruits: {
    apple: true,
    banana: false
  },
  doSomething: {
    eatFruits: function() {
      console.log(this);
      // this : obj
      return this.fruits.apple;
    }
  }
};

obj.doSomething.eatFruits.bind(obj)();
// now `this` inside eatFruits() refers to obj object
```

##### Common Mistakes: Separation from its object
When method invocation is passed as a parameter of a function, it loses the connection to its antecedent. It is alike:

```javascript
var event_handlers = {
  mouseClick: function() {
    return this;
  }
};

var button = document.getElementById('btn-submit');
button.addEventListener( "click", event_handlers.mouseClick );
// this === button
// The above code is exactly same as the below

var extractFunction = event_handlers.mouseClick;
button.addEventListener( "click", extractFunction );
```

In this situation, `this` inside the method function no longer refers to its owner object. The object that invokes the very function is now `button`, so `this` now refers to `button` object.  
_Note: HTML Elements are objects._

```javascript
function foo() {
  console.log(this.a);
}
var a = 'You are in global'

var obj = {
  a: 'You are in obj context',
  foo: foo
}
var anotherObj = obj.foo
// It loses implicit binding
// Separation from obj context

obj.foo(); // You are in obj context
anotherObj(); // You are in global
```

#### 3) Constructor Invocation
**Constructor invocation** is performed when a function is used with `new` keyword in front of it. With `new`, function is executed neither in function invocation nor in method invocation, but in constructor invocation. `this` inside the constructor function refers to newly created instance.

```javascript
var Person = function(name, age) {
  this.name = name;
  this.age = age;
};

Person('jiseung', 23);
// Function Invocation (this === Window Object)
// It created a global variable name and age
console.log(name); // 'jiseung'
console.log(age); // 23

var boyoon = new Person('boyoon', 23);
console.log(boyoon.name); // 'boyoon'
console.log(boyoon.age); // 23
```
