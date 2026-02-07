#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private:
        stack<int>push_stack;
        stack<int>pop_stack;
    public:
        void enqueue(int value);
        int dequeue();
};

void Queue::enqueue(int value) {
    push_stack.push(value);
}

int Queue::dequeue() {
    // If both stacks are empty Queue is empty
    if(push_stack.empty() && pop_stack.empty())
        return -1;
    // If pop_stack is empty but push_stack is non-empty
    else if(!push_stack.empty() && pop_stack.empty()) {
       while(!push_stack.empty()) {
           pop_stack.push(push_stack.top());
           push_stack.pop();
       }
    }
    // Pop from pop_stack(), which ensure FIFO
    int popped = pop_stack.top();
    pop_stack.pop();
    return popped;
}


int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue() << endl;    // 4
    cout << q.dequeue() << endl;    // 5
    q.enqueue(10);
    q.enqueue(12);
    cout << q.dequeue() << endl;    // 6
    cout << q.dequeue() << endl;    // 10
    cout << q.dequeue() << endl;    // 12
    cout << q.dequeue() << endl;    // -1

    return 0;
}
