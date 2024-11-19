// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Count odd and even number from a sequence
// COUNT_ODD_EVEN_ELEMENTS_FROM_SEQ	Accept		100	CPP17	5 / 5

#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n,d=0;
    int x;
    cin>>n;
    for ( int i=1 ;i<=n;i++){
        cin>>x;
        if(x%2==1){
            d++;
        }
    }
    cout<<d<<" "<<n-d;
}
