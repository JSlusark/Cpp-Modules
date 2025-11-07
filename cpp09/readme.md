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

1. merge sort phase:
- we divide the list of numbers into pairs
- we order each pair from small to big
- we create 2 sub-containers: main and pending.
- pending container holds the smallest values of each pair
- main container holds the largest values of each pair
- we call this process recursively until our main container has 1 or 2 elements (base case) 

2. insertion phase:
- once our main container has 1 or 2 elements, we backtrack the recursion to binary insert the pending values into the sorted main container
- at each recursion the main container is already sorted from the previous steps
- before inserting each value from the pending container we need to calculate the Jacobsthal sequence for the pending values to determine the optimal insertion order that ensures the minimum number of comparisons/movements.

in short: Binary search handles the "where to insert" part; Jacobsthal handles the "in what order to insert" part to minimize total comparisons. It's optimized for the merge-like behavior of the algorithm


bash-5.1$ ./PmergeMe 8 6 7 9 3 1 4 5 2
[LOG] Unsorted arguments
8 6 7 9 3 1 4 5 2 

------------ START RECURSION N0------------
N0_Pairs:
[(6, 8), (7, 9), (1, 3), (4, 5)]
N0_Main chain:
[8, 9, 3, 5]
N0_Pending chain:
[6, 7, 1, 4]
N0_Remainder:2
------------ START RECURSION N1------------
N1_Pairs:
[(8, 9), (3, 5)]
N1_Main chain:
[9, 5]
N1_Pending chain:
[8, 3]
No remainder found
N1_Final Result:
[5, 9]

- generate Jacobsthal sequence for pending [8,3] has size 2.

------------ END RECURSION N1------------
N0_Final Result:
[5, 9] <- insert pending [8, 3] into main using jacobsthal sequence
------------ END RECURSION N0------------


We recurse back and have to insert pending into the sorted main values and use the jacobsthal sequence.
The Jacobsthal sequence is a list of numbers where each new number is made by adding the previous number and twice the one before that.

Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171 ...etc.

First 0 and 1 are given by default:
J(0) = 0 (given, base case).
J(1) = 1 (given, base case).

Then each next number is calculated as follows:

J(2) = J(1) + 2 * J(0) = 1 + 2*0 = 1.
J(3) = J(2) + 2 * J(1) = 1 + 2*1 = 3.
J(4) = J(3) + 2 * J(2) = 3 + 2*1 = 5.
J(5) = J(4) + 2 * J(3) = 5 + 2*3 = 11.
J(6) = J(5) + 2 * J(4) = 11 + 2*5 = 21.
J(7) = J(6) + 2 * J(5) = 21 + 2*11 = 43.
J(8) = J(7) + 2 * J(6) = 43 + 2*21 = 85.
J(9) = J(8) + 2 * J(7) = 85 + 2*43 = 171.

In practice:
J(n) = J(n-1) + 2 * J(n-2) 
for n > 1
- J(n - 1 ) is the previous number from the current iteration.
- J(n - 2) is the previous number from the previous iteration. This is multiplied by 2.






































It determine the optimal order of insertion by:
- taking the size of the pending container, which will represent how many iterations we need to perform the jacobsthal sequence.
- in each iteration we calculate the jacobsthal sequence S(n) - 1 where n is the number of iterations starting from 1
- we skip duplicate results and results >= size of pending container
- if the resulting sequence size is smaller than the pending container size, we fill in the missing indices from left to right.
Example:
For pending [8,3] with size 2:
0 → [ 0 ]
1-1=0 → [0] skip duplicte and move on
Fill in from left to right to reach size amount: [0,1]
- the jacobsthal sequence S(n) is calculated as:
  S(0) = 0
  S(1) = 1
  S(n) = S(n-1) + 2 * S(n-2) for n > 1
  Sequence: 0, 1, 1, 3, 5, 11, 21, 23,
- for every number in the jacobsthal sequence we calculate S(n) - 1 where n is the number of iterations starting from 1


 inserting "anchors" first to reduce binary search steps).










 splitting the pending container into smaller chunks and inserting them in the main container in that order.
Example:
- For pending [2,1,4,8] with size 4:
  0 → [ 0 ]
  1-1=0 → [0] skip duplicte and move on
  1-1=0 → [0] skip duplicte and move on
  3-1=2 → [0,2]
  5-1=4 → [0,2] we skip as 4 >= size 4
  Fill in from left to right to reach size amount: [0,1,2]
  This means we apply the binary search insert in the first 3 indices of pending and rest(8) uses just normal binary search insert.




3. pending [6] with main [7]
2. pending [5,9] with main [6,7] (Jacob sequence optimisation is used on 5 only as total S is 0,2?)
1. pending [2,1,4,8] with main [5,6,7,9] (Jacob sequence optimisation is used on 2,1,4 only as total S is 0,1,2 and 4 is skipped)
This is typically done via jacobsthal sequence with binary search, but also using just a normal binary search insert each value from pending into main would suffice. However this does not ensure the minimum number of comparisons/movements to insert each value from pending into main like the jacobsthal sequence does.



HOW THE SEQUENCE CLACULATION WORKS AND WHY IT SAVES COMPARISONS
Jacobstahl sequence: 0, 1, 1, 3, 5, 11, 21, ...
- We have to calculate the indexes sequence for every element in the pending container.
- This means that the resulting numbers of the sequence also have to have the same size as the pending container.
Process:
	- We always start with index 0 -> results in 0 as the first element of the sequence.
	- From 1 upwards, the result is the next S(n) - 1.
	- Duplicate result is not added to the sequence
	- If result >= size of pending we stop calculating.
	- If the resulting sequence size is smaller than the pending container size, we fill in the missing indices from left to right.
Example:
pend [2,1,4,8] with sie 4.
0 → [ 0 ]
1-1=0 → [0] skip duplicte and move on
1-1=0 → [0] skip duplicte and move on
3-1=2 → [0,2]
5-1=4 → [0,2] we skip as 4 >= size 4
Fill in from left to right to reach size amount: [0,1,2]
This means we apply the binary search insert in the first 3 indices of pending and rest(8) uses just normal binary search insert.

Jacobsthal insertions (2, 1, 4): The order inserts "anchors" first (e.g., 2 sets a left boundary), so later inserts (1, 4) reuses comparison results, reducing steps in binary search (~5-6 total for these 3 vs. ~7-8 in sequential).


Another example:
For pend [2,1,4,8,5] (Size 5)
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
This means we apply the binary search insert in all indices of pending cobtainer.

I realy hope i got it right because it's really frustrating especially as I don't remember much of advanced math
and feel so ashemed of it :(
https://github.com/leske42/CPP09