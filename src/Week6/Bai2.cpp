// Nguyen Thai Hieu - Project1 - 2024.1
// Week 6 - Max Flow
// MAX_FLOW	Accept		60	CPP17	3 / 3

#include<bits/stdc++.h>
#define INF 999999
using namespace std;

int V, e, s, t;           // V: số đỉnh, e: số cạnh, s: đỉnh nguồn, t: đỉnh đích
int graph[110][110]; 

// Hàm kiểm tra xem có đường đi từ đỉnh `s` đến đỉnh `t` không
bool hasPath(int *parent) {
    bool visited[V + 1] = {false}; // Mảng đánh dấu các đỉnh đã được thăm

    queue<int> q;
    q.push(s);              
    visited[s] = true;   
    parent[s] = -1;
    
    // BFS để tìm đường đi từ s -> t
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        // Duyệt qua tất cả các đỉnh liền kề với `u`
        for (int i = 1; i <= V; i++) {
            if (visited[i] == false && graph[u][i] > 0) {
                q.push(i);           
                visited[i] = true;   
                parent[i] = u;         
            }
        }
    }
    
    return visited[t]; // Trả về true 
}

// Hàm Ford-Fulkerson
int fordFulkerson() {
    int u, v;                    
    int maxFlow = 0;          
    int *parent = (int *) malloc ((V + 1) * sizeof(int)); // Mảng lưu đường đi tìm được

    // Lặp lại đến khi không còn đường đi từ `s` đến `t`
    while(hasPath(parent)) {
        int path_flow = INF; 

        // Duyệt ngược từ `t` về `s` để tìm luồng nhỏ nhất trên đường đi
        for (v = t; v != s; v = parent[v]) {
            u = parent[v]; 
            path_flow = min(path_flow, graph[u][v]); 
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow; 
        }

        maxFlow += path_flow; // Cộng 
    }

    return maxFlow; // Trả về tổng luồng cực đại
}

int main() {
    // Nhập
    cin >> V >> e >> s >> t;

    // tạo graph = 0 0
    for(int i = 1; i <= V; i++) 
        for(int j = 1; j <= V; j++) 
            graph[i][j] = 0;

    // Nhập các cạnh và trọng số
    for(int i = 1; i <= e; i++) {
        int u, v, w; 
        cin >> u >> v >> w; 
        graph[u][v] = w;    // Gán trọng số w cho cạnh (u, v)
    }

    cout << fordFulkerson();

    return 0;
}
