# Linked-List

# This linked list implementation and design was the final challenge of my university course. Which focused on object-centered design and implementation in C++. Building programs from modules. Data abstractions and classes to implement abstract data types. Static and dynamic memory allocation. Data structure implementation and algorithm efficiency. Lists, tables, stacks, and queues. Templates and generic programming. I implemented the member and friend functions that are bolded below, as well as the main.cpp file. The singlelink.hpp file was provided as guidance by the course instructor.


A singly-linked list is a data structure for implementing a generic array of elements, where each node has data, and a pointer to the next node. The list structure typically has pointers to the list’s first node and last node. A singly-linked list’s first node is typically called the head, and the last node the tail.

Node has two private members, Node* next_ and int data_.
next_ is a pointer to another instance of type Node; the “chain” that makes up the structure of the entire list.
data_ is the value held by the Node. It’ll only be allowed to hold integers.
It has two constructors, a default that initializes data_ to 0, and a one-parameter variant that initializes data_ to the incoming argument.

SingleLink has two private members, Node* head_ and Node* tail_, which are pointers to the first and last node of the list, respectively.
If the list is ever empty, head_ and tail_ should point to nullptr.
If the list ever has one Node, both the head_ and tail_ should point to that one Node.
SingleLink has two constructors; a default with no arguments, and a one-parameter variant that should add a Node with data, dat, to the list.
If the one-parameter variant is invoked, the head and tail pointers will need to be adjusted to point to this new Node

# void append_back(int dat)
Member function; creates a new Node instance with data_=dat and appends it to the end of the list.

# ostream & operator<<(ostream &out, const SingleLink &s)
Friend function; pushes the data_ member of each Node instance in the list to the output stream, out, and returns ostream &.

# bool del(int val)
Searches through the list for the first Node that has the same data_ value as val. If found, deletes the Node and returns true, otherwise it returns false.


# Node & operator[](size_t index)
This member function is an override for the [] operator. On a call, such as sl[3], the argument, 3, is assigned to the parameter, index. The return value is a reference to a Node so that the Node can be modified (i.e., can show up on either side of an assignment operator).
