/***                                                *
 * 1. method                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/

## Question Category

### Dynamic Programming
#### 1. 0-1 Backpack
322, 377, 474, 139, 494


字符串匹配动态规划问题：10, 44

sliding window: 30, 76

climbing stairs: 91, 70

## Notes

### 1. Search Template
1. Applicable for most searching problems;
2. When to output, when to skip;
3. Some problems: Permutations, Unique Permutations, Combination Sum, Letter Combination of a Phone Number, Palindrome Partitioning, Restore IP Address and so on;

### 2. Binary Search and Sorted Array
1. Binary Search Template (4 key points);
2. Rotated Sorted Array;
a. Find Minimum
b. Find Target
c. Why O(n) with duplicates?
3. Find Median in Two Sorted Array (Find Kth);
4. Reverse in 3 steps;
5. Reference: 二分查找有几种写法？它们的区别是什么？ - Jason Li的回答 - 知乎
https://www.zhihu.com/question/36132386/answer/530313852


### 3. Binary Tree
1. Divide and Conquer: merge sort, quick sort and most binary problems.
2. Merge sort and Quick sort.

||Time|Space|Stability|
|:-:|:-:|:-:|:-:|
|Merge Sort|O(n logn)|O(n)|Better. (1, 1), (1, 2), (1, 3)|
|Quick Sort|O(n logn)|O(1)|(1, 3), (1, 1), (1, 2)|
3. BFS and DFS.
4. 3 ways to solve binary tree problems: divide and conquer, traverse and iteration(non-recursion).
5. For Binary Search Tree, its inorder traversal is ascending.

### 4. Linked List
1. Dummy Node in Linked List.
2. Basic skills in Linked List:
- Insert a Node in Linked List;
- Remove a Node from Linked List;
- Reverse a Linked List;
- Merge two Linked List;
- Find the Middle of a Linked List.
3. Fast slow pointers:
- Find the middle of a Linked List;
- Remove N-th Node from End of List
- Linked List cycle I, II
...

### 5. Dynamic Programming
1. Recursion or DP
2. Matrix DP
3. Sequence DP
4. Bottom-Top, Top-Bottom: jiyihua sousuo
5. When to use DP:
- Maximum, Minimum
- Yes or No
- Count(*). If listing all results, not DP but recursion.
- Can not sort or swap
6. Dynamic Programming 4 steps:
- State
- Function
- Initialization
- Answer
7. Frequent Questions
- Matrix DP: 
    - state: f[x][y] is from beginning to (x, y). 
    - function: Study on previous step of (x, y).
    - initialize: 起点
    - answer: 终点
- Sequence DP: 
    - state: f[i] 表示“前i”个位置/数字/字母，(以第i个为)...
    - function: f[i] = f[j]... j是i之前一个位置
    - initialize: f[0]
    - answer: f[n-1]
- Two Sequence DP
- Backpack 

### 7. Data Structures
1. Linear Data Structure:
    - queue
    - stack
    - hash
2. Tree Data Structure:
    - heap
    - trie
3. Queue
    - push: O(1)
    - pop: O(1)
    - top: O(1)
used for BFS
4. Stack
    - push: O(1)
    - pop: O(1)
    - top: O(1)
5. Hash
    - insert: O(1)
    - delete: O(1)
    - find: O(1)
    - Hash Function

Collision
    - Open Hashing(LinkedList)
    - Closed Hashing(Array)
x. Tips
    - For binary tree, if balanced, related to O(lg n), if not, O(n^2).
