// Time- O(1) in both push and pop
// Space- O(n) because of array

// isme phle ik array bna rhe h then usko 2 parts mei divide first half for stack1 second for stack2
// uske bdd usme pop n push krenge

#include <iostream>
#include <stdlib.h>
  
using namespace std;
  
class twoStacks {
    int* arr;
    int size;
    int top1, top2;
  
public:
    // Constructor
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1; // isko initialise kr rhe h half+1
        top2 = n / 2;     // isko half pr
    }
  
    // Method to push an element x to stack1
    void push1(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1 > 0) {     // checking ki atleast 1 to h na isme ni h to -1
            top1--;         // minus kr krke peeche aa rhe h
            arr[top1] = x;  // store krne ke lie 
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
  
    // Method to push an element
    // x to stack2
    void push2(int x)
    {
  
        // There is at least one empty
        // space for new element
        if (top2 < size - 1) {  // same logic as stack 1
            top2++;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
  
    // Method to pop an element from first stack
    int pop1()
    {
        if (top1 <= size / 2) {   // agr size/2 se chota h to x mei store krenge value then top1++ kr denge aur x ko return
            int x = arr[top1];
            top1++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";  // else underflow
            exit(1);
        }
    }
  
    // Method to pop an element
    // from second stack
    int pop2()
    {
        if (top2 >= size / 2 + 1) { // same as prv
            int x = arr[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
};
  
/* Driver program to test twoStacks class */
int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}

Output
Stack Overflow By element :7
Popped element from stack1 is  : 11
Stack Overflow By element :40

Popped element from stack2 is : 15
  
  
  // Upr vale method mei bht faltu ki space use ho rhi  space efficient ni h
  
  
  
