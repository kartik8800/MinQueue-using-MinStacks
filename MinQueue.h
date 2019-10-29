/// author : kartik8800
#ifndef MINQUEUE_H
#define MINQUEUE_H
#include "MinStack.h"
using namespace std;

/*
Implementation of a Queue data structure that
supports insertion at the back of the queue,
removal from the front and get Minimum element
currently in the queue all in amortized O(1) time.
*/
template<class T>
class MinQueue
{
    public:
        //Push x to the rear of the queue
        void push(T x);
        //remove element from the front
        void pop();
        //get element currently at front of queue
        T top();
        //get smallest element currently in the queue
        T getMin();
        //check if the queue is empty
        bool empty()
        {
            return (Front.empty() && Rear.empty());
        }
        //number of elements currently in the queue
        int size()
        {
            return Front.size() + Rear.size();
        }

    private:
        //minStacks used to simulate the minQueue
        MinStack<T> Front, Rear;
        /*
          aux function that transfer elements from
          Rear stack to Front stack.
        */
        void fillFront();
};

template<class T>
void MinQueue<T> :: push(T x)
{
    Rear.push(x);
}

template<class T>
void MinQueue<T> :: pop()
{
    //no action if queue is empty.
    if(empty())
        return;

    /*
      element at top of Front represents the head
      element of the queue.
    */
    if(Front.empty())
       fillFront();

    Front.pop();
}

template<class T>
void MinQueue<T> :: fillFront()
{
     /*
       Transfer the contents of Rear Stack
       to Front stack.
     */
     while(!Rear.empty())
       {
           Front.push(Rear.top());
           Rear.pop();
       }
}

template<class T>
T MinQueue<T> :: top()
{
    //if queue is empty throw an exception.
    if(empty())
        throw *new exception;

    if(Front.empty())
      fillFront();

    return Front.top();
}

template<class T>
T MinQueue<T> :: getMin()
{
    //if queue is empty throw an exception.
    if(empty())
        throw *new exception;

    /*
       The elements of the queue are divided into
       the two stacks, so min of the queue is
       min(min of Front, min of Rear).
    */

    if(Front.empty())
        return Rear.getMin();

    else if(Rear.empty())
        return Front.getMin();

    else return min(Front.getMin(), Rear.getMin());
}

#endif // MINQUEUE_H
