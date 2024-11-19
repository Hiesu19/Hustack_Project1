// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - List sequence of integer having 3 digits divisible by n
// 	LIST_NUMBER_3_DITGITS_DIVISIBLE_N	Accept		100	CPP17	5 / 5


#include <iostream>
using namespace std;

int main (){
    int n,s;
    cin >>n;
    for (int i = 1 ; i < 1000 ; i++){
        s = n*i;
        if (s>=100 && s <=999){
            cout <<s<<" ";
        }
    }
}
