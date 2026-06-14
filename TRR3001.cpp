// Đồ thị vô hướng

// Trường hợp 1. T == 1
// Euler: G liên thông và mọi đỉnh có bậc chẵn
// Nửa Euler: G liên thông và tồn tại đúng 2 đỉnh có bậc lẻ
// Nếu có 0 đỉnh bậc lẻ: G là Euler, không phải chỉ là Nửa Euler

// Trường hợp 2. T == 2
// Tìm đường đi, chu trình Euler
// Thuật toán:
//      1. Đưa start vào stack
//      2. While stack != emty:
//              u = top, v = -1
//              for i = 0; i < n; i ++:
//                  if(matrix[u][i]) v = i; break;
//              if v != 0: cho v vào stack, đánh dấu cạnh u, v đã duyệt
//              else: cho u vào chu trình, stack.pop
//      3. Đảo ngược chu trình & xuất ra

// Kiểm tra 1 đồ thị có liên thông không:
// DFS/BFS tại 1 đỉnh, nếu có n đỉnh được duyệt -> Liên thông

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int t, n, u, lt = 0;
vector<vector<int>> matrix(105, vector<int>(105, 0)); // ma trận kề
vector<bool> visited(1000, false);
vector<int> adj[1000];


void DFS(int u) {
    visited[u] = true;
    lt += 1;

    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

// Tìm chu trình Euler tại 1 đỉnh u
void EulerCycle(int start) {
    stack<int> st;
    vector<int> cycle;

    st.push(start);
    while(!st.empty()) {
        int u = st.top();
        int v = -1;

        // Tìm cạnh (u, v) chưa được duyệt
        for(int i = 0; i < n; i ++) {
            if(matrix[u][i]) {
                v = i;
                break;
            }
        }

        if(v != -1) {
            matrix[u][v] = matrix[v][u] = 0;
            st.push(v);
        }
        else {
            cycle.push_back(u);
            st.pop();
        }
    }
    
    reverse(cycle.begin(), cycle.end());
    for(auto val : cycle) cout << val + 1 << " "; // Vì chạy từ 0 -> n - 1
}

int main() {
    if(!freopen("CT.INP", "r", stdin));
    if(!freopen("CT.OUT", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t >> n;
    if(t == 2) cin >> u;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];

            if(matrix[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    if(t == 1) {
        DFS(0);
        if(lt == n) { // Nếu đồ thị liên thông
            // Tìm số lượng deg chẵn
            int chan = 0;
            for(int i = 0; i < n; i ++) {
                if(adj[i].size() % 2 == 0) chan += 1;
            }

            // Nếu số lượng đỉnh có deg chẵn == n -> Euler
            // Nếu số lượng đỉnh có deg chẵn == n - 2 -> Nửa Euler
            // Ngược lại: Không Euler
            if(chan == n) cout << 1;
            else if(chan == n - 2) cout << 2;
            else cout << 0;
        }
        else cout << 0;
    }

    else {
        EulerCycle(u-1);
    }
}