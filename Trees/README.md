Pset 6
CPSC 223
Due Date: 11:59 PM NHT on Sunday Dec 10, 2023
Introduction
In this assignment, you will devise an implementation of each of three kinds of Binary Search Trees:

A naive Binary Search Tree
An AVL Tree
A Red-Black Tree
A binary search tree has the invariant that all nodes to the left of a node are smaller in value, and all nodes to the right are larger in value.
Every AVL Tree and Red-Black Tree is a "self-balancing" binary search tree.

Why is balancing a BST important?
If a binary search tree is balanced (or close to being balanced), it has a logarithmic runtime for the following functions:

minimum_value()
maximum_value()
contains(value)
insert(value)
remove(value)
a few others
However, if the binary search tree is not balanced, the runtime for these operations could be linear in the number of nodes in the tree!

Makefiles
As with Pset 5, the makefile is given.
You may not change the makefile.
Type make to compile the code you write.
Run the program(s) with ./bst, ./avlt, or ./rbt.
Each individual executable can be compiled in isolation with make bst, make avlt, or make rbt.

Starter Code
You should not modify the driver(s) for this assignment (in files main_*.cpp).
In addition to the driver(s), you are given an extra function that can be used to print out your trees (because it's kind of a pain to write such a thing from scratch!).
Looking at the trees that print (after doing operations such as insert, remove, etc.) can be a great way to check the correctness of your code.

The Assignment
For this assignment, we provide the header files (BSTree.h, AVLTree.h, and RBTree.h) file and most of the implementations in BSTree.cpp, AVLTree.cpp, and RBTree.cpp, which call corresponding functions on the tree's root, which is a BSTNode.
You are responsible for writing many of the implementation functions in BSTNode.cpp, although we have provided you with some of the functions already.

Remember, self-balancing trees are a subset of binary search trees.
That means that your AVL Trees and Red-Black trees must maintain the binary search tree invariant that all values in the left subtree of any node are less than the node and all values in the right subtree are greater than the node.
They must additionally maintain the invariants enforcing balance, so be careful!
We have thoroughly commented the header files (interfaces), so please refer to those for specific information.

You are not allowed to change the header or functionality of the public functions.
What you can do is to add extra functions and attributes to your code to better modularize the program.
These functions and attributes are to be added only under the private section of your code in the header files or, in the case of a function that does not require you to access the tree itself, as a separate function defined only in the .cpp file.

You are responsible for implementing all or part of the following functions, within the listed time bounds:

In BSTree.cpp, AVLTree.cpp, and RBTree.cpp
The assignment operator overload in each, which must run in $O(n)$ time
In BSTNode.cpp
BSTNode::BSTNode(const BSTNode &source), the copy constructor
$O(n)$
BSTNode::~BSTNode(), the destructor
$O(n)$
const BSTNOde* BSTNode::minimum_value() const
$O([\text{height of this}])$
const BSTNode* BSTNode::maximum_value() const
$O([\text{height of this}])$
const BSTNode* BSTNode::search(int value) const
$O([\text{height of this}])$
BSTNode *BSTNode::insert(int value)
$O([\text{height of this}])$
BSTNode *BSTNOde::avl_insert(int value)
$O(\log n)$
BSTNode *BSTNode::rb_insert(int value)
$O(\log n)$
void BSTNode::remove(int value)
$O([\text{height of this}])$
void BSTNode::avl_remove(int value)
$O(\log n)$
int BSTNode::node_height() const
$O(1)$
unsigned int BSTNode::node_count() const
$O(n)$
unsigned int BSTNode::count_total() const
$O(n)$
BSTNode *BSTNode::right_rotate()
$O(1)$
BSTNode *BSTNode::left_rotate()
$O(1)$
BSTNode *BSTNode::avl_balance()
$O(1)$
BSTNode *BSTNode::rb_eliminate_red_red_violation()
$O(1)$
void BSTNode::make_locally_consistent()
$O(1)$
Note: This may seem like a lot, but observe that many of the implementations share much of their body, and even more of them have remarkably similar structure!
It's likely you will be copy-pasting significant chunks of your code, so as you do so think about ways in which you can eliminate duplicate code without copy-pasting.

The BSTNode class has members including the tree's height and color.
Not all of those fields are useful for every implementation.
For example, your naive BST and AVL tree implementations should not use the color field (you'll notice the output of the reference implementation shows every node in those trees as BLACK).
The naive BST and Red-Black tree implementations are unlikely to need the height field.

Notes about the starter code
Pre-implemented Functions
Many of the pre-implemented functions are convenience functions that might help you keep your code concise, but are not fundamental to the behavior of a binary search tree.
However, one major function that is implemented for you is rb_remove.
We encourage you to study that implementation because it is interesting, but you are not responsible for understanding the Red-Black tree deletion algorithm for this course.
Because that function is implemented for you, however, it means that the driver's output is not particularly helpful as it pertains to your own code for Red-Black trees.
You must write unit tests for your rb_insert function to ensure that it appropriately maintains the Red-Black tree invariants—the driver only displays the tree after all insertions are complete, which is not enough to guarantee the invariants always hold.

Modification Restrictions and Style
Except for the assignment operator overloads in BSTree.cpp, AVLTree.cpp, and RBTree.cpp, the only starter code file you may modify is BSTNode.cpp (or its corresponding .h file, in the case that you add private members or functions to it—in which case you may only add to it, and may not change or remove anything that is already there).
Any style violations in starter code are intentional, generally to exhibit alternate code styles.
All code that you write must conform to the style guide.

"Assumes" Clauses
Many of the functions you are required to implement have specifications that include an "Assumes" clause.
These are facts that the function body is allowed to assume are true; their behavior if that assumption is violated is undefined.
Your implementation does not need to handle any cases that violate the assumptions since we will not run unit tests that violate those things.
Instead, it is the responsibility of the caller of the function to ensure the assumption holds true.
This could be done by explicit checks, or it could be implicit (for example, the assumption by minimum_value that the tree is non-empty could be guaranteed by the fact that all paths through the calling code insert some items into the tree before calling it).
In general, explicit checks should be used sparingly, and you should strive to write code that implicitly guarantees the assumptions hold true at the point of each call.

TODO markers
Each function you are required or encouraged to implement is marked with the following line of code or similar:

C++
Copy code
#pragma message "TODO: Implement this function"
This generates a compiler message that looks like the following for each of them:

arduino
Copy code
BSTNode.cpp:134:17: note: ‘#pragma message: TODO: Implement this function’
  134 | #pragma message "TODO: Implement this function"
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Each time you implement a required function, you should remove this line from that function.
If you compile your program and there are still such notes, you are not yet done!
You must implement all functions marked with these TODO messages.

Further Reading
For interested students
When you try to make a copy of an object, the copy constructor or assignment operator overload gets called, depending on the situation.
Why? The C++ compiler only makes shallow copies automatically—all the data is copied exactly from one object to the other.
This is fine for fundamental types (int, bool, float etc.).
But pointer types are also copied to the new object (so the new object points to the same location)!
This leads to aliasing of values referred to by pointer members.
We need to make a deep copy of the object (in this case, a new BST, AVL Tree, or Red-Black tree that is identical to the original one is created at a different location in memory so any modification to one of the trees is not reflected in the others).

There is nothing magical about either a copy constructor or an assignment operator overload, but it does take some time to learn how to write them.
The structure is (almost) always the same, however, so you should be able to follow the code on the page below to write the ones for this assignment.
Read the following article if you want more information on those two operations: http://www.cplusplus.com/articles/y8hv0pDG/.

For very interested students
Deep copying can be expensive.
The C++11 standard introduced move semantics to help with this.
Move semantics transfer ownership of a value from one variable to another, which prevents the aliasing problem mentioned above and makes it "cheap" to assign a value to a new variable.
A good introduction to move semantics is available at https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/.
(As a bonus, that tutorial also provides an introduction to "smart pointers", a beautiful construct in C++ to help us manage memory.)
If you're interested, we encourage you to implement a move constructor and overload the moving assignment operator for your BSTree, AVLTree, and RBTree classes.

For extremely interested students
A Binary Search Tree could be considered a subtype of a "Multiset" type.
In turn, AVL Trees and Red-Black Trees are each a subtype of a Binary Search Tree.
That is, a client interacts with a naive BST, an AVL Tree, and a Red-Black Tree in exactly the same manner as one another, which is as if it is a set of (possibly duplicated) things!
This shared interface can be codified in C++ by defining an abstract class called Multiset, containing the following virtual functions:

virtual unsigned int count_of(int value)
virtual void insert(int value)
virtual void remove(int value)
virtual int minimum_value()
virtual int maximum_value()
virtual void size(int value)
Note the similarities to and differences from the provided interface in AVLTree.h and RBTree.h.
Think about why these differences exist and how you could write an implementation for this hypothetical Multiset class using a Binary Search Tree (or AVL or Red-Black Tree) as a representation, and how to extend this typing relationship between naive BSTs and self-balancing trees.

For ridiculously interested students
The three BST implementations share an enormous amount of code between them, but there is no obvious way to implement these things without duplicating the code.
That is not to say there is not a way to do so.
One way to do so would be to leverage the Curiously Recurring Template Pattern, which lets one implementation for a function be shared among many implementations of a type, each of which returns a different type of thing (which is then used to, e.g., make a recursive call, or assign to a variable of derived type).
Doing so would require a tremendous restructuring of your code and you should not implement it for this assignment.
If you are "ridiculously interested", come talk to one of us and we can have a conversation about this clever use of C++ template classes.

The Reference Executables
We will provide three compiled binaries that run the same driver you have been given, named the_bst, the_avlt, and the_rbt, which were compiled and will run on the Zoo (but probably not your personal computer).
We encourage you to study their output carefully; it’s quite an interesting end product that you’ll end up with!
Pay careful attention to the format of the output.
Assessment of your submission will be automated, so even small errors in spacing can have an impact on your grade.
Fortunately, most of the output formatting is performed by code that was written for you, so as long as you do not modify main_*.cpp or pretty_print.cpp (you are not supposed to, anyway!), the output spacing should conform to expectations.
You can also verify that your code is correct by executing diff on the output obtained by the reference implementation (an empty diff is a good diff).

Testing
This time around, you're basically on your own for testing!
Except for the reference executables, we won't be releasing a testing script (there will be a make script on Gradescope that will allow you to confirm you submitted the appropriate files in the appropriate way).
But we will drop hints here and there about what kinds of things you should look for in your testing.

In fact, we'll start those recommendations now!

Pay careful attention to your implementation's handling of duplicate entries.
Consider the worst-case scenario for a naive BST. How does your AVL tree handle it? Your Red-Black tree?
What does a newly-created tree look like? A newly-destroyed one?
What happens if you don't put anything at all into your tree and try to call the various functions?
How big can you make your tree before things start to noticeably slow down? Does this limit change depending on the self-balancing algorithm used?
Remember unittest.cpp from the last pset?
We strongly encourage you to create a version of that with your own unit tests for the BSTree, AVLTree, and RBTree implementations.
Ask one of the course staff if you'd like some guidance on how to get started.
Here are some resources to give you a better overview of unit testing in general:

Wikipedia: Unit Testing
Googletest
Note: Googletest (aka gtest) relies on toolchains we haven't discussed in class (and won't!) but it's an industry standard unit testing framework for C and C++ code and it's probably worth an hour or two of your time to get it set up and familiarize yourself with its basics
Introduction to the theory of unit testing, from OSU
Tips and Hints
Before you write any code at all, familiarize yourself with the interface(s) for the classes you are asked to implement.
In particular, study and digest the detailed comments in the BSTNode.h interface file, which describes the behavior of a BSTNode.
After you are comfortable with the interface(s), study the pre-implemented functions to solidify your sense of how the representation maps to an abstract state.
Next, study the output of the reference executable and ensure you understand exactly how the tree gets from one state to the next.
Only then should you start writing code.

You are asked to implement many functions for this assignment.
We suggest you start by implementing the functions needed for the naive binary search tree (BSTree) before moving on to the self-balancing trees.
There is a naive Binary Search Tree implementation in the demo code from lecture, although it does not deal with duplicate entries.
Use that as a jumping-off point for your implementations in this assignment.
As you implement functions, you'll undoubtedly recognize patterns emerge.
Use those patterns to reduce your work by leveraging implementations from one function in another function.

As you implement each of the self-balancing functions, ensure that you conform exactly to the specified behavior.
The specifications for required functions are written such that they solve a local problem that can be leveraged to solve a global problem by repeated invocation of those functions.
They do not solve the global problem on their own.
Each relies on some facts about the tree being true before calling, which enables them to guarantee the invariants hold after the function.
For example, the function avl_balance assumes that the tree is "almost balanced" and rb_eliminate_red_red_violation assumes that within the tree rooted at this, the only violation (if there is one) is in the neighborhood of this.

It's likely that the most challenging function you write is rb_eliminate_red_red_violation.
Make sure you dedicate significant time to that function, because it does not follow the same pattern as other functions you're required to implement.
adjust
