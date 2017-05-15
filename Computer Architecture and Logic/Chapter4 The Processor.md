# Chapter 4
#### The processor
we learn about ***pipeline concepts***

1. [Three basic requirement for a processor](#Chapter1)
2. [Instruction execution cycle](#Chapter2)
3. [Grant chart](#Chapter3)
4. [Look behind & Look ahead facility](#Chapter4)

---
<a id = "Chapter1"></a>  
#### 4.1 Three basic requirement for a processor
* Three main blocks
  1. Instruction Unit : ***Instruction fetch***, ***Instruction Decode***
      * effective operand address calculation
  2. Execution unit
      * ALU
  3. Storage



<a id = "Chapter2"></a>  
#### 4.2 Instruction execution cycle
1. `Instruction fetch`
2. `Decode`
3. `Operand effective address calculation`
4. `Operand fetch`
5. `Execution`
6. `Store result`
7. `Next address calculation`

* I-fetch : 1 + 2
* I-unit : 2 + 3 + 4
* D-unit : 5


<a id = "Chapter3"></a>  
#### 4.3 Gantt chart

`Pararell 1`

|   Time  |  1 | 2  | 3  | 4  | 5  | 6  | 7  | 8  | ... |
|:-------:|:--:|----|----|----|----|----|----|----|-----|
| I-fetch | i1 |    | i2 |    | i3 |    | i4 |    | ... |
| I-unit  |    | i1 |    | i2 |    | i3 |    | i4 | ... |
| D-unit  |    |    | i1 |    | i2 |    | i3 |    | ... |

`Pararell 2`

|   Time  |  1 | 2  | 3  | 4  | 5  | 6  | 7  | 8  | ... |
|:-------:|:--:|----|----|----|----|----|----|----|-----|
| I-fetch | i1 | i2 | i3 | i4 | i5 | i6 | i7 | i8 | ... |
| I-unit  |    | i1 | i2 | i3 | i4 | i5 | i6 | i7 | ... |
| D-unit  |    |    | i1 | i2 | i3 | i4 | i5 | i6 | ... |

* Out of this rule
  1. `Dependency`
  2. `Procedure call`
  3. `Conditional statement`

<a id = "Chapter4"></a>  
#### 4.4 Look behind & Look ahead facility

Add provision for a decoded and then executed instruction to be kept in the buffer until ARM instructions following it in sequential stream
* To avoid dependency
```
"C" <-  A  + B
 E  <- "C" + 1
```

* Assume three stage pipeline
  * I-fetch, I-input, Execution
* Unavailibility of a functional unit
  * S1 : R1 <- R2 + R3     
  * S2 : R4 <- R2  *  R5    
  * S3 : R6 <- R3 + R6
>(+) : 4 units  
> ( \* ) : 10 units

  | unit |         1         |         2         |         3         | 4 | 5 | 6 |         7        | 8 |   |   |   |   |   | ... |
  |:----:|:-----------------:|:-----------------:|:-----------------:|:-:|:-:|:-:|:----------------:|:-:|:-:|:-:|:-:|:-:|:-:|:---:|
  |  S1  | Instruction Fetch |  Instruction Unit |         +         | + | + | + |                  |   |   |   |   |   |   | ... |
  |  S2  |                   | Instruction Fetch |  Instruction Unit | * | * | * |         *        | * | * | * | * | * | * | ... |
  |  S3  |                   |                   | Instruction Fetch |   |   |   | Instruction Unit | + | + | + | + |   |   | ... |

  `Waiting "+" operator`


#### 4.5 Requirements for Parallel execution of two instructions  
> S(i), S(j) : two instructions  
> I(i), I(j) : domain (inputs)  
> O(i), O(j) : range (outputs)  

* O(i) ∩ O(j) = Ø  
* O(i) ∩ I(j) = Ø  
* O(j) ∩ I(i) = Ø  
>두 개 이상의 Outputs이 동일하지 않고 Output과 Input이 다를때 Parallel execution이 가능하다.  

###### Example
```javascript
S1 : R1 <- R2 + R3
S2 : R4 <- R2 * R5
S3 : R6 <- R3 + R6
```
> O(1) = {R1}, I(1) = {R2, R3}  // instruction 조건은 맞지 않은데..?  
> O(2) = {R4}, I(2) = {R2, R5}  
> O(3) = {R6}, I(3) = {R3, R6}  

Independent (Processed same time)  
**But one by one** 으로 Dynamic Scheduling inside PC(processor)
> Processor가 Optimal하게 instruction execution 순서를 정한다.  

##### Example 안되는 경우
```javascript
S1 : R1 <- R2 + R3
S2 : R2 <- R4 * R5
```
