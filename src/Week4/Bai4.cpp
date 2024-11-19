// Nguyen Thai Hieu - Project1 - 2024.1
// Week 4 - Sum pair of sequence equal to a number
// SUM_PAIR_EQUAL_M	Accept		100	CPP17	5 / 5	

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    set<int> seen; // tạo mảng đã duyệt qua
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int k = M - x;

        // kiểm tra xem k có trong set không
        if (seen.find(k) != seen.end()) {
            count++;
        }
        // Thêm x vào set
        seen.insert(x);
    }

    cout << count;
}
