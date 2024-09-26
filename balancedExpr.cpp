#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std; //Makes it easier to access methods and makes it global


bool isMatchingPair(char open, char close){
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool isBalanced(const string& expression){
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty(); 
}

int main(){
    string filePath;
    cout << "Enter the to your expression file: ";
    cin >> filePath;

    ifstream inputFile(filePath);
    string expression;

    if (!inputFile){
        cout << "Unable to open file. \n";
        return 1;
    }
    
    while (getline(inputFile, expression)) {
        if (isBalanced(expression)) {
            std::cout << "The expression '" << expression << "' is balanced.\n";
        } else {
            std::cout << "The expression '" << expression << "' is NOT balanced.\n";
        }
    }

    inputFile.close();  // Close the file after processing
    return 0;
}

