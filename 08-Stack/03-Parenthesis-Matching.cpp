#include <stack>
#include <string>
#include <iostream>

bool is_balanced(std::string exp) {
    int index = 0;
    std::stack<char> brackets;
    while(exp[index] != '\0') {
        /* For opening brackets push to stack and 
         * for closing brackets pop from stack */
        if(exp[index] == '[' || exp[index] == '{' || exp[index] == '(')
            brackets.push(exp[index]);
        /* Check if closing brackets are found */
        else if(exp[index] == ']' || exp[index] == '}' || exp[index] == ')') {
            /* Check if brackets is non-empty and brackets are matched */
            if((!brackets.empty() && exp[index] == ']' && brackets.top() == '[') || 
                (!brackets.empty() && exp[index] == '}' && brackets.top() == '{') ||
                (!brackets.empty() && exp[index] == ')' && brackets.top() == '('))
                brackets.pop();
            else
                return false;
        }
        index++;
    }
    if(brackets.empty())
        return true;
    return false;
}

int main() {
    std::string e1 = "((a * b) + (c * d))";
    std::string e2 = "[{(a + b) * (c - d)} / e]";
    std::string e3 = "{([a * b) * [c - d]] / e}";
    std::string e4 = "(((a * b) + (c * d)) / e))";
    std::cout << (is_balanced(e1) == 1 ? "Balanced" : "Not Balanced") << std::endl;
    std::cout << (is_balanced(e2) == 1 ? "Balanced" : "Not Balanced") << std::endl;
    std::cout << (is_balanced(e3) == 1 ? "Blanaced" : "Not Balanced") << std::endl;
    std::cout << (is_balanced(e4) == 1 ? "Blanaced" : "Not Balanced") << std::endl;
    return 0;
}
