// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Sum Array
// SUM_ARRAY	Accept		100	CPP17	3 / 3	

#include <iostream>
using namespace std;

int main (){
    int n;
    int s = 0;
    cin >>n;
    int a[n+1];
    for (int i= 0  ; i <n ; i++){
        cin >>a[i];
        s+= a[i];
    }
    cout <<s;
}
