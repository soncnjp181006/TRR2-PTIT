// Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, s, t;
vector<vector<int>> matrix(1005, vector<int>(1005, 0));
vector<int> d(1005, INF);
vector<int> parent(1005, -1);
vector<bool> used(1005, false);

void dijkstra() {
    d[s] = 0;
    
    // Lặp tối đa n lần
    for(int k = 1; k <= n; k++) {
        int u = -1;
        int minDist = INF;

        // Chọn đinh chưa xét có d[u] nhỏ nhất
        for(int i = 1; i <= n; i ++) {
            if(!used[i] && d[i] < minDist) {
                minDist = d[i];
                u = i;
            }
        }

        // Không còn đỉnh nào có thể đi tới
        if(u == -1) break;

        used[u] = true; // Đánh dấu đã sử dụng đỉnh u

        // Tối ưu các đỉnh kề của u
        for(int v = 1; v <= n; v ++) {
            // Có cạnh u ->  khi matrix[u][v] != 10000
            if(!used[v] && matrix[u][v] != 10000 && d[v] > d[u] + matrix[u][v]) {
                d[v] = d[u] + matrix[u][v];
                parent[v] = u;
            }
        }
    }
}

vector<int> getPath() {
    vector<int> path;
    int curr = t;
    while(curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    
    cin >> n >> s >> t;
    
    for(int i = 1; i <= n; i += 1) {
        for(int j = 1; j <= n; j += 1) {
            cin >> matrix[i][j];
        } 
    }

    dijkstra();

    // Nếu không có đường đi từ s đến t
    if(d[t] == INF) {
        cout << 0;
    }
    else {
        cout << d[t] << endl;
        vector<int> path = getPath();
        for(int v : path)
            cout << v << " ";
    }
}