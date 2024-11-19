// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - Simulation Queue
// QUEUE_SIM	Accept		100	CPP17	5 / 5	

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Tạo hàng đợi sử dụng vector
vector<int> queue;

// Hàm PUSH để thêm phần tử vào hàng đợi
void push_(int value) {
    queue.push_back(value);
}

// Hàm POP để xóa phần tử ra khỏi hàng đợi và in kết quả
void pop_() {
    if (!queue.empty()) { // Nếu khác rỗng in ra số đầu tiên
        cout << queue.front() << endl; 
        queue.erase(queue.begin()); 
    } else {
        cout << "NULL" << endl;         // Hàng đợi trống
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
