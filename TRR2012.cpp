// Thành phần liên thông trong đồ thị vô hướng
// Tập hợp các đỉnh mà tồn tại đường đi từ đỉnh đầu -> cuối
// ví dụ, đồ thị có 5 đỉnh: 1 - 2 - 3, 4 -5
// 2 thành phần liên thông: {1, 2, 3}, {4, 5}

// Thuật toán BFS tìm thành phần liên thông

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, lt = 0;
vector<vector<int>> PATHS;
vector<int> visited;
vector<int> adj[1000];

void bfs(int start) {
    vector<int> components;
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        components.push_back(u); // Thu thập đỉnh vào thành phần hiện tại

        for(auto x : adj[u]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }

    sort(components.begin(), components.end());
    PATHS.push_back(components);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(!freopen("TK.INP", "r", stdin));
    if(!freopen("TK.OUT", "w", stdout));

    cin >> n;  
    visited.assign(n, 0); // Khởi tạo mảng visited với n phần tử     
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n ; j += 1) {
            cin >> matrix[i][j];

            if(matrix[i][j])
                adj[i].push_back(j);
        } 
    }

    for(int i = 0; i < n; i ++) {
        if(!visited[i]) {
            bfs(i);
        }
    }

    lt = PATHS.size();
    cout << lt << endl;
    for(auto const& comp : PATHS) {
        for(auto node : comp) cout << node + 1 << " "; // +1 vì đề bài là 1-based
        cout << endl;
    }
    return 0;
}