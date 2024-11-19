// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Basic queries on array
// BASIC_QUERY_ARRAY	Accept		100	CPP17	5 / 5	

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    string s;
    while(cin>>s){
        if(s=="find-max"){
            int max_=-9999;
            for(int i=1;i<=n;i++){
                if(a[i]>max_){
                    max_=a[i];
                }
            }
            cout<<max_<<endl;
        }
        if(s=="find-min"){
            int min_=9999;
            for(int i=1;i<=n;i++){
                if(a[i]<min_){
                    min_=a[i];
                }
            }
            cout<<min_<<endl;
        }
        
        if(s=="find-max-segment"){
            int l,r;
            cin>>l>>r;
            int max_=-9999;
            for(int i=l;i<=r;i++){
                if(a[i]>max_){
                    max_=a[i];
                }
            }
            cout<<max_<<endl;
        }
        if(s=="sum"){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=a[i];
            }
            cout<<sum<<endl;
        }
        if(s=="***"){
            break;
        }
    }
}
