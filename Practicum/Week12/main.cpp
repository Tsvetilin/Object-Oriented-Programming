#include <iostream>
#include "Stack.hpp"

int main() {
    Stack<int, 5> s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        std::cout << "Top element: " << s.top() << std::endl;
        std::cout << "Stack size: " << s.getSize() << std::endl;

        s.pop();
        std::cout << "Top element after pop: " << s.top() << std::endl;
        std::cout << "Stack size after pop: " << s.getSize() << std::endl;

        while (!s.empty()) {
            std::cout << "Popping: " << s.top() << std::endl;
            s.pop();
        }

        s.pop();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}