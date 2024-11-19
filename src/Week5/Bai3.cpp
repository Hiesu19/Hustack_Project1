// Nguyen Thai Hieu - Project1 - 2024.1
// Week 5 - Minimum Spanning Tree - Kruskal
// MST_KRUSKAL	Accept		100	CPP17	5 / 5	

#include <bits/stdc++.h>
using namespace std;

// Tạo đối tượng cạnh
struct edge{
    int u, v;
    int w;
};

int n, m;
int parent [100000], sz[100000];
vector<edge> canh;

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find (parent[v]);
}

bool check_kruskal(int a, int b){
    a = find(a);
    b = find (b);
    if(a == b) return false; // khong the gop a, b vào voi nhau
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] + sz[b];
    return true;
}
void inp() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w;
        edge e = edge {x, y, w};
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void solve_kruskal(){
    //Tao cay khung cuc tieu rong
    vector<edge> mst;
    
    int d = 0;
    //Sort danh sach canh theo chieu dai tang dan
    sort(canh.begin(), canh.end(), cmp);


    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        edge e = canh[i]; // chon canh e la canh nho nhat
        if (check_kruskal (e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d << endl;
}

int main(){
    inp();
    make_set();
    solve_kruskal();
}
