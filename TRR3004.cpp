// Đồ thị có hướng
// Trường hợp 1. T == 1
// Euler:
// G liên thông yếu trên các đỉnh có bậc > 0 và mọi đỉnh u có:
//      in[u] == out[u]

// Nửa Euler:
// G liên thông yếu trên các đỉnh có bậc > 0 và tồn tại đúng:
//      1 đỉnh start: out[u] - in[u] == 1
//      1 đỉnh end:   in[u] - out[u] == 1
// các đỉnh còn lại:
//      in[u] == out[u]

// Nếu mọi đỉnh đều có in[u] == out[u]:
// G là Euler, không phải chỉ là Nửa Euler

// Thuật toán:
// Nhập ma trận, if(matrix[i][j]) adj[i].push(j), adj[j].push(j), outdeg[i] += 1, indeg[j] += 1
// DFS(u), kiểm tra số lượng đỉnh duyệt có bằng n không
// Nếu số lượng đỉnh duyệt bằng n -> Liên thông yếu -> Kiểm tra Euler, Không Euler


// Trường hợp 1. T == 1
// Thuật toán:
// root == -1
// for i = 0 -> n-1: if indeg[i] + outdeg[i] > 0: root = i; break
// if root == -1: cout << 0; return 0
// for i = 0 -> n-1: if indeg[i] + outdeg[i] > 0 && !visited[i]: cout << 0; return 0
// start = 0, end = 0
// for i = 0 -> n-1:
//      if(indeg[i] == outdeg[i]) continue
//      else if(outdeg[i] - indeg[i] == 1) start +=1
//      else if(indeg[i] - outdeg[i] == 1) end += 1
//      else cout << 0; return 0
// if start == end == 0: cout << 1
// if start == end == 1: cout << 2
// else cout << 0 


// Trường hợp 2. T == 2
// Tìm đường đi, chu trình Euler
// Thuật toán:
//      1. Đưa start vào stack
//      2. While stack != empty:
//              u = stack.top, v = -1
//              for i = 0; i < n; i ++: if(matrix[u][v]) v = i; break
//              if u != -1: stack.push(v), matrix[u][v] = 0;
//              else: cycle.push_back(u); stack.pop()
//      3. Đảo ngược cycle & xuất

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int t, n, u;
vector<vector<int>> matrix(1005, vector<int>(1005, 0));
vector<bool> visited(1000, false);
vector<int> adj[1000];
vector<int> indeg(1000), outdeg(1000);

void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void EulerCycle(int start) {
    stack<int> st;
    vector<int> cycle;
    st.push(start);

    while(!st.empty()) {
        int u = st.top(), v = -1;

        for(int i = 0; i < n; i ++) {
            if(matrix[u][i]) {
                v = i;
                break;
            }
        }

        if(v != -1) {
            st.push(v);
            matrix[u][v] = 0;
        }
        else {
            cycle.push_back(u);
            st.pop();
        }
    }
    reverse(cycle.begin(), cycle.end());
    for(auto x : cycle) cout << x + 1 << " "; // Do chạy từ 0 -> n -1
}

int main() {
    if(!freopen("CT.INP", "r", stdin));
    if(!freopen("CT.OUT", "w", stdout));
    cin >> t >> n;
    if(t == 2) cin >> u;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];
            if(matrix[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i); // Bỏ hướng cạnh

                indeg[j] += 1;
                outdeg[i] += 1;
            }
        }
    }

    if(t == 1) {
        int root = -1;

        // Tìm đỉnh để DFS
        for(int i = 0; i < n; i++) {
            if(indeg[i] + outdeg[i] > 0) {
                root = i;
                break;
            }
        }

        // Nếu không có đỉnh
        if(root == -1) {
            cout << 1;
            return 0;
        }

        dfs(root);

        // Kiểm tra đồ thị có liên thông yếu không
        // Nếu không, xuất ra 0
        for(int i = 0; i < n; i++) {
            if(indeg[i] + outdeg[i] > 0 && !visited[i]) {
                cout << 0;
                return 0;
            }
        }

        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            if(indeg[i] == outdeg[i]) continue;
            else if(outdeg[i] - indeg[i] == 1) start++;
            else if(indeg[i] - outdeg[i] == 1) end++;
            else {
                cout << 0;
                return 0;
            }
        }

        if(start == 0 && end == 0) cout << 1;
        else if(start == 1 && end == 1) cout << 2;
        else cout << 0;
    }

    else {
        EulerCycle(u - 1);
    }

}
