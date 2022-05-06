#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

int pc(char opr) {
    if((opr == '+') ||  (opr == '-')) {
      return 1;
    } else if((opr == '*') || (opr == '/')) {
      return 2;
    } else if(opr == '^') {
      return 3;
    } else {
      return -1;
    }
}


int main(void) {
    using namespace std;
    int count;
    string expression;
    cin >> count;

    string postFix;
    stack<char> stak;

    while(count != 0) {

        cin >> expression;

        for(int i=0; expression[i]; i++) {
            if(expression[i]<= 'z' && expression[i]>= 'a' || expression[i] >= 'A' && expression[i] <= 'Z' ){
                postFix.push_back(expression[i]);
            }
            else if(expression[i] == '(') {
                stak.push('(');
            }
            else if(')' == expression[i] ) {

                while(stak.top() != '(' && !stak.empty()) {
                    postFix.push_back(stak.top());
                    stak.pop();
                }
                if(!stak.empty()) {
                  stak.pop();
                } else {
                    cerr<< "Invalid infix expression: "<< expression << endl;
                    exit(1);
                }
            }
            else {
                while(!expression.empty() && pc(expression[i]) <= pc(stak.top())) {
                    postFix.push_back(stak.top());
                    stak.pop();
                }
                stak.push(expression[i]);
            }
        }

        while(!stak.empty()) {
            postFix.push_back(stak.top());
            stak.pop();
        }

        cout << postFix << endl;
        count--;
    }

    return 0;
}
