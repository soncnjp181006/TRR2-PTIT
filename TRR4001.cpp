// Cây khung
// Điều kiện tồn tại: G vô hướng liên thông

// Thuật toán tìm cây khung bằng DFS/BFS
// DFS(u):
//      visited[u] = true
//      for v : adj[u]:
//          if(!visited[v]):
//              (u, v) vào T
//              DFS(v)
// 
// if (T.size() == n || n == 1) -> In cây khung trong T

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int t, n, u;
vector<int> adj[1005];
vector<bool> visited(1005, false);
vector<pair<int, int>> T; // Cây khung

void DFS(int u) {
    visited[u] = true;
    for(auto v : adj[u]) {
        if(!visited[v]) {
            T.push_back({min(u, v), max(u, v)});
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto v : adj[x]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
                T.push_back({min(x, v), max(x, v)});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(!freopen("CK.INP", "r", stdin));
    if(!freopen("CK.OUT", "w", stdout));

    if (!(cin >> t >> n >> u)) return 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int val; cin >> val;
            if(val) {
                adj[i].push_back(j);
            }
        }
    }

    if(t == 1) DFS(u);
    else BFS(u);

    if(T.size() == n -1 || n == 1) {
        cout << T.size() << endl;
        for(int i = 0; i < T.size(); i++)
            cout << T[i].first << " " << T[i].second << endl;
    }
    else cout << 0;
}