#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> adj[1000];
vector<pair<int, int>> edges;

void bfs(vector<int>& visited, int x, int start, int end) {
    visited[x] = 1;
    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!(u == start && v == end) && !(u == end && v == start) && !visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    vector<int> visited(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;
            if(val && i < j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                edges.push_back({i, j});
            }
        }
    }

    // Tìm số thành phần liên thông ban đầu 
    int k = 0;
    for(int i = 0; i < n; i ++) {
        if(!visited[i]) {
            bfs(visited, i, -1, -1);
            k += 1;
        }
    }

    // Tìm số cạnh cầu
    vector<pair<int, int>> v;
    for(int i = 0; i < edges.size(); i ++) {
        int cnt = 0;
        visited.assign(n, 0);
        for(int j = 0; j < n; j ++) {
            if(!visited[j]) {
                bfs(visited, j, edges[i].first, edges[i].second);
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