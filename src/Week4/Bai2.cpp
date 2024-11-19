// Nguyen Thai Hieu - Project1 - 2024.1
// Week 4 - Kiểm tra xuất hiện
// ipmac-set-exist	Accept		100	CPP17	5 / 5

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> seenNumbers; // dùng set để chưa số đã xuất hiện
    int x;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (seenNumbers.count(x)) { // Trả về có xuất hiện trong set hay không
            cout << "1\n";
        } else {
            cout << "0\n";
            seenNumbers.insert(x); //thêm vào set
        }
    }
    
    return 0;
}
