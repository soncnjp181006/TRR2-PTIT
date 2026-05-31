// Đỉnh trụ:
// Bỏ đỉnh x và các cạnh liên thuộc của x đi 
// -> Đồ thị tăng số thành phần liên thông -> x là đỉnh trụ

#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> adj[1000];

// Dfs duyệt đồ thị
// Không duyệt đỉnh bị bỏ đi
void dfs(vector<int>& visited, int u, int x) {
    visited[u] = 1;

    for(auto val : adj[u]) {
        if(val != x && !visited[val]) {
            dfs(visited, val, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if(!freopen("TK.INP", "r", stdin)) return 0;
    if(!freopen("TK.OUT", "w", stdout)) return 0;

    cin >> n;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;

            if(val) adj[i].push_back(j);
        }
    }

    // Đếm số thành phần liên thông ban đầu
    int k = 0;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i ++) {
        if(!visited[i]) {
            dfs(visited, i, -1);
            k += 1;
        }
    }

    // Tìm các đỉnh trụ
    vector<int> v;
    for(int i = 0; i < n-1; i ++) {
        int cnt = 0;
        visited.assign(n ,  0);
        for(int j = 0;  j < n; j ++) {
            if(j != i && !visited[j]) {
                dfs(visited, j, i);
                cnt ++;
            }
        }

        if(cnt > k) {
            v.push_back(i + 1);
        }
    }

    cout << v.size() << endl;
    for(auto x : v) {
        cout << x << " ";
    }
}