# Book Exchange Solver

This is an implementation of an algorithm I submitted as my solution to
HW2, Q2 of the WI21 CSE 101 course with Professor Kane. Since the answers
to the homework are already made public, I believe it is fine to release this
implementation as a public repo too.

## Problem Description:

The [original problem](https://cseweb.ucsd.edu/~dakane/CSE101/Homework2.pdf)
(credit to Professor Kane for providing the algorithm question) states the
the following:

> Chris has a long reading list this summer, but unfortunately only
has money to purchase a single book. Fortunately, he knows of a local book exchange. Each person at the book
exchange is willing to swap a copy of some particular book for a copy of some other particular book. They
are willing to make this same exchange as many times as necessary, but not all of these books are on Chris’
reading list. Chris would like to be able to purchase just a single book and then by repeatedly exchanging it
eventually get to every book on his reading list. Give an algorithm that given Chris’ reading list and a list of
potential exchanges determines whether or not this is possible to do.

In other words, given a set of possible exchanges of book X for book Y,
and a set of wanted books (that is a subset of all the books available in the exchange),
determine if there exists a "path" through all the books, starting at any
given book.

## Algorithm

**Note: [Professor Kane's solution](https://cseweb.ucsd.edu/~dakane/CSE101/Solutions2.pdf)
uses an approach that is drastically different from the one I came up with
on my own.**

### High-level description

My algorithm works as follows:

0. Represent each book as a vertex, and each possible exchange of book A for
book B as a edge from A to B on directed graph `G`
1. Compute the metagraph of `G`
2. Find the corresponding super-vertices of each book vertex. Let `SCC(v)` be
the super-vertex of `v`. Let `W` be the set of super-vertices that correspond
to a book on the wish list.
3. Topologically sort `W`. Let `V_1, V_2, ..., V_N` be the
super-vertices of `W` in this topological order.
4. For `k = N-1, N-2, ..., 2, 1`, use DFS `explore` to check if there exists
a path from `V_k` to `V_(k+1)`. If there does not, return false. To optimize,
we let the `visited` marks on each vertex persist from iteration to iteration,
so that we do not waste time duplicating a search that has already been done
(this is why we perform the searches in this reverse-order).
5. If there does exist a path from `V_k` to `V_(k+1)` for all `k`, return true.

### Time complexity

With the optimization as specified above, the time complexity of this algorithm
is `O(|V|+|E|)`, where `|V|` is the number of books and `|E|` is the number
of possible book exchanges.

To prove the time complexity is linear, we can break the algorithm down into
its steps. Step 0 is obviously linear time as we are constructing the
graph representation of the problem.

Step 1 computes the metagraph of `G`, which is linear time too using the
algorithm taught in class.

Step 2 is linear time, as we iterate through all the book vertices.

Step 3 is linear time too, since topological sorting involves performing one DFS
which is linear time.

Step 4 is linear time too, if we use the optimization explained above and do not
perform redundant `explores` on the same element - in the end, we will
only `explore` each element once (twice depending on how you count it), but
either way we perform `explore` only a linear number of times.

Step 5 is just the termination of the function, which is constant time.

### Proof of Correctness

The main thing this algorithm takes advantage of, is the fact that a single path
through all the super-vertices corresponding to books on the wish list is
possible if and only if there exists a path between every adjacent pair of
super-vertices on the "wish list", ordered topologically.

Let us prove the `if` direction. If there exists a path between every
adjacent pair of super-vertices on the "wish list", we can just stitch the paths
together to get one full path from the topologically first super-vertex
to the topologically last super-vertex on the wish list. Therefore we prove that
a single path through all the super-vertices on the wishlist is possible if
there exists a path between every topologically-adjacent pair of super-vertices
on the "wishlist".

Now let us prove the `only-if` direction. Let us say that there does exist
a full path through all the super-vertices on the wish list. Since our metagraph
is by definition a DAG, there must exist a strict topological order of the
super-vertices on the wish list. Furthermore, since our full path is a "line"
(i.e. unary tree/linked list/no branches), it follows that the topological
order is also the order in which the super-vertices are reached on the
complete path. Therefore, we can break down the complete path into subpaths,
between adjacent super-vertices in topological order (which as said earlier is
equivalent to the order they appear in on the path). It is obvious that these
subpaths must also exist as a consequence of the complete path existing.
Therefore we prove that a single path through all the super-vertices
on the wishlist is possible only if there exists a path between every
topologically-adjacent pair of super-vertices on the "wishlist".

We have proven both directions, therefore we prove the bijection correct.
Therefore we prove the critical component of our algorithm correct. QED.

## How to compile

Navigate to the root folder of the repository and type "make". An executable
`main` will be generated, along with two tests `SCCTest` and `BookExchangeTest`.

## How to use

### Input

`main` is used with the following syntax:

```
./main <filename>
```

where `<filename>` is the name of the text file encoding information for the
list of books available, the exchanges available and the wishlist. The file
should be formatted as follows:

```
<total number of books in the exchange>

<list of possible book exchanges>

<wish list of wanted books>
```

In this formatting scheme, each book is represented as a number from 0 to
`<total # of books> - 1`, inclusive. The list of possible exchanges is formatted
 as a multiple of pairs of book IDs, each pair having its own line. For instance,
 the line

 ```
 3,2
 ```

Signifies that it is possible to exchange book \#3 for book \#2. For more
examples on the input file format, refer to the testAssets/ directory.

### Output

`main` will compute the scenario given the input file, and have two
possible outputs to `stdout`. If the wishlist can be fulfilled
with the exchanges, `main` will output

```
Yes, wish list can be fulfilled with the book exchange
```

if not, `main` will output

```
No, wish list cannot be fulfilled with the book exchange
```

## Credits

Problem by [Professor Daniel Kane](https://cseweb.ucsd.edu/~dakane/)

Algorithm by Eugene Lau

Code by Eugene Lau
