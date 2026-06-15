#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; 

struct Edge {
    int u, v, w;
};

int main() {
    // Đọc và ghi tệp theo yêu cầu bài toán
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    int n, s, t;
    if (!(cin >> n >> s >> t)) return 0;

    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (i != j && w != 10000) {
                edges.push_back({i, j, w});
            }
        }
    }

    vector<int> dist(n + 1, INF);
    vector<int> trace(n + 1, 0);

    dist[s] = 0;

    // Bước 1: Lặp n - 1 lần nới lỏng các cạnh
    for (int i = 1; i <= n - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                trace[v] = u;
            }
        }
    }

    // Bước 2: Kiểm tra chu trình âm (lặp lần thứ n)
    bool hasNegativeCycle = false;
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // Bước 3: In kết quả
    if (hasNegativeCycle) {
        cout << -1 << "\n";
    } else if (dist[t] == INF) {
        cout << 0 << "\n";
    } else {
        cout << dist[t] << "\n";
        
        vector<int> path;
        int curr = t;
        while (curr != 0) {
            path.push_back(curr);
            if (curr == s) break; // Đã lùi về tới đỉnh nguồn s
            curr = trace[curr];
        }
        
        // Đảo ngược lại để in từ s -> t
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}