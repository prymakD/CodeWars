#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int numOfTimes;
    int numToPush;
    multiset<int> multiseT;
    stack<int> stak;

    scanf("%d", &numOfTimes);

    char inp[10];
    for(int i = 0; i < numOfTimes; i++) {
        scanf("%s",inp);
        if(inp[1] == 'U') {
            scanf("%d", &numToPush);
            stak.push(numToPush);
            multiseT.insert(numToPush);
        } else if(inp[0] == 'M') {
            if(stak.empty()) {
              cout << "EMPTY\n";
            } else {
              cout << *multiseT.begin() << "\n";
            }
        } else if(inp[2] == 'P'){
            if(stak.empty()) {
              cout << "EMPTY\n";
            } else {
                int temp = stak.top();
                stak.pop();
                multiseT.erase(multiseT.find(temp));
            }
        }
    }
}
