// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Binary sequence generation
// BINARY_SEQUENCE_GEN	Accept		100	CPP17	5 / 5


#include <iostream>
#include <string>
#include <math.h>
using namespace std;


// Tạo hàm chuyển từ số thực sang số nhị phân có độ dài bằng n
int N; 

string chuyenSoNhiPhan(int n){
    string res = "";
    while (n > 0) {
        // Thực hiện phép chia cho 2
        res = char (n % 2 + '0') + res; // n%2+'0' sẽ ra 0 hoặc 1
        n /= 2;
    }
    // Chỉnh lại cho độ dài bằng n
    while (res.length() < N)
        res = "0" + res;
    return res;
}

int main()
{
    int n;
    cin >> N;
    n = pow(2, N);
    
    for (int i = 0; i < n; i++) //Chayj for từ 0 đến 2^n
        cout << chuyenSoNhiPhan(i) << endl;
    return 0;
}
