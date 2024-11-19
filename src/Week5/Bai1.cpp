// Nguyen Thai Hieu - Project1 - 2024.1
// Week 5 - Hamiton Cycle
// HAM_CYCLE	Accept		20	CPP17	1 / 1	

#include <bits/stdc++.h>
using namespace std;

int bac[10000] ={0}; // Lưu bậc của đỉnh đều = 0
//Hàm input
int inp (){
    int n,m;
    cin>>n>>m;
    for (int i =0 ; i <m ; i++){
        int x ,y;
        cin >> x >> y;
        bac[x]++;
        bac[y]++;
    }
    return n;
}

// Ham kiem tra xem co chu trình Hamilton hay không?
// Chu trình haminton có bậc ở mỗi đỉnh luôn lớn hơn số n/2
bool check(int n){
    for (int i = 1; i <= n; i++) {
        if(bac[i] < n / 2) return false;
    }
    return true;
}
int main()
{
    int t;
    cin >>t;
    while(t--){
        int n = inp();
        // check(n);
        cout <<check(n) <<endl;
        int bac[10000] ={0};
    }
}
