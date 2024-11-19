// Nguyen Thai Hieu - Project1 - 2024.1
// Week 4 - Store & Search String
// STORE_SEARCH_STRING	Accept		100	CPP17	5 / 5	

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



// Hàm tìm kếm trong vector (trả 0,1)
int findV(const vector<string>& data, const string& k) {
    if (find(data.begin(), data.end(), k) != data.end()) {
        return 1;
    }
    return 0;
}

int main() {
    
    vector<string> data;
    string nhap, k;
    

    while (cin >> nhap) {
        if (nhap == "*") break;
        else data.push_back(nhap);
    }
    while (cin >> nhap) {
        if (nhap == "***") break;
        if (nhap == "find") {
            cin >> k;
            cout << findV(data, k) << endl;
        }
        if (nhap == "insert") {
            cin >> k;
            if (findV(data, k) == 0) {
                data.push_back(k);
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}
