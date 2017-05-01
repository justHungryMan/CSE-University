# Chapter 4
#### The processor
we learn about ***pipeline concepts***

1. [Three basic requirement for a processor](https://github.com/jun-Sogang/CSE-University/blob/master/ComputerArchitectureAndLogic/Chapter4%20The%20Processor.md#41-three-basic-requirement-for-a-processor)
2. [Instruction execution cycle](https://github.com/jun-Sogang/CSE-University/blob/master/ComputerArchitectureAndLogic/Chapter4%20The%20Processor.md#42-instruction-execution-cycle)
3. [Grant chart](https://github.com/jun-Sogang/CSE-University/blob/master/ComputerArchitectureAndLogic/Chapter4%20The%20Processor.md#43-gantt-chart)
4. [Look behind & Look ahead facility](https://github.com/jun-Sogang/CSE-University/blob/master/ComputerArchitectureAndLogic/Chapter4%20The%20Processor.md#44-look-behind--look-ahead-facility)

---

#### 4.1 Three basic requirement for a processor
* Three main blocks
  1. Instruction Unit : ***Instruction fetch***, ***Instruction Decode***
      * effective operand address calculation
  2. Execution unit
      * ALU
  3. Storage

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
  * S1 : R1 <- R2 + R3    (+) 4 unit
  * S2 : R4 <- R2  *  R5    ( \* ) 10 unit
  * S3 : R6 <- R3 + R6

  | unit |         1         |         2         |         3         | 4 | 5 | 6 |         7        | 8 |   |   |   |   |   | ... |
  |:----:|:-----------------:|:-----------------:|:-----------------:|:-:|:-:|:-:|:----------------:|:-:|:-:|:-:|:-:|:-:|:-:|:---:|
  |  S1  | Instruction Fetch |  Instruction Unit |         +         | + | + | + |                  |   |   |   |   |   |   | ... |
  |  S2  |                   | Instruction Fetch |  Instruction Unit | * | * | * |         *        | * | * | * | * | * | * | ... |
  |  S3  |                   |                   | Instruction Fetch |   |   |   | Instruction Unit | + | + | + | + |   |   | ... |
  `Waiting "+" operator`
