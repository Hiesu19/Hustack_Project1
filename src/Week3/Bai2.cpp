// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - Check Parenthesis
// PARENTHESIS_CHECK	Accept		100	CPP17	5 / 5

#include<bits/stdc++.h>

using namespace std;

int kt(char x, char y){ // kiểm tra x có phải là dấu mở của y
    if(x=='[' && y==']') return 1;
	if(x=='{' && y=='}') return 1;
	if(x=='(' && y==')') return 1;
	
	return 0;
}

int solve(string s){ // Dùng stack
    vector<char> v;
    for(char c: s){
        if(c=='[' || c=='{'|| c=='('){
            v.push_back(c); //Nếu là dấu mở thêm vào stack
        }
        else{
            if(v.empty()) return 0;
            else{
                char x=v.back(); //x là phần tử trên cùng của stack
                v.pop_back();
                if(!kt(x,c)) return 0;
            }
        }
    }
    if(v.empty()) return 1;
    return 0;

}

int main(){
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
