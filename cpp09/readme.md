https://winder.nom.za/ferdaws/42/Cursus/cpp09.php
https://cdn.intra.42.fr/pdf/pdf/173137/en.subject.pdf


2. ex01 use set as it only needs to store unique values
3. ex02 use vector and deque as they allow duplicates and maintain order

EX 00 - MAP - ✅ need to doublecheck things before submitting
Explanation of choice:
https://www.geeksforgeeks.org/when-to-use-map-in-cpp/
https://www.codingninjas.com/codestudio/library/when-to-use-map-in-cpp
https://www.educative.io/answers/what-are-the-advantages-of-using-map-in-cpp
https://www.geeksforgeeks.org/map-associative-container-in-cpp-stl/
https://www.cplusplus.com/reference/map/map/
Because key pair values matches csv structure, keeps data sorted and manages some error handling for us (unique keys/dates, lower_bound).
- map<date, value> ->	Stores key–value pairs efficiently.
- std::map::lower_bound() -> allows binary-search for the key and steps one iterator back to get the previous date, so that we can find the nearest date if the exact date is not present in the database.
- std::map-> Automatically keeps keys sorted lexicographically(chronologiaclly for dates), which matches YYYY-MM-DD ordering from csv.
- O(log n)	Fast for both direct and nearest-key lookups,
- each key is unique : meaning it handles error handling if for example we have duplicates no duplicate dates.
- value should be in float as bitcoin prices can have decimal values.
- input can be processed line by line and inserted into the map as we read it, making it memory efficient.



EX01 - STACK AS THE LIFO PRINCIPLE HELPS REPLICATING THE RPN CALCULATION LOGIC.
Reverse polish notation: is a mathematical notation where operators follow their operands, eliminating the need for parentheses and the confusion over operator precedence (i.e. * used before +).
It represents how arithmetic expressions are performed in many computers and calculators, in a stack-based manner.

- Expressions are evaluated from left to right, which follows a similar approach to how stacks operate with the Last In, First Out (LIFO) principle.
- stack.push() -> collects operands from the expression and stores them until they are needed for an operation.
- stack.pop() -> retrieves the most recent operands when an operator is encoutered.
- stack.top() -> useful for check the current state of the stack during evaluation.
- Last In, First Out (LIFO) principle: the LAST element added IN the stack is the FIRST one to go OUT removed.
- time complexity: simple operations are all 0(1)


EX02 -

EX02 - VECTOR AND DEQUE
Ford Johnson's Algo know also as merge-insertion sort.
Explanation of choice: https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42
https://www.youtube.com/watch?v=9pMqIA2ehtE
https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
https://en.wikipedia.org/wiki/Merge-insertion_sort#Algorithm
https://link.springer.com/article/10.1007/s00224-020-09987-4

The Ford-Johnson algorithm solves this question:
What is the minimum possible number of comparisons any comparison sort can do for n elements?
How:
- pairing to halve the number of items that need recursive sorting, and
- inserting the remaining ones in an order that keeps the list size small for as long as possible.

In short from my understanding to replicate the algorithm we have to do the following:
- we divide the list into pairs
- we then sort each vakue in pair from smallest to largest
- we create 2 sub-containers, one for the largest values of each pair and one for the smallest values of each pair
- we have to sort the biggest values first  by recursively applying the same pairing and subcontainer logic until we reach a base case of 1 or 2 elements
- we backtrack to the previous subcontainer and start inserting the smallest values into the sorted largest values container
- we use the jacobsthal sequence to determine the order in which we insert values from the smallest values subcontainer into the sorted largest values subcontainer. This can be done also just with a binary search but the jacobsthal sequence ensures a smaller number of comparisons/movements to insert each value from sub into main.
- we repeat this process until all values are sorted


Exampe list of numbers:
6,2,1,5,7,4,9,8

1. Pairing and sorting each pair:
[2,6] [1,5] [4,7] [8,9]
main [6,5,7,9]
sub [2,1,4,8]

2. new pairing and sorting of main:
[6,5] [7,9]
main [6,7]
sub [5,9]

3. new pairing and sorting of main:
[6,7]
main [7]
sub [6]

Base case reached, we recurse back to the sub values to insert them into the sorted main values:
3. sub [6] with main [7]
2. sub [5,9] with main [6,7] (Jacob sequence optimisation is used on 5 only as total S is 0,2?)
1. sub [2,1,4,8] with main [5,6,7,9] (Jacob sequence optimisation is used on 2,1,4 only as total S is 0,1,2 and 4 is skipped)
This is typically done via jacobsthal sequence with binary search, but also using just a normal binary search insert each value from sub into main would suffice. However this does not ensure the minimum number of comparisons/movements to insert each value from sub into main like the jacobsthal sequence does.
Binary search handles the "where to insert" part; Jacobsthal handles the "in what order to insert" part to minimize total comparisons. It's optimized for the merge-like behavior of the algorithm


HOW THE SEQUENCE CLACULATION WORKS AND WHY IT SAVES COMPARISONS
Jacobstahl sequence: 0, 1, 1, 3, 5, 11, 21, ...
- We have to calculate the indexes sequence for every element in the sub container.
- This means that the resulting numbers of the sequence also have to have the same size as the sub container.
Process:
	- We always start with index 0 -> results in 0 as the first element of the sequence.
	- From 1 upwards, the result is the next S(n) - 1.
	- Duplicate result is not added to the sequence
	- If result >= size of sub we stop calculating.
	- If the resulting sequence size is smaller than the sub container size, we fill in the missing indices from left to right.
Example:
Sub [2,1,4,8] with sie 4.
0 → [ 0 ]
1-1=0 → [0] skip duplicte and move on
1-1=0 → [0] skip duplicte and move on
3-1=2 → [0,2]
5-1=4 → [0,2] we skip as 4 >= size 4
Fill in from left to right to reach size amount: [0,1,2]
This means we apply the binary search insert in the first 3 indices of sub and rest(8) uses just normal binary search insert.

Jacobsthal insertions (2, 1, 4): The order inserts "anchors" first (e.g., 2 sets a left boundary), so later inserts (1, 4) reuses comparison results, reducing steps in binary search (~5-6 total for these 3 vs. ~7-8 in sequential).


Another example:
For Sub [2,1,4,8,5] (Size 5)
Raw indices: [0] (start)
1-1=0 → skip duplicate → [0]
1-1=0 → skip → [0]
3-1=2 → add → [0,2]
5-1=4 → add (4 <5, valid) → [0,2,4]
11-1=10 >=5 → stop.
Indeces reult: [0,2,4]

Fill gaps from left to right:
- Between 0 and 2: add 1 → [0,1,2,4]
- Between 2 and 4: add 3 → [0,1,2,3,4]
Final indices: [0,1,2,3,4] (matches size 5, no skips).
This means we apply the binary search insert in all indices of sub cobtainer.

I realy hope i got it right because it's really frustrating especially as I don't remember much of advanced math
and feel so ashemed of it :(
https://github.com/leske42/CPP09