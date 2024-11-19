// Nguyen Thai Hieu - Project1 - 2024.1
// Week 4 - Hash Over Strings
// HASH_FUNCTION_STRING	Accept		100	CPP17	5 / 5	

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solve(string s ,int m){ //Hàm tính hash
    int hash = 0;
    int k = s.length();
    
    for (int i = 0; i < k; ++i) {
        hash = (hash * 256 + s[i]) % m;
    }
    return hash;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int hash = solve(s, m); //Tính hash của string
        cout << hash<< endl;
    }

}
