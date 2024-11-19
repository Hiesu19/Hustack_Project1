// Nguyen Thai Hieu - Project1 - 2024.1
// Week 5 - List order of nodes visited by a DFS
// DFS_LIST_ORDER_NODES	Accept		20	CPP17	1 / 1

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


// Dùng stack để làm dfs

void solve_dfs(int root, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& res) {
    // Root là node đầu tiên: vì thứ tự từ điển => root =1 
    // graph là vector lưu giá trị nhập vào
    //víited là lưu giá trị đã duyệt qua
    // res là vector kết quả
    
    stack<int> s;
    s.push(root);
    
    while (!s.empty()) {
        int v = s.top(); //Lấy ptu trên cùng
        s.pop(); //Xoá ptu trên cùng
        
        if (!visited[v]) {
            visited[v] = true; //đánh dấu đã đi qua
            res.push_back(v);// thêm vào kết quả
            
            // Thêm các đỉnh kề vào ngăn xếp theo thứ tự giảm dần để duyệt từ bé đến lớn
            for (int i = graph[v].size() - 1; i >= 0; i--) {
                int n = graph[v][i];
                if (!visited[n]) {
                    s.push(n);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false); // Mảng đánh dấu các đỉnh đã duyệt
    vector<int> res;
    
    // Nhập
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Lưu các nút liền kề
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Sắp xếp các danh sách kề
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    solve_dfs(1, graph, visited, res); // Bắt đầu duyệt từ đỉnh 1
    
    // In
    for (int n : res) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
