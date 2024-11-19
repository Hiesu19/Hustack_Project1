// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Text Replacement
// TEXT_REPLACEMENT	Accept		100	CPP17	5 / 5

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string P1, P2, T;
    
    getline(cin, P1);
    getline(cin, P2);
    
    while(getline(cin, T)){
        size_t p = 0;
         while ((p = T.find(P1, p)) != string::npos) {
            T.replace(p, P1.length(), P2);
            p += P2.length();
        }
        cout << T << endl;
    }
    return 0;
}
