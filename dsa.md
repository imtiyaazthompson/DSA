# Data Structures and Algorithms

## Data Structures
+ Data representation methods for organizing data
+ Arrays, linked lists, Trees

## Algorithms
+ Procedure that contains steps for performing a given task
+ When implementing an algorithm, a particular data structure must be used
+ Develop alg for various operations on data Structures
  + Searching, sorting, traveral etc.
+ Many different algorithms can be used to solve a particular problem.
+ Develop and find the most effecient algorithm to solve a problem
+ Effeciency of an alg is dependent on
  + running time
  + memory


## Measuring the running time of an algorithm

### Analytical method
+ Analyze alg base on input size (asymptotic analysis)
+ Independent of software and hardware
+ Allows the  consideration of all possible inputs

## Asymptotic Analysis
+ `input size (n)` <-- `running time`
+ The running time of the algorithm depends on the size of input
+ The input size `n` can mean different things depending on the problem that is being solved
+ Algorithm will run faster on a smaller input size as compared to a big input size
+ Running time of an algorithm is directly proportional to the input size
+ An algorithm is considered inefficient  if the running time increases rapidly with the input size
+ The exact running time is not of importance in asymptotic analysis

## Big O Notation
+ Asymptotic behaviour of a function is described as how fast a function `f(n)`
grows as `n` becomes large
```
  f(n) is O(g(n)) if there exists constants c and n0 s.t.

  f(n) <= cg(n) for all n >= n0
```
+ `f` will not grow faster than the function `g` for larger values of `n`
+ `g` is an upperbound on function `f`
+ `f` is the function whose rate of growth has to be examined
+ `g` is the function whose rate of growth is known

+ Examples
```

  Suppose f(n) = 5n + 4

          g(n) = n

          Is f(n) = O(g(n))?

  f(n) = 5n + 4 = O(g(n)) iff. there exists some constants c and n0
  s.t f(n) <= cg(n)

  Therefore,

  5n + 4 <= cn, for all n >= n0

  Let c = 6 (by inspection) then the following holds,

  5n + 4 <= 6n, however, this only holds for all n >= 4.

  Since there exists constants c and n0 in this case
  => 5n + 4 is O(n)

```
+ The constant are not unique
+ Another Example

```

  Suppose f(n) = 23n + 57, g(n) = n, is f(n) = O(g(n))?

  There must exist c and n0 s.t

  f(n) <= g(n) for all n > n0

  23n + 57 <= cn

  then,

  23n + 57 <= 80n for all n >= 1

  hence f(n) is O(g(n))

```
+ Another example
```

  Suppose f(n) = 3n^2 + 4n + 7
          g(n) = n^2

          is f(n) <= cg(n) for all n >= 0?

          3n^2 + 4n + 7 <= cn^2

          c = 14, n0 = 1


          Therefore, 3n^2 + 4n + 7 is O(n^2)
```

## Finding Big O
```

  Suppose f(n) = 3n^2 + 4n + 15

  To find the order of the above function, find a function g such that
  f(n) is O(g(n))

  if n = 10, f(n) = 300 + 40 + 15 = 355

  Contribution of 3n^2 to answer:
    300/355 = 84.50%
  Contribution of 4n to answer:
    40/355 = 11.26%
  Contribution of 15 to answer:
    15/355 = 4.22%


```
+ For increasing values of `n` (input size) the contribution to `f(n)` of the term with the highest power in `f(n)` tends to 100%
+ Term with the highest power dominates the value of the function
+ Smaller power terms and constants become insignificant
`Fastest growing term becomes dominant, whereas the lower terms and constants become insignificant`
+ Keep the fastest growing term to find big O of the function, discard insignificant terms
+ Ignore coefficients
+ If `f(n) = c` is constant, then `f(n)` is  `O(1)`
+ Base logarithms are unimportant
```
  O(logn) for log_2_n and log_10_n
```

## Big O analysis of Algorithms
+ Express the running time as a function of input size `n`
+ Let `T(n)` represent the time in terms of `n`
+ Find big O for function `T(n)`
```

  Given the running time T(n) of 4 algorithms
  (i) 6n^3 + logn + 2n

  (ii) 5n + n^2 + 4

  (iii) logn + 5n + 10

  (iv) 3n^2 + 15

  Compare the running times of the above algorithms

  Find big O
  (i) O(n^3)

  (ii) O(n^2)

  (iii) O(n)

  (iv) O(n^2)

  The algorithm (iii) is the best because its rate of growth is the least as compared with the other algorithms for increasing input sizes of n
```

## Calculating time complexity
+ Running time is proportional to the number of primitive operations executed during running time
  + comparisons
  + arithmetic operations
  + assignments
  + I/O
+ To find a function `T` (running time), express the number of primitive operations executed during run time, in terms of `n`
+ Given
```

  someAlg(int n) {
    input                 c1
    assignment            c2

    for (i=0;i<n;i++) {
      comparison          c3
    }

    arithmetic operation  c4
  }

```
+ Each of the operations in the above algorithm will take a certain amount of time depending on the computer that is running the algorithm
+ The times for each operation is given as `ci`
+ To calculate the total running time of the algorithm, add the time taken by all the operations
+ Also find out the number of times each operation is executed
```

  T(n) = c1 + c2 + nc3 + c4

```
+  Take note that the comparison is executed `n` times since it is enclosed in a `for-loop` block
+ To find big O
```

  therefore T(n) is O(n), [T(n) is order of n]

```
+ This method of analysis is independent of the hardware running the algorithm
+ More examples
+ The key is to only focus on operations that are dependent on the input size `n`
+ Remembering to also ignore insignificant terms, such as constants
```

  someAlg(int n) {
    assignment                    c1

    for(i=n-2;i>=1;i--) {
      arithmetic operation        c2
    }

    output                        c3

    for(i=0;i<n;i++) {
      comparison                  c4
    }

    for(i=0;i<6;i++) {
      assignment                  c5
    }
  }


  T(n) = c1 + c2(n-2) + c3 + nc4 + 6c5

  but, for operations only dependent on n

  T(n) = c2(n-2) + nc4

  then

  T(n) = n - 2 + n
       = 2n - 2

  therefore T(n) is O(n)
```
+ Another example
```

  someAlg(int n) {
    input                       c1

    for(i=n;i>=1;i-=4) {
      arithmetic operation      c2
    }

    output                      c3
  }


  Ignore the i/o operations since they are not dependent on the input size

  The arithmetic operation is executed n/4 times
  therefore T(n) is O(n)
```
+ Another example
```

  someAlg(int n) {
    input                     c1

    for(i=1;i<=n;i+=5) {
      comparison              c2
    }

    output                    c3
  }


  Ignore the i/o operations since they are not dependent on the input size

  The comparison operation is executed n/5 times
  therefore T(n) is O(n)
```
+ Another example
```

  someAlg(int n) {
    assignment                c1

    for(i=n-1;i>=1;i/=2) {
      arithmetic operation    c2
    }

    output                    c3
  }

  Ignore the assignment and output operations since they are not dependent on n
  Here the value of i is divided by 2 for every iteration so

  if n = 51

  iteration         i
  ------------------------------
  1                 50
  2                 25
  3                 12
  4                 6
  5                 3
  6                 1
                    0

  Such a pattern gives rise to T(n) = ceil(log_(2)_n) ; [log of base 2 n]

  Then T(n) is O(logn)
```
+ Another example
```

  someAlg(int n) {
    assignment                  c1

    for(i=1;i<n;i*=2) {
      arithmetic operation      c2
    }

    output                      c3
  }


  Ignore c1 and c2
  Here the value of i is doubled every iterations

  if n = 51

  iteration         i
  ------------------------------
    1               1
    2               2
    3               4
    4               8
    5               16
    6               32
    7               64 (break)

    This also gives rise to T(n) = ceil(log_(2)_n)
    therefore T(n) is O(logn)
```
+ Examples with nested loops
```

  someAlg(int n) {
    input

    for(i=0;i<n;i++) {
      assignment
      for(j=0;j<n;j++) {
        comparison
      }
    }

    arithmetic operation
    output
  }


  The assignment in the outer loop will be executed n times
  For every iteration of the outer loop, the comparison in the outer loop is executed n times => the comparison operation is executed n*n = n^2 times and

  T(n) = n^2 + n

  therefore T(n) is O(n^2)
```
+ Another Example
```

  someAlg(int n) {
    input

    for(k=0;k<n;k++) {
      for(i=n-1;i>=1;i/=2) {
        arithmetic operation
      }

      for(j=0;j<n;j++) {
        comparison
      }
    }

    arithmetic operation
    output
  }


  The arithmetic operation occurs nlogn times since it is executed logn times for each iteration of the outer loop

  The comparison operation is executed n^2 times

  therfore T(n) = nlogn + n^2 and T(n) is O(n^2)
```
+ Another example
```

  someAlg(int n) {
    input

    for(i=0;i<n;i++) {
      for(j=0;j<n;j++) {
        for(k=0;k<n;k++) {
          comparison
        }
      }
    }

    arithmetic operation

    for(i=0;j<n;j++) {
      for(j=10;j>=1;j--) {
        assignment
      }
    }
  }

  The comparison operation is executed n times in the 3rd level loop for every n times in the 2nd level loop, which in turn is executed every n times in the 1st level loop, this n^3 times

  The assignment operation is executed 10 times for every n times of the outer loops, thus 10n times

  therefore T(n) = n^3 + 10n and T(n) is O(n^3)
```
+ Examples of nested loops in which iterations of the inner loop are dependent on the index of the outer loop
+ One cannot simply just multiply the iterations across loop levels
+ TBC

# Linked Lists
| Linked Lists             | Arrays               |
| :------------------------| :--------------------|
| Dyanmically Allocated    | Statically allocated |
| Size can vary at RT      | Size cannot vary     |

+ For arrays,
  + If data < array_size => memory waste
  + if data > array_size => buffer overflow
+ There is no memory wastage when using linked lists

## Single Linked Lists
+ `[ INFO | LINK ]`
+ The `INFO` contains the actual data that is to be stored in a list
+ The `Link` contains the address of the next node in the list
```

  [ START | 450 ] - [ 10(&450) | 600 ] - [ 23(600) | 250 ] - [43(250) | END ]

```
+ All the elements of the list can be accessed using the `START` pointer
+ Nodes of a linked lists are not stored in contiguous memory locations, whereas for arrays, each element is stored within contiguous memory locations
+ Since nodes are allocated during runtime for a LL and during compile time for an array

## Implementation of a SLL
+ Structure
```c

  struct node {
    type_1 var_1;
    type_2 var_2;

    . . .

    struct node *link;

  }

```
+ Using a `self-referential` structure, which is a structure that contains a pointer member that can point to a structure of the same type
+ `link` is a pointer that will point to the next node in the list and will contain the address of that node
+ Example
```c

  struct node {
    int x;
    struct node *next;
  }


  [ x | next ] ->


  struct node {
    char name[10];
    int id;
    float marks;

    struct node *next;
  }

  [ (name | id | marks) | next ] ->
```

## Implementing a LL
+ First requirement
```c

  struct node *start = NULL;

```
+ Indicates that the list is initially empty
```c

  #include <stdio.h>
  #include <stdlib.h>

  // Node structure
  struct node {
  	int data;
  	struct node *next;
  };

  int main() {

  	struct node *start = NULL;
  	printf("Address of start: 0x%x", &start);

  }

```

## Traversing a SLL
```

[ START | -]-> [ 10 | -]-> [ 20 | -]-> [ 30 | -]-> [ 40 | -]-> [ 50 | END ]

```
### Moving a pointer forward
+ If some pointer `p` is pointing to `[ 30 | -]->` i.e. pointer `p` contains the address of that specific node in the linked list
+ Then to move the pointer forward, and have it point to `[ 40 | -]->`
+ `p = p->link` since `p->link` contains the address for the next node in the list

### Traversal
+ Always start from the first node `p = start;`, `p` now contains the address of the starting node in the list
+ We can access the actual data a node possesses `p->info;`
+ To move to the next node in the list `p = p->link;`
+ When on the last node, `p = p->link` sets the value of `p` to `NULL`
+ Therefore the terminating condition for traversing a linked list is when, `p = NULL`
```c

  p = start;
  while (p != NULL) {
    printf("%d ", p->info);
    p = p->link;
  }

```
+ The number of nodes in the list can be counted using another variable in a similar loop as above
+ Searching for a specific element `x` in the list
```c

  int pos = 1;
  p = start;
  while (p != NULL) {
    if (p->info == x) {
      break;
    }

    pos++;
    p = p->link;
  }

```

## Finding pointers in a LL
### Finding a pointer to the last node
```c

  p = start;
  while (p->link != NULL) {
    p = p->link;
  }

```
+ The above traversal breaks when `p` is pointing to the last node, since `p->link` points to `NULL` on the last node

### Finding a pointer to the second last node
```c

  p = start;
  while (p->link->link != NULL) {
    p = p->link
  }

```
+ This traversal looks ahead by 1 node where `p->link->link` refers to to the node ahead of the current node `p` points to
+ if `k = p->link` then `k->link` == `p->link->link`

### Finding a pointer to a node with a particular info
+ if `x = 30`
```c

  p = start;
  while (p != NULL) {
    // In case x = 30 is not present
    if (p->info == x) {
      break;
    }

    p = p->link
  }

```

### Finding a pointer to a predecessor of a node with particular INFO
+ Find the node that is before a the node with `x = 30`
```c

  p = start;
  while (p->link != NULL) {
    if (p->link->info == x) {
      break;
    }
  }

  p = p->link;

```
+ If we need to find a node before another node with `info: x = 30`
+ Then if we iterate through the list and from the current node `p`, its `link` to the next node is a `pointer (address)` which we can access the `info` member from
+ if that `info` member happens to be the value we need to stop at then we break out of the list traversal and we get the predecessor node of the node with value `x = 30`

### Finding a pointer to a node at a particular position
+ Find a node at position `k = 3`
```c

  p = start;
  for(int i = 1; i < k && p != NULL; i++) {
    p = p->link;
  }

```

## Insertion into a LL
### Standard procedure
+ Declare a temporary pointer of `struct node`
+ Allocate it size equivalent to `struct node` then cast to `struct node *`
+ Initialize the `info` member of the node
```c

  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->info = data;

```

### Insertion in the beginning
+ Follow standard procedure for `temp` node
+ Link the `temp` node to the `first` node in the list
+ Then `decouple` the `start` pointer from the first node, and link it to the `temp` node
```c

  temp->link = start;
  start = temp;

```
+ `temp->link = start`, will link the `temp` node to the `first` node in the list since `start` contains the address of the `first` node
+ `start = temp` now makes the `start` pointer contain the address of the new first node `temp`

### Insertion into an empty list
+ `start` node is initially `NULL`, that is, the `start` node is pointing to nothing
+ Set `temp->link = NULL;` or `temp->link = start` since it is the first element being added to an empty list and `start` is initially `NULL`
+ Then `start = temp;`

### Insertion at the end
+ Require a pointer that will point to the last element in the list
+ Requires iteration of the list till the last element
```c

  p = start;
  while(p->link != NULL) {
    p = p->link;
  }

```
+ Setting some pointer `p` to `start` allows us to always keep the `start` pointer safe and use an iteration pointer.
+ Since `p = start;` means that pointer `p` now also contains the address of the first element in the list
+ Then we iterate through the list with the iteration pointer `p`
+ Iteration is stopped when `p->link == NULL`
+ Then `p->link = temp` will an element to the end of the list

### Insertion between 2 nodes
+ Iterate to the node that you will insert after it, but before another node (between) using an iteration pointer
+ Point `temp->link` node containing new data to `p->link`
+ Then point `p` to `temp`
```

  p->[ x | link-]->[ y | link-]-> . . .

  [ temp | link-]->

  p->[ x | link-]->[ y | link-]-> . . .
                     ^
                     |
           [ temp | link]

  p->[ x | link-] [ y | link-]-> . . .
            |           /
            |          |
          [ temp | link ]


  p->[ x | link-]->[ temp | link-]->[ y | link-]-> . . .
```

```c

  temp->link = p->link;
  p->link = temp;

```

## Deleting elements from a list
### Deletion of the first node
+ Link a `temp` node to the first node in the list using `temp = start;` since `start` contains the address of the first node in the list
+ Link the `start` node to the `second` node in the list by letting `start = temp->link`
+ Free the `temp` node
```c

  temp = start;
  start = start->link;
  free(temp);

```

### Deletion of the only node
```c

  temp = start;
  start = NULL; or start = start->link;
  free(temp);

```
+ `start = start->link` is the same as `start = NULL;` since `start->link` points to `NULL` for only one element in the list

### Deletion in between the list of nodes
+ Iterate to the node `p`, just before the node that needs to be deleted
+ Link `temp` node to the node that needs to be deleted, `p->link`
+ Link `p` to the node after the node that needs to be deleted, `temp->link`
+ Free the `temp` node
```c

  temp = p->link;
  p->link temp->link;
  free(temp);

```

### Deletion at the end of the list
+ Iterate to the second last element of the list `p`
+ Link `temp` to `p->link`
+ Link `p->link` to `NULL` or `temp->link` since `temp->link` is `NULL` as it points to the last element in the list
+ Free `temp`
```

  temp = p->link;
  p->link = temp->link;
  free(temp);

```

### C and Call by Value
+ All function arguments are `passed by-value`
+ Called function is given its arguments as `temporary` variables and not as its originals
+ So simply passing a pointer as an argument to a function will not allow you to make changes to that pointer inside the function
+ The address of a pointer must be passed to the function as an argument `double pointer`
+ The `double pointer` is then dereferenced inside the calling function to manipulate it
