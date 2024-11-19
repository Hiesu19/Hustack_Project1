// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Dãy fibonacci
// HuyDQ_Cintro_Midterm_bai2	Accept		2 500	CPP17	4 / 4	

#include<iostream>
using namespace std;

int a[1000];

// Tạo mảng fibo gồm 40 ptu đầu tiên
void solve() {
    a[0] =0;
    a[1] =1;
    for (int i =2 ; i< 40 ;i++){
        a[i] = a[i-1] +a[i-2];
    }
    
}

int main() {
    solve();//Tạo mảng
    int n;
    cin >> n;
    cout << a[n-1];
    return 0;
}
