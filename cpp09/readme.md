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
Repository with amazing help/walktrhough: https://github.com/leske42/CPP09
Jacobstahl and lucas sequence: https://mathworld.wolfram.com/JacobsthalNumber.html
Containers lib: https://en.cppreference.com/w/cpp/container.html
Deque: https://en.cppreference.com/w/cpp/container/deque.html

Why std::deque is consistently slower than std::vector
1. Memory layout
std::vector is based on a single, contiguous block of memory (cache-friendly and easy).
Vector benefits because all elements sit next to each other in L1/L2 cache.
The iterator is usually a raw int*.

std::deque is not contiguos and allocated in blocks that are linked together via pointers.
Deque suffers because elements hop between memory blocks.
The iterator is a struct with multiple pointers and boundary checks (therefore more costly).
Deque is not designed for high-performance sorting but it’s designed for cheap push/pop at both ends.




