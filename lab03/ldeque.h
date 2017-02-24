// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete LDeque template class

// First, get the declaration for the base stack class
#include "stack.h"

// This is the declaration for LDeque.
// Array-based stack implementation
template <typename E> class LDeque: public Stack<E> {
private:
  Link<E>* top;                  // Index for top element
  Link<E>* bottom;
  int size;

public:
  LDeque(int size =defaultSize)   // Constructor
    { front = rear= new Link,<E>(); size=0; }

  ~LDeque() { clear(); delete front; }  // Destructor

  void clear() {  
	 while(front->next != NULL) { // Delete each link node
      rear = front;
      delete rear;
    }
    rear = front;
    size = 0;
  }
           // Reinitialize

  void push(const E& it) {         // Put "it" on stack
    Assert(top != maxSize, "Stack is full");
    listArray[top++] = it;
  }

  E pop() {                // Pop top element
    Assert(top != 0, "Stack is empty");
    return listArray[--top];
  }

  const E& topValue() const {     // Return top element
    Assert(top != 0, "Stack is empty");
    return listArray[top-1];
  }

  int length() const { return top; }  // Return length
};
