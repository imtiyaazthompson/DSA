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
+
