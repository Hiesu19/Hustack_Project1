// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Permutation generation
// PERMUTATION_GEN	Accept		120	CPP17	6 / 6


#include <iostream>
#include <vector>

using namespace std;

void solve (int n, vector<int>& hoanVi, vector<bool>& check) {
    // Nếu độ dài vector hoanVi ==n thì in ra
    if (hoanVi.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << hoanVi[i] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        //Nếu check == false thì thêm đc
        if (!check[i]) {
            hoanVi.push_back(i); //thêm i vào cuối vector
            check[i] = true; //thay đổi check = true
            solve(n, hoanVi, check);
            hoanVi.pop_back(); //Xoá phần tử cuối cùng và trả về false
            check[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> hoanVi;
    vector<bool> check(n + 1, false);// Tạo vector toàn false

    solve(n, hoanVi, check);

    return 0;
}
