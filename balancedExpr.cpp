#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std; //Makes it easier to access methods and makes it global

//Function to check if the opening and closing brackets match
bool isMatchingPair(char open, char close){
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}


//Function to check if the expression has balanced brackets
bool isBalanced(const string& expression){
    stack<char> s; //Stack to keep track of opening brackets

    // Iterate through each character in the expression
    for (char ch : expression) {
        // If the character is an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If the character is a closing bracket, check for balance
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty or if the top of the stack doesn't match
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                // closing brackets didnt match
                return false;
            }
            s.pop(); // pop the matched opening brackets from the stack
        }
    }
    return s.empty(); // if stack is empty, its already balanced
}

int main(){
    string filePath; // variable to store the path to input file
    cout << "Enter the to your expression file: ";
    cin >> filePath;
    /*
     Examples of file inputs:
        - For a file in the same folder as the program: filename.txt or filename.cpp or filename.java
        - For a file in a different folder: data/filename.txt
        - For an absolute path: C:/Users/your_name/Documents/filename.txt
     */

    ifstream inputFile(filePath);
    string expression;

    //checking if the files opened successfully
    if (!inputFile){
        cout << "Unable to open file. \n";
        return 1;
    }

    //read each line from file until the end
    while (getline(inputFile, expression)) {
        //check if current expression is balanced
        if (isBalanced(expression)) {
            cout << "The expression '" << expression << "' is balanced.\n";
        } else {
            cout << "The expression '" << expression << "' is NOT balanced.\n";
        }
    }

    inputFile.close();  // Close the file after processing
    return 0; // exit the program
}

