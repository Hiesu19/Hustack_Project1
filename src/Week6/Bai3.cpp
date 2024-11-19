// Nguyen Thai Hieu - Project1 - 2024.1
// Week 6 - Shortest Path between 2 nodes on a directed graph with non-negative weights
// SHORTEST_PATH_DIJKSTRA	Accept		140	CPP17	7 / 7

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX 
using namespace std;


struct Edge {
    int vertex;  //Dích 
    int weight;  
};

// Hàm thêm cạnh vào đồ thị
void addEdge(vector<vector<Edge>>& graph, int u, int v, int w) {
    graph[u].push_back({v, w});
}

// Hàm thuật toán Dijkstra 
int dijkstra(const vector<vector<Edge>>& graph, int n, int src, int dest) {
    vector<int> dist(n + 1, INF); // Khởi tạo khoảng cách đến các đỉnh là vô cực
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Đưa đỉnh nguồn vào hàng đợi

    while (!pq.empty()) {
        int u = pq.top().second; 
        int uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u]) continue;

        // Duyệt tất cả các cạnh từ đỉnh `u`
        for (const Edge& edge : graph[u]) {
            int v = edge.vertex;
            int weight = edge.weight;

            // Nếu tìm thấy đường đi ngắn hơn đến `v`, cập nhật khoảng cách
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Thêm đỉnh `v` với khoảng cách mới vào hàng đợi
            }
        }
    }

    // Trả về khoảng cách đến đỉnh đích
    return dist[dest] == INF ? -1 : dist[dest];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    // Đọc các cạnh và thêm vào đồ thị
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    int s, t;
    cin >> s >> t;

    int res = dijkstra(graph, n, s, t); // Thực hiện Dijkstra

    if (res == -1)
        cout << "-1\n";
    else
        cout << res << "\n";

    return 0;
}
