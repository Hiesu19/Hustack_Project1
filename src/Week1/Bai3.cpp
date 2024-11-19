// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Convert a TEXT to Upper-Case
// TO_UPPER_CASE_TEXT	Accept		100	CPP17	5 / 5

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(getline(cin,s)){
        for (char& c : s) {
            c = toupper(c);
        }
        cout<<s;
        cout<<endl;
    }
    return 0;
}
