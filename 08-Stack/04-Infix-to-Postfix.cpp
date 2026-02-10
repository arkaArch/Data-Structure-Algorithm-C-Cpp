#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool is_operand(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    return true;
}

int precedence(char x) {
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    
    return 0;
}

// If operand then
//      push it to postfix expression
// If operator then
//      If pracedence of the operator is higher than the st.top() operator
//          push it to postfix expression
//      If st.top() precedence is higher
//          pop it from stack and push it to postfix expression
//
// After scan through the whole expression, if the stack is not empty
// push the element of stack to postfix expression.

string convert_to_postfix(string expression) {
    stack<int> st;
    string postfix;

    int i = 0;
    while(expression[i] != '\0') {
        if(is_operand(expression[i]))
            postfix.push_back(expression[i++]);
        else {
            if(!st.empty() && precedence(expression[i]) <= precedence(st.top())) {
                postfix.push_back(st.top());
                st.pop();
            }
            else
                st.push(expression[i++]);
        }
    }

    while(!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*c-d/e";
    
    // postfix = abc*+de/-
    cout << convert_to_postfix(infix) << endl;
    
    return 0;
}
