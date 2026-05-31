// Liên thông mạnh, yếu

// Liên thông mạnh:
// + Là đồ thị có hướng
// + Với mọi cặp đỉnh u, v:
//   luôn tồn tại đường đi u -> v
//   và v -> u

// Không liên thông mạnh:
// + Là đồ thị có hướng
// + Tồn tại ít nhất 1 cặp đỉnh
//   không đi tới nhau được hai chiều

// Liên thông yếu:
// + Là đồ thị có hướng
// + Nếu bỏ hướng các cạnh,
//   đồ thị trở thành liên thông
//   [1 thành phần liên thông duy nhất]


// Dùng DFS để kiểm tra thành phần liên thông
// Với mọi đỉnh i:
// DFS từ i phải đi được tới toàn bộ n đỉnh
// => Liên thông mạnh


// ------------------------------------------------------ //
// Yêu cầu:
// 1 -> Nếu G liên thông mạnh
// 2 -> Nếu G liên thông yếu
// 0 -> Nếu G không liên thông mạnh
//      và không liên thông yếu

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> adj_ch[1000]; // Có hướng
vector<int> adj_vh[1000]; // Vô hướng

// DFS
void dfs(vector<int>& visited, vector<int> adj[], int u) {
    visited[u] = 1;

    for(auto x : adj[u]) {
        if(!visited[x]) {
            dfs(visited, adj, x);
        }
    }
}

int main() {
    if(!freopen("TK.INP", "r", stdin)) return 0;
    if(!freopen("TK.OUT", "w", stdout)) return 0;

    int n;
    cin >> n;

    // Nhập ma trận kề
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;

            if(val) {
                // Đồ thị có hướng
                adj_ch[i].push_back(j);

                // Bỏ hướng cạnh
                // i -> j thành i -- j
                adj_vh[i].push_back(j);
                adj_vh[j].push_back(i);
            }
        }
    }

    // 1. Kiểm tra liên thông mạnh
    //
    // DFS từ từng đỉnh
    // Nếu có đỉnh không đi được hết
    // => Không liên thông mạnh

    bool check_ltm = 1;

    for(int i = 0; i < n; i++) {

        vector<int> visited(n, 0);

        dfs(visited, adj_ch, i);

        // Tổng visited != n
        // => còn đỉnh chưa thăm
        if(accumulate(visited.begin(), visited.end(), 0) != n) {
            check_ltm = 0;
            break;
        }
    }

    // Liên thông mạnh
    if(check_ltm) {
        cout << 1;
    }

    else {
        // 2. Kiểm tra liên thông yếu
        //
        // Bỏ hướng các cạnh
        // DFS 1 lần
        // Nếu đi hết -> Liên thông yếu
        // Không đi hết -> Không liên thông

        vector<int> visited(n, 0);

        dfs(visited, adj_vh, 0);

        if(accumulate(visited.begin(), visited.end(), 0) == n) {
            cout << 2;
        }

        else {
            cout << 0;
        }
    }
}