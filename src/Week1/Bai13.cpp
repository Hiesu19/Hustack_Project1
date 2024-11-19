// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - k-Subsequence even
// K_SUBSEQ_EVEN	Accept		100	CPP17	5 / 5		

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n,k;
    int d=0,s=0;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        s+=a[i];
    }
    if(s%2==0){
        d++;
    }
    for(int i=1;i<=n-k;i++){
        s=s-a[i]+a[i+k];
        if(s%2==0){
            d++;
        }
    }
    cout<<d;
}
