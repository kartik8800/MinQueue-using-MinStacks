# MinQueue-using-MinStacks
This is a CPP implementation of a MinQueue that provides the basic functionalities of a queue with the added functionality of getting the smallest element currently in the queue in amortized O(1) time complexity.

The MinQueue uses two MinStacks to simulate the behaviour of a Queue.
Functionalities :
1. push(x) : push element x at the back of the queue
2. pop : remove an element from the front of the queue.
3. top : return the element currently at the front of the queue.
4. getMin : return the current smallest element in the queue.

Example Usage :<br>
MinQueue < int > Q: <br>
Q.push(5);<br>
Q.push(3);<br>
Q.push(10);<br>
// currently Q looks like 5 -> 3 -> 10<br>
// Q.getMin() returns 3. <br>
