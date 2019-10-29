#ifndef MINSTACK_H
#define MINSTACK_H
#include <vector>
using namespace std;

template<class T>
class MinStack
{
    public:
        //get element at top of the stack
        T top();
        //get smallest element currently in stack
        T getMin();
        //push x on top of the stack
        void push(T x);
        //remove topmost element from the stack
        void pop();
        //check if the stack is empty
        bool empty()
        {
            return myStack.empty();
        }
        //returns number of elements currently in stack
        int size()
        {
            return myStack.empty();
        }

    private:
        //STL stack that backs up our minStack
        stack<pair<T, T>> myStack;
};

template<class T>
void MinStack<T> :: push(T x)
{
    /*
       the element x is to be pushed at top of the stack
       we push { x, MIN_ELEMENT } instead of only x.
       here MIN_ELEMENT represents the minimum element.
    */

    if(myStack.empty())
        myStack.push( { x, x } );

    else
    {
        T currMin = getMin();
        myStack.push({ x, min(currMin, x) });
    }
}

template<class T>
void MinStack<T> :: pop()
{
    if(!myStack.empty())
      myStack.pop();
}

template<class T>
T MinStack<T> :: top()
{
    //if stack is empty throw an exception
    if(myStack.empty())
        throw *new exception();

    return myStack.top().first;
}

template<class T>
T MinStack<T> :: getMin()
{
    //if stack is empty throw an exception
    if(myStack.empty())
        throw *new exception();

    return myStack.top().second;
}


#endif // MINSTACK_H
