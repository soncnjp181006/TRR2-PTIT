// Cạnh cầu
// e = (u, v)
// Nếu xóa e đi, giữ nguyên các đỉnh u, v
// -> Số thành phần liên thông tăng lên

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int n;
vector<int> adj[1000];
vector<pair<int, int>> edges; // Danh sách cạnh

// e = (start, end)
void dfs(vector<int>& visited, int u, int start, int end) {
    visited[u] = 1;

    for(auto v : adj[u]) {
        if(!(u == start && v == end) && !(u == end && v == start) && !visited[v]) {
            dfs(visited, v, start, end);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if(!freopen("TK.INP", "r", stdin)) return 0;
    if(!freopen("TK.OUT", "w", stdout)) return 0;

    cin >> n;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;
            if(val) {
                adj[i].push_back(j);
                edges.push_back({i, j}); // Tìm các cạnh
            }
        }
    }

    // Tìm các thành phần liên thông ban đầu
    int k = 0;
    for(int i = 0; i < n; i ++) {
        if(!visited[i]) {
            k ++;
            dfs(visited, i, -1, -1);
        }
    }

    // Tìm các thành phần liên thông mới
    vector<pair<int, int>> v;
    for(int i = 0; i < edges.size(); i ++) {
        visited.assign(n, 0);
        int cnt = 0;
        for(int j = 0; j < n; j ++) {
            if(!visited[j]) {
                dfs(visited, j, edges[i].first, edges[i].second);
                cnt += 1;
            }
        }

        if(cnt > k) {
            v.push_back(edges[i]);
        }
    }

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i ++)
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
}