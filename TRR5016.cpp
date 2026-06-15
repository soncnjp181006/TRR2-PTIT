#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Sử dụng 1 tỷ thay cho 10000 để đại diện cho vô cùng

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> nxt(n + 1, vector<int>(n + 1, -1));

    // Đọc ma trận trọng số và khởi tạo
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w == 10000 && i != j) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = w;
                if (i != j && w != 0) {
                    nxt[i][j] = j;
                }
            }
        }
    }

    // Thuật toán Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    int max_dist = -1;
    int best_u = -1, best_v = -1;

    // Tìm cặp (u, v) có đường đi ngắn nhất mang giá trị lớn nhất
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u != v && dist[u][v] != INF && dist[u][v] > max_dist) {
                max_dist = dist[u][v];
                best_u = u;
                best_v = v;
            }
        }
    }

    // In kết quả
    if (max_dist == -1 || max_dist == 0) {
        cout << 0 << "\n";
    } else {
        cout << best_u << " " << best_v << " " << max_dist << "\n";
        
        // Truy vết đường đi
        vector<int> path;
        int curr = best_u;
        while (curr != best_v) {
            path.push_back(curr);
            curr = nxt[curr][best_v];
        }
        path.push_back(best_v);

        // In đường đi
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}