// Nguyen Thai Hieu - Project1 - 2024.1
// Week 2 - Binary sequences generation without consecutive 11
// BINARY_GEN_WITHOUT_CONSECUTIVE_11	Accept		100	CPP17	5 / 5


#include <iostream>
#include <vector>
#include <string>
using namespace std;


void  solve(int n, string s, char last, vector<string>& res) {
    // Dừng khi có độ dài n
    if (s.length() == n) {
        res.push_back(s);
        return;
    }
    //Thêm 0
    solve(n, s + '0', '0', res);
    
    // Thêm '1' chỉ khi ký tự cuối cùng không phải là '1'
    if (last != '1') {
        solve(n, s + '1', '1', res);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> res;
    //Chạy đệ quy lưu vào res
    solve(n, "", '0', res);

   for (string s : res) {
        cout<<s<<endl;
    }


    return 0;
}
