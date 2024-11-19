// Nguyen Thai Hieu - Project1 - 2024.1
// Week 1 - Solve degree-2 polynomial equation
// DEGREE_2_POLY_EQUATION	Accept		100	CPP17	5 / 5

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    double a,b,c;
    cin>>a>>b>>c;
    
    double delta = b*b -4*a*c;
    
    if(delta<0){
        cout<<"NO SOLUTION";
    }
    
    if(delta==0){
        cout<<fixed<<setprecision(2)<<-b/(2*a);
    }
    
    if(delta>0){
        double res=sqrt(delta);
        cout<<fixed<<setprecision(2)<<min((-b-res)/(2*a),(-b+res)/(2*a))<<" "<<max((-b-res)/(2*a),(-b+res)/(2*a));
    }
}
