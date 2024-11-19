// Nguyen Thai Hieu - Project1 - 2024.1
// Week 5 - Sequence of nodes visited by BFS
// BFS_LIST_NODES_LEX	Accept		40	CPP17	2 / 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Dùng hàng đợi queue để làm bfs

void solve_bfs(int root, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);

        // Thêm các đỉnh kề vào hàng đợi 
        for (int n : graph[v]) {
            if (!visited[n]) {
                q.push(n);
                visited[n] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> res;

    // Nhập
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Sắp xếp các danh sách kề
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

  
    //  solve_bfs(1, graph, visited, res); // Bắt đầu duyệt từ đỉnh 1
     
    // Dùng for để duyệt hết tất cả, tránh trường hợp đồ thị rời nhau, không nối với nhau 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            solve_bfs(i, graph, visited, res);
        }
    }

    // In kết quả
    for (int n : res) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
