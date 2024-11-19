// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Count number of sudoku solutions
// SUDOKU_COUNT	Accept		100	CPP17	5 / 5	

#include <bits/stdc++.h>
using namespace std;

int a[9][9];  
int dem = 0; 

// Hàm kiểm tra có hợp lệ không
bool check(int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (a[row][i] == val || a[i][col] == val) {
            return false;
        }
    }
    
    // Kiểm tra ô 3x3
    int startRow = (row / 3) * 3;  // Hàng bắt đầu
    int startCol = (col / 3) * 3;  // Cột bắt đầu
    for (int i = 0; i < 9; i++) {
        if (a[startRow + i / 3][startCol + i % 3] == val) {
            return false; 
        }
    }
    
    return true;
}

// Hàm đệ quy
void solve(int row, int col) {
    if (row == 9) {
        dem++;
        return;
    }

    // Chuyển sang ô tiếp theo nếu ô hiện tại đã có giá trị
    if (a[row][col] != 0) {
        if (col == 8) {  // Nếu là cột cuối cùng, chuyển sang hàng tiếp theo
            solve(row + 1, 0);
        } else {  // Nếu không, chuyển sang cột tiếp theo
            solve(row, col + 1);
        }
    } else {
        // Thử điền các số từ 1 đến 9
        for (int val = 1; val <= 9; val++) {
            if (check(row, col, val)) {
                a[row][col] = val;
                if (col == 8) {  // Chuyển sang hàng tiếp theo
                    solve(row + 1, 0);
                } else {  // Nếu không chuyển sang cột tiếp theo
                    solve(row, col + 1);
                }
                a[row][col] = 0;  // Đặt lại ô 
            }
        }
    }
}

int main() {
    // Nhập bảng Sudoku
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }
    solve(0, 0);
    cout << dem << endl;

    return 0;
}
