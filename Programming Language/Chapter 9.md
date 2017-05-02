# Chaper 9
#### Subprograms
1. [Introduction](#Introduction)
2. [Fundamentals of Subprograms](#FundamentalsOfSubprograms)
3. [Design Issues for Subprograms](#DesignIssuesForSubprograms)
4. [Local Referencing Environments](#LocalReferencingEnvironments)
5. [Parameter Passing Methods](#ParameterPassingMethods)
6. [Parameters That are Subprogram Names](#ParametersThatAreSubprogramNames)
7. Overloaded Subprograms
8. Generic Subprograms
9. Design Issues for Functions
10. Accessing Nonlocal Environments
11. User-Defined Overloaded Operators
12. Coroutine

> Subprograms are the fundamental building blocks of programs and are therefore among the most important concepts in programming language design.

---
<a id = "Introduction"></a>
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

<a id = "FundamentalsOfSubprograms"></a>

#### 9.2 Fundamentals of Subprograms

1. **General Subprogram Characteristics**
* **Basic characteristics of subprograms**
  * Each subprogram has a [single entry point](https://en.wikipedia.org/wiki/Entry_point)
  * the calling program unit is suspended during the execution of the called subprogram, which implies that there is ***only one subprogram in execution at any given time***
  * controls ***always returns to the caller*** when the subprogram execution terminates
2. **Basic Definitions**
* Basic Definitions
  * ***Subprogram definition*** describes the action of the subprogram abstraction
  * ***Subprogram call*** is the explicit request that the subprogram be executed
  * a subprogram is ***active*** if, after having been called, it has begun execution but has not yet completed that execution

***Caller : OS***
```
main() {
  ...
  sub();
  ...
}
```

***Callee***
```
sub() {
  ...
}
```
While the sub is running, the main and sub are active
  * ***subprogram header*** : the first line of the definition
    * objectives
      * specified that the following syntactic unit is a subprogram definition
      * provides the name for the subprogram
      * may ***optionally*** specify a list of parameters
    * In FORTRAN,
    ```
    SUBROUTINE ADDER (parameters) is
    ```
    * In Ada,
    ```
    procedure ADDER (parameters) is
    ```
    * In C
      * C has only one kind of subprogram, the function
      * header is recognized by its context
      ```
      int a, b;
      int p (int i) {
        static int a = 0, p = 0;
        a = a+1; b = 1; p = p + 2;
        return p;
      }
      void main() {
        int i, j;
        a = p(i) + p(i);
      }
      ```
> Sing entry point : 하나로 들어가고 하나로 나감



3. **Parameters**

Means for **conveying information between caller and callee**
  * two ways that a subprogram can gain access to data
    * through ***direct access to nonlocal variables***(declared elsewhere but visible in the subprogram, or variables in the reference environment)
      * fast
    * through parameter passing
      * a parameterized computation

      The calculation is different depending on the parameter.

      ```
      int factorial (int n) {
        if (n==1) return 1;
        else return (n * factorial(n-1));
      }
      void main() {
        int i, sum = 0;
        for (int i = 1; i < 1001; i += 1) {
          sum = sum + factorial(i);
        }
      }
      ```
      * [functional side effect](https://en.wikipedia.org/wiki/Side_effect_(computer_science))
      * hard to debugging
  * In some situations, it is convenient to be able to ***transmit computations***, rather than ***data***, as parameters to subprograms
    * the name of subprogram may be used as a parameter
    * `sort(x, comparison)`
  * Formal parameters and Actual parameters
    * ***formal parameters*** : the parameters in the subprogram header
    * ***actual parameters*** : a list of parameters in subprogram call that would be bound to the formal parameters of the subprogram
    * Initialize actual parameter to formal parameter
  * Parameter Passing
    * ***Positional parameters*** : thie binding of actual parameters to formal parameters is done ***by simple position***
    * ***Keyword parameters*** : the name of formal parameter to which an actual parameter is to be bound is ***specified with actual parameter***
      * In Ada,
      ```
      SUMER (LENGTH => MY_LENGTH,
              LIST => MY_LIST,
              SUM => MY_SUM);
      ```
        * the user of the subprogram must know the names of formal parameter
        * There is a drawback that you have to know the library

  * In C++ and Ada, formal parameters can have default values
    ```
    sub(a, b, c = 0)
    ```
    * It is used if no actual parameter is passed to the formal parameter in the subprogram header
      * In Ada,
      ```
      procedure COMPUTE_PAY (
                INCOM : FLOAT ;
                EXEMPTION : INTEGER := 1 ;
                TAX_RATE : FLOAT
        )
      ```
      * The default parameter should always be ***at the end***
      ```
      sub(a, b = 0, c) {
        ...
      }
      main() {
        sub(x, y)
      }
      ```

  * the number of actual parameters in a call must match the number of formal parameters in the subprogram definition header (Exceptino : C language)
    ```
    main() {
      int i, j;
      char c;
      ...
      printf("%d %d", i, j);
      printf("%c", c);
    }
    ```

4. **Procedures and Functions**
  * ***Procedure***
    * collections of statements that define parameterized computations
    * It defines, in effect, ***new statements***
    * two ways to pass the results to caller
      * by changing **visible variables** (excluding formal parameters) : global variables
      * by changing **formal parameters** that allows the transfer of data to the caller

  * ***Functions***
    * functions are called by appearances of their names, along with the required actual parameters, in expressions (**user defined operator**)
    * the value produced by a function's execution is returned to calling code, effectively replacing the call itself
    * In Pascal,
      ```
      function power (base, exp : real) : real;
        begin
          ...
        end
      ...
      result := 3.4 * power(10.0, x)
      ```
      * In FORTRAN
        ```
        Result = 3.4 * 10.0**x
        ```
<a id = "DesignIssuesForSubprograms"></a>

#### 9.3 Design Issues for Subprograms

* Issues
  * What parameter-passing methods are used?
    * ***Pass-by-Value***
    * ***Pass-by-Result***
    * ***Pass-by-Value-Result***
    * ***Pass-by-Reference***
    * ***Pass-by-Name***
  * Are the type of the actual parameters checked against the types of the formal parameters?
  * Are local variables statically or dynamically allocated?
  * What is the referencing environment of a subprogram that has been passes as a parameter?
  * If subprograms can be passed as parameters, are the types of parameters checked in calls to the passed subprograms?
  * Can subprograms be overloaded?
  ```
  sub(char a, char b){};
  sub(int x, int y){};

  main() {
    char c, d;
    int x, y;
    sub(x,y);
  }
  ```
  * Can subprograms be generic?
  * Is either separate or independent compilation possible?

<a id = "LocalReferencingEnvironments"></a>

#### 9.4 Local Referencing Environments

* Variables that are declared inside subprograms are called ***local variables***
  * *access to local variable is usually* ***restricted*** *to the subprogram in which they are declared*
  * ***Stack-dynamic local variables***
    * bound to storage when the subprogram begins execution and unbound from storage when that execution terminates
    * Advantages
      * allows recursive subprograms
      * storage sharing
    * Disadvantages
      * cost of the time to allocate, initialize, and deallocated such variables for each call
      * indirect referencing -> slow
      * do not allow history-sensitive Procedures
  * ***Static local variables***
    * bound to storage when the program begins the execution
    * Advantages
      * allows fast referencing
      * history-sensitive Procedures
    * but, ***do not allow recursion***
  * In ALGOL 60 and its descendant languages, local variables are by default Stack-dynamic
    * In C
      ```
      adder (list, listLen)
      int list[], listLen;
      {
        static int sum = 0;
        int count;
        for (count = 0; count < listLen; count += 1) {
          sum = sum + list[count];
        }
        return sum;
      }
      ```
    * In FORTRAN 77
      * No recursion : all local variables are ***static***

<a id = "Parameter-Passing Methods"></a>

#### 9.5 Parameter-Passing Methods

the ways in which parameters are transmitted to and/or from subprograms

1. Semantics Models of Parameter Passing
  * Formal parameters are characterized by one of **three distinct semantics models**
    * in mode : formal parameters can receive data from corresponding actual parameters
    * out mode : formal parameters can transmit data to corresponding actual parameters
    * inout mode : both of them
  * two conceptual models of how data transfers take place in parameter transmission
    * actual value is physically moved to
    * an access pass (pointer) is moved
2. Implementation Models of Parameter Passing

a variety of models has been developed by language designers to guide the implementation of three basic parameter transmission modes
  * ***Pass-by-Value (call-by-value)***
    * the value of the actual parameter is used to initialize the corresponding formal parameter, which then acts as a local variable in the Subprograms
    * provides ***in-mode*** semantics
    * normally implemented by **actual data transfer**
    * the extra storage and the move operations can be costly if the parameter is a large object, such as a long array
    ```
    int p (int i[][100]) {
      ...
    }
    void main {
      int a[100][100];
      ...
      p(a);
      ...
    }
    ```
  * ***Pass-by-Result***
    * an implementation model of ***out-mode*** Parameters
      * no value is transmitted to the Subprograms
    * the corresponding formal parameter acts as a local variable, but just before control is transferred back to the caller, its value is passed back to the caller's actual parameter, which ***must be variable***
    * Problems
      * the extra storage and move operation could be problems
      * there can be an actual parameter collision
      ```
      subroutine sub(x, y) {
        x = 3;
        y = 5;
      }
      main() {
        int p1;
        sub(p1, p1);
      }
      ```
      `what is the value of p1 after return?`
      * the implementor may be able to choose between two different times to evaluate the address of the actual parameters
        ```
        int index, list[10];

        subroutine sub(a) {
            index = 5;
            a = 3;
        }
        main() {
          index = 3;
          sub(list[index]);   // index[3] or index[5] ?
        }
        ```
  * ***Pass-by-Value-Result (pass-by-copy)***
    * an implementation model for ***inout-mode*** parameters in which actual values are moved
    * the value of the actual parameter is used to initialize the corresponding formal parameter, which then acts as a local variable. At subprogram termination, the value of the formal parameter is transmitted back to the actual parameter
  * ***Pass-by-Reference***
    * a second implementation method for ***inout-mode*** parameters
    * transmits ***an access path***, usually just ***an address***, to the called subprogram
      * the actual parameter is ***shared*** with the called subprogram***
      * An alias is generated.
    * ***No copying overhead***, and ***no duplicate space***
    * Problems
      * accesses to the formal parameters will most likely be ***slower*** because of one more level of ***indirect addressing***
      * inadvertent and erroneous change may be made to the actual parameter
      * aliases can be created
      ```
      procedure bigsub ;
        var global : integer;
          procedure smallsub (var local : integer) ;
            begin
              global = 3; local = 5;
            end
          begin
            smallsub(global);
          end
      ```

      ```
      procedure sub(var first, second : integer)
      ...
      call sub(total, total);
      ...
      ```
  * ***Pass-by-Name***
    * an **inout-mode** parameter transmission method
    * the actual parameter is, in effect, ***textually substituted*** for the corresponding formal parameter in all its occurrences in the subprogram
    * a pass-by-name formal parameter is bound to access method at the time of the subprogram call, but the actual binding to a value or an address is delayed until the formal parameter is assigned or referenced ***(late binding)***
    * the form of the actual parameter dictates the implementation method of pass-by-name parameters
      * passing variable -> Pass-by-Reference
      * passing constant -> Pass-by-Value
      * passing array element -> the value of array element (expression) can change with each reference to the formal parameter
      ```
      procedure BIGSUB ;
        integer GLOBAL ;
        integer array LIST[1 : 2] ;
        procedure SUB (PARM) ;
          int PARAM ;
          begin
            PARAM := 3;
            GLOBAL := GLOBAL + 1;
            PARAM := 5;
          end ;
        begin
          LIST[1] := 2;
          LIST[2] := 2;
          GLOBAL := 1;
          SUB(LIST[GLOBAL]) ;
        end;
      ```
    * Jesen's Devices (Single procedure can be used for a variety of purposes)
      * passing an expression and one or more variables that appear in that expression as parameters to subprogram
      * whenever one of the variable from parameters is changed in the subprogram, that change can cause a change of the values of later occurrences of the formal parameter that corresponds to the expression actual parameter
      ```
      real procedure SUM (ADDER, INDEX, LENGTH) ;
        real ADDER ;
        integer INDEX, LENGTH ;
        begin
          real TEMPSUM ;
          TEMPSUM := 0.0 ;
          for INDEX := 1 step 1 until LENGTH DO
            TEMPSUM := TEMPSUM + ADDER ;
          SUM := TEMPSUM ;
        end ;
      ```
      * `100*A`
        ```
        SUM (A, I, 100)
          for I := 1 step 1 until 100 do
            TEMPSUM := TEMPSUM + A;
        ```
      * Interchanging the values of two given actual parameters (swapping)
        ```
        procedure swap (FIRST, SECOND)
          integer FIRST, SECOND ;
          begin
            integer TEMP ;
            TEMP := FIRST ;
            FIRST := SECOND ;
            SECOND := TEMP ;
          end
        ```
      * OK !
        ```
        swap(KK, II) ;
          TEMP = KK ;
          KK = II ;
          II = TEMP ;
        ```
      * OK ?
        ```
        swap(I, A[I]) ;
          TEMP := I ;
          I := A[I] ;
          A[I] = TEMP ;
        ```
        `A[A[I]] = TEMP`
    * Pass-by-Name provides ***great flexibility***, but ***slow process*** and ***difficult to implement*** and confuse both reader and writers of the program
      * Create an address every time you reference it
3. Parameter-Passing Methods of the Major Languages
  * C
    * Pass-by-Value
    * Pass-by-Reference is achieved by using pointers as parameters
  * C++
    * A special pointer type called reference type for Pass-by-Reference
  * Java
    * All parameters are passed are passed by value
    * Object parameters are passed by reference
  * Fortran 95+
    * Parameters can be declared to be in, out, or inout mode
  * C#
    * Default method: Pass-by-Value
      * Pass-by-Reference is specified by preceding both a formal parameter and its actual parameter with ref
  * PHP
    * very similar to C#, except that either the actual or the formal parameter can specify ref
  * Perl
    * all actual parameters are implicitly placed in a predefined array named
  * Python use pass-by-assignment (al data values are objects); the actual is assigned to the formal
  * Pascal and Modula-2
    * default parameter-passing method is pass-by-value, and pass-by-reference can be specified by prefacing formal parameters with the reserved word var
    ```
    procedure adder (var a : integer ; // call-by-reference
                         b : integer ; // call-by-value
                     var c : real)   ; // call-by-reference
    ```
  * Ada
    ```
    procedure ADDER (A : in out INTEGER ;
                     B : in INTEGER ;
                     C : in out FLOAT)  is
    ```
    * out : can be assigned, but not referenced
    * in : can be referenced, but not assigned
    * in out : both
  * Python
    ```
    def spam[eggs];
      eggs.append(1)
      eggs = [2, 3];
    ham = [0];
    spam(ham);
    printf(ham);
    ```
    eggs은 [0]을 가르키다가 새로 할당되면 새로운 [2, 3]을 가르킨다

    `result : [2, 3]`
    * uses a mechanism, which is known as "Call-by-Object", sometimes also called "Call by Object Reference" or "Call by Sharing"
    * If you pass immutable arguments like integers, strings, or tuples to a function, the passing acts like call-by-value
    * The object reference is passed to the function parameters
      * They can't be changed within the function, because they can't be changed at all
      * It's different, if we pass mutable arguments. They are also passed by object reference, but they can be changed in place in the function.
        * If we pass a list to a function, we have to consider two cases:
          * Elements of a list can be changed in place : the list will be changed even in the caller's scope
          * If a new list is assigned to the name, the old list will not be affected : the list in the caller's scope will remain untouched

          `Example 1`
          ```
          def ref_demo(x):
            print "x=", x, " id=", id(x)
            x = 42
            print "x=", x, " id=", id(x)
          ```
          ```
          >>> x = 9
          >>> id(x)
          41902552
          >>> ref_demo(x)
          x = 9 id = 41902552
          x = 42 id = 41903752
          >>> id(x)
          >>> 41902552
          >>>
          ```

          `Example 2`
          ```
          >>> def func1(list):
          ...   print list
          ...   list = [47, 11]
          ...   print list
          ...
          >>> fib = [0, 1, 1, 2, 3, 5, 8]
          >>> func1(fib)
          [0, 1, 1, 2, 3, 5, 8]
          [47, 11]
          >>> print fib
          [0, 1, 1, 2, 3, 5, 8]
          ```

          `Example 3`
          ```
          >>> def func2(list):
          ...    print list
          ...    list += [47, 11]
          ...    print list
          ...
          >>> fib = [0, 1, 1, 2, 3, 5, 8]
          >>> func2(fib)
          [0, 1, 1, 2, 3, 5, 8]
          [0, 1, 1, 2, 3, 5, 8, 47, 11]
          >>> print fib
          [0, 1, 1, 2, 3, 5, 8, 47, 11]
          ```
          * Variable Length Arguments
            * The asterisk "\*" is used in Python to defined a variable number of arguments. The asterisk character has to precede a variable identifier in the parameter list.

            `Example 1`
            ```
            >>> def varpafu(*x): print(x)
            ...
            >>> varpafu()
            ()
            >>> varpafu(34, "Do you like Python?", "Of course")
            (34, 'Do you like Python?', 'Of course')
            >>>
            ```

            `Example 2`
            ```
            >>> def arithmetic_mean(x, *l):
            ...    sum = x
            ...    for i in l:
            ...      sum += i
            ...
            ...    return sum / (1.0 + len(l))
            >>> arithmetic_mean(4, 7, 9)
            6.66666666666667
            >>> arithmetic_mean(4, 7, 9, 45, -3, 7, 99)
            26.7166666666667
            ```

  4. **Type-Checking Parameters**
  * It is now widely accepted that software reliability demands that ***the types of actual parameters be checked for consistency with the corresponding formal parameters***
    * FORTRAN 77 : no parameter type checking
    * Pascal, Modula-2, FORTRAN 90 : parameter type checking
    * Original C : neither the number of parameters nor their types were checking
    * ANSI C : the formal parameters of functions can be declared two ways
      * the same way as original C : no type checking
      ```
      double sin(x) double x ; { ... }
      double value ;
      int count ;
      ...
      value = sin(count);
      ```
      * prototype method : (***type checking*** and ***coercion***)
        * coercion is used to match the types, or syntax error is reported
        ```
        double sin(double x) ; { ... }
        ...
        value = sin(count) ;
        ```
    * C++
      * the formal parameter list can have both typed parameters and ellipsis

        `printf(const char*, ...);` : at least one parameter (a char pointer)
      * Relatively new languages Perl, JavaScript, and PHP do not require type checking. In Python and Ruby, variables do not have types (objects do), so parameter type checking is not possible

  5. **Design Considerations**
  * Design considerations
    * efficiency
    * **one way or two-way data transfer** is desired
      * SE principles dictate that access by subprogram code to data outside the subprogram be minimized (in-mode only)
      * It is better to change the execution result with return

<a id = "ParametersThatAreSubprogramNames"></a>

#### 9.6 Parameters That are Subprogram Names
subprogram names are sent as ***parameters*** to other subprograms
* The description of the subprogram's parameters must be sent, along with the subprogram name (for ***type checking***)
  * In ALGOL 68 and later version of Pascal
  ```
  procedure integrate (function fun (x : real) : real ;
                       lowerbd, upperbd, real ) ;
        var funval : real ;
        begin
          ...
          funval := fun(lowerbd);
          ...
        end ;
  )
  ```
  ```
  call integrate (sub1(), 5.0, 10.0) ;
  ```
  ```
  sub1(x : real) { return x*x ;}
  ```
  ```
  sub2(x : real) { return 2*x ;}
  ```

* What is the correct referencing environment for executing the passed subprogram ?
  * ***shallow binding*** : the environment of subprogram that calls the passed Subprograms (SUB4) (result : x=4)
    * in dynamically scoped languages (ex. SNOBOL)
  * ***deep binding*** : the environment of subprogram in which the passed subprogram is declared (SUB1) (result : x=1)
    * in block structured languages (ex. Pascal)
  * ***others*** : the environment of subprogram that includes the call statement that passed the subprogram as an actual parameter (SUB3) (result : x=3)
    ```
    procedure SUB1 ;
      var x : integer ;
      procedure SUB2 ;
        begin
          write ('x=', x);
        end ; {of SUB2}
      procedure SUB3 ;
        var x : integer ;
        begin
          x := 3 ; SUB4(SUB2) ;
        end ; {of SUB3}
      procedure SUB4(SUBX) ;
        var x : integer ;
        begin
          x := 4; SUBX
        end ; {of SUB4}
    begin {of SUB1}
      x := 1 ; SUB3;
    end ; {of SUB1}
    ```
    `SUB1- > SUB3 -> SUB4 -> SUB2`
