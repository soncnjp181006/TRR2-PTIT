// Thành phần liên thông trong đồ thị vô hướng
// Tập hợp các đỉnh mà tồn tại đường đi từ đỉnh đầu -> cuối
// ví dụ, đồ thị có 5 đỉnh: 1 - 2 - 3, 4 -5
// 2 thành phần liên thông: {1, 2, 3}, {4, 5}

// Thuật toán DFS tìm thành phần liên thông

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, lt = 0;
vector<int> adj[1000];
vector<int> visited;
vector<vector<int>> PATHS;

void dfs(vector<int>& path, int u) {
    visited[u] = 1;
    path.push_back(u);

    for(auto x : adj[u]) {
        if(!visited[x]) {
            dfs(path, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(!freopen("TK.INP", "r", stdin));
    if(!freopen("TK.OUT", "w", stdout));

    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    visited.assign(n , 0);

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];

            // Tìm danh sách kề
            if(matrix[i][j])
                adj[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i ++) {
        // Nếu chưa thăm đỉnh i 
        if(!visited[i]) {
            vector<int> path;
            dfs(path,i);
            lt += 1;

            sort(path.begin(), path.end()); // Sắp xếp để theo thứ tự tăng
            
            PATHS.push_back(path);
        }
    }
    
    cout << lt << endl;
    for(auto path : PATHS) {
        for(auto x : path) cout << x + 1 << " ";
        cout << endl;
    }
}