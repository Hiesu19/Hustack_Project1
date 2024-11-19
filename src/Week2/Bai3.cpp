// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Compute C_k_n
// 	C_K_N	Accept		100	CPP17	5 / 5

#include<iostream>
using namespace std;

// Dùng mảng để tính
unsigned long long v[1000][1000];
unsigned long long modd = 1e9+7;

void solve() {
    for (int i = 0; i < 1000; i++) {
        v[i][0] = v[i][i] = 1; // C_0/x =1 ,C_x/x =1
        for (int j = 1; j < i; j++) {
            //C_k/n = C_k/n-1 + C_k-1/n-1
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % modd;
        }
    }
}
int main() {
    solve();
    int n, k;
    cin >> k >> n;
    cout << v[n][k];
    return 0;
}
