// Nguyen Thai Hieu - Project1 - 2024.1
// Week 6 - All pair shortest paths
// ALL_PAIR_SHORTEST_PATH	Accept		40	CPP17	2 / 2	

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int u, v, w;
};

int solve(int n, int m, vector<Edge> &edges, int s, int t) {
    //Ban đầu tạo 1 vector khoảng cách
    // Khảng cách từ đỉnh s tới các đỉnh còn lại là vô cùng trừ chính s = 0
    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;

    // Áp dụng thuật toán BellmanFord
    for (int i = 0; i < n - 1; ++i) {
        for (const auto &edge : edges) { // Duyệt hết tất cả các cạnh
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.w < distance[edge.v]) {
                // Cập nhật lại khoảng cách từ đỉnh xuất phát
                distance[edge.v] = distance[edge.u] + edge.w;
            }
        }
    }

    // Kiểm tra kết quả
    return distance[t] == INT_MAX ? -1 : distance[t];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    // Nhập các cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    for (int i =1 ; i <= n ;i++){
        for (int j = 1; j<=n; j++ ){
            cout << solve(n, m, edges, i, j)  << " ";
        }
        cout << endl;
    }

    return 0;
}
