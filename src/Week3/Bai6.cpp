// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - Simulation Stack
// STACK_SIM	Accept		100	CPP17	5 / 5

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Tạo stack myStack
stack<int> myStack;

// Hàm PUSH để thêm phần tử vào stack
void push_(int n) {
    myStack.push(n);
}

// Hàm POP để xóa phần tử ra khỏi stack và in kết quả
void pop_() {
    if (!myStack.empty()) {
        cout << myStack.top() << endl;  // Lấy phần tử trên cùng của stack
        myStack.pop();                  // Xóa phần tử trên cùng
    } else {
        cout << "NULL" << endl;         // Stack trống
    }
}

int main() {
    string s;
    while(cin>>s){
        if (s =="PUSH"){
            int n;
            cin >>n;
            push_(n);
        }
        if (s =="POP"){
            pop_();
        }
        if (s == "#"){
            break;
        }
    }

}
