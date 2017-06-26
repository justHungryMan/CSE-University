# Chapter 10  
#### Implementing Subprograms  
1. [The General Semantics of Calls and Returns](#)
2. [Implementing "Simple" Subprogram](#)
3. [Implementing Subprograms with Stack-Dynamic Local Variables](#)
4. [Blocks](#)
5. [Implementing Dynamic Scoping](#)

>_The purpose of this chapter is to explore methods for implementing subprograms in the major imperative languages. The discussion will provide the reader with some insight into how such language **works?**_   
 *The increased difficulty of implementing is caused by the need to include support for recursion and for mechanisms to **access nonlocal variables***


#### 10.1 The General Semantics of Calls and Returns  
* _Subprogram linkage_
  * the subprogram call and return operations of a language are together called its subprogram linkage
  * Any implementation method for subprograms must be based on the semantics of subprogram linkage  
* _The actions associated with **subprogram call**_
  * includes parameter passing mechanism
  * causes storage to be allocated for local variables and bind those variables to that storage
  * save the execution status of calling program unit
  * cause some mechanism to be created to provide access to nonlocal variables
* *The actions associated with **subprogram return***
  * if the subprogram has parameters that are out mode and are implemented by copy, the first action of the return process is to move local values of the associated formal parameters to the actual parameters
    * how about by-reference or by-copy?
  * deallocate the storage used for local variables
  * return the mechanism used for nonlocal references
  * control must be returned to the calling program unit

#### 10.2 Implementing "Simple" Subprograms
* Subprograms in early version of FORTRAN
  * subprograms can not be recursive
  * All referencing of nonlocal variables in FORTRAN 77 is through COMMON
  * variables declared in subprograms are statically allocated
* The semantics of a FORTRAN 77 *subprogram call*
  * Save the execution status of the current program unit
  * Carry out the parameter-passing process  
  * Pass the return address to the callee  
  * Transfer control to the callee  
* The semantics of a FORTRAN 77 _subprogram return_  
  * If pass-by-value-result parameters are used, the current values of those parameters are moved to the corresponding actual parameters  
  * If the subprogram is a function, the function value is moved to  a place accessible to the caller  
  * The execution status of caller is restored  
  * Control is transferred back to the caller  
* The call and return actions requires _storage_ for the following:  
  * Status information about the caller
  * Parameters  
  * Return address  
  * Function value for function subprograms  
* A FORTRAN 77 subprogram consists of two parts each of which is fixed size:
  * the local variables and data areas for call/return actions  
    * the noncode part of a subprogram is associated with a particular execution, or activation, of subprogram, and is therefore called an activation record  
    * because FORTRAN 77 does not support recursion, there can be _only one active version of subprogram a given subprogram at a tiem_  
      * there can only _a single **instance** of the activation record_ for a subprogram, and _can be statically allocated_
        * instance :  int i, j, k (i, j, k 는 다른 용도로 씀, 각각이 instance)
* Code and activation records of a FORTRAN 77 program  
  * They are allocated before execution
  * Linking

| Data |     COMMON Storage     |       for nonlocal references      |
|:----:|:----------------------:|:----------------------------------:|
|      |     Local variables    |                Main                |
|      |     Return address     | Activation Record for Subprogram A |
|      |     Local variables    |                                    |
|      |       Parameters       |                                    |
|      |     Return address     | Activation Record for Subprogram B |
|      |     Local variables    |                                    |
|      |       Parameters       |                                    |
| Code |     Codes for Main          | Code |                                    |
|      | Codes for Subprogram A |                                    |
|      | Codes for Subprogram B |                                    |

#### 10.3 Implementing Subprograms with Stack-Dynamic Local Variables  
1. More Complex Activation Records  
    * Subprogram linkage in ALGOL-like languages is more complex than the linkage of FORTRAN 77 subprograms for the following reasons:  
      * Parameters are usually passed by two different methods  
        * For example, in Modular-2, they are passed by value or reference  
      * Variables declared in subprograms are often dynamically allocated  
      * _Recursion_ adds the possibility of _multiple simultaneous activations of subprogram_  
        * requires _multiple instances of activation records_  
        * each activation requires its own copy of the formal parameters and the dynamically allocated local variables, along with the return address  
      * ALGOL-like languages use _static scoping_ to provide access to nonlocal variables. Support for these nonlocal accesses must be part of the linkage mechanism  
      * 
