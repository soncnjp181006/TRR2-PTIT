#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> adj[1000];
vector<int> visited;

void bfs(vector<int>& visited, int start, int x) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto val : adj[u]) {
            if(val != x && !visited[val]) {
                q.push(val);
                visited[val] = 1;
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
    visited.assign(n, 0);    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;
            if(val) adj[i].push_back(j);
        }
    }

    // Tìm số thành phần liên thông ban đầu
    int k = 0;
    
    for(int i = 0; i < n; i += 1) {
        if(!visited[i]) {
            bfs(visited, i, -1);
            k ++;
        }
    }

    // Tìm các đỉnh trụ
    vector<int> v;
    for(int i = 0; i < n; i ++) {
        visited.assign(n, 0);
        int cnt = 0;
        for(int j = 0; j < n; j += 1) {
            if(j != i && !visited[j]) {
                bfs(visited, j, i);
                cnt += 1;
            }
        }

        if(cnt > k) v.push_back(i + 1);
    }

    cout << v.size() << endl;
    for(auto x : v) cout << x << " ";

}