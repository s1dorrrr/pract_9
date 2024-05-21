#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <utility> // For std::pair

int main() {
    int continueFlag;
    do {
        std::string input;
        std::cout << "Enter an expression with balanced parentheses: ";
        std::getline(std::cin, input); // Reading the string

        std::stack<int> st;
        std::vector<std::pair<int, int>> brackets;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                // Push the index of the opening parenthesis onto the stack
                st.push(i);
            }
            else if (input[i] == ')') {
                if (!st.empty()) {
                    // Take the index of the opening bracket and form a pair with the current index
                    int openIndex = st.top();
                    st.pop();
                    brackets.push_back(std::make_pair(openIndex, i));
                }
            }
        }

        // Print the positions of the brackets in reverse order to match the assignment requirement
        for (auto it = brackets.rbegin(); it != brackets.rend(); ++it) {
            std::cout << it->first + 1 << ' ' << it->second + 1;
            if (it != brackets.rend() - 1) std::cout << ", "; // Avoiding the trailing comma
        }
        std::cout << "\nDo you want to continue? 1 (yes) | 2 (no): ";
        std::cin >> continueFlag;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing the input buffer
    } while (continueFlag == 1);

    return 0;
}
