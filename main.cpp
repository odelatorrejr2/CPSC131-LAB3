// Oscar De La Torre
// CPSC-131
// 05-03-2024
//

#include <iostream>
#include <vector>
#include <string>

// The Stack class is defined to implement a stack using a vector.
class Stack {
private:
    std::vector<char> data;

public:
    // Adds a character to the top of the stack.
    void push(char c) {
        data.push_back(c);
    }

    // Removes and returns the top character from the stack.
    char pop() {
        char c = data.back();
        data.pop_back();
        return c;
    }

    // Checks if the stack is empty and returns true or it's false
    bool isEmpty() {
        return data.empty();
    }
};

// This function takes a string expression.
// It uses an instance of the Stack class to keep track of open parentheses.
// It also iterates through each character in the expression.
bool isBalanced(std::string expression) {
    Stack stack;
    
    for (char c : expression) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.isEmpty()) {
                return false; // Unbalanced ')' without '('
            } else {
                stack.pop();
            }
        }
    }
    return stack.isEmpty(); // If stack is empty, all '(' were matched
}

int main() {
    std::string expression;
    std::cout << "Enter an expression with parentheses: ";
    std::cin >> expression;

    // It reads an input expression from the user, calls the isBalanced function.
    if (isBalanced(expression)) {
        std::cout << "Balanced\n";
    } else {
        std::cout << "Not Balanced\n";
    }

    return 0;
}
