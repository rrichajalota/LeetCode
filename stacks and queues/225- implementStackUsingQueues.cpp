/*  225. Implement Stack using Queues  

    Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.
*/

class Stack {
public:
    queue<int> q1;
    queue<int> q2;
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        else if(q2.empty()){
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty())
            q1.pop();
        
        else if(!q2.empty())
            q2.pop();
        
    }

    // Get the top element.
    int top() {
        if(!q1.empty()){
            int val= q1.front();
            return val;
        }
        else if(!q2.empty()){
            int val= q2.front();
            return val;
        }
        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};