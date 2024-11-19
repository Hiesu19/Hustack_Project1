// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Count words
// COUNT_WORD	Accept		160	CPP17	8 / 8	

#include<bits/stdc++.h>
using namespace std;

int main() {
    int d=0;
    string s;
    
    while(getline(cin,s)){
        s=" "+s;
        bool check=false;
        
        for(char c : s){
            if(isspace(c)){
                check=true;
            }
            if(check==true){
                if(!isspace(c)){
                    d++;
                    check=false;
                }
            }
        }
    }
    cout<<d;
}
