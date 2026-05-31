// matrix[n][n]

// 1. Tìm số lượng đường đi từ u -> v với độ dài k
// k = 2 -> 1 vòng lặp: 
//      for(k = 1 -> n) if(matrix[u][k] && matrix[k][v]) cnt += 1
// k = 3 -> 2 vòng lặp lồng:
//      for(a = 1 -> n) { for(b = 1 -> n) { if(matrix[u][a] && matrix[a][b] && matrix[b][v]) cnt += 1 } }

// 2. Tìm đường đi từ u -> v theo BFS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, u, v;
vector<int> adj[1000];
vector<int> parent;

bool bfs(int start, int end) {
    vector<int> visited(n, 0);
    parent.assign(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    parent[start] = -1; // Không có cha ở đỉnh nguồn

    while(!q.empty()) {
        int u = q.front(); 
        q.pop();

        if(u == end) return true;

        for(auto x : adj[u]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = 1;
                parent[x] = u; // ghi nhớ cha của x
            }
        }
    }    

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(!freopen("TK.INP", "r", stdin)) return 0;
    if(!freopen("TK.OUT", "w", stdout)) return 0;

    
    cin >> t >> n >> u >> v;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];

            if(matrix[i][j])
                adj[i].push_back(j);
        }
    }

    if(t == 1) {
        int cnt = 0;

        for(int k = 0; k < n; k ++) {
            if(matrix[u-1][k] && matrix[k][v-1]) cnt += 1;
        }

        cout << cnt;
    }
    else {
        if(bfs(u - 1, v - 1)) {
            vector<int> path;
            int curr = v - 1; // Bắt đầu từ đỉnh đích
            
            // 1. Truy ngược từ v về u bằng mảng parent
            while(curr != -1) {
                path.push_back(curr + 1); // Lưu đỉnh (chuyển về 1-based)
                curr = parent[curr];      // Nhảy ngược về cha
            }
            
            // 2. Hiện tại path đang là [v, ..., u], cần đảo ngược lại
            // In từ phần tử cuối về đầu
            for(int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << (i == 0 ? "" : " ");
            }
        }
        else cout << 0;
    }
}