// Cây khung nhỏ nhất
// Điều kiện tồn tại cây khung: G vô hướng liên thông

// Cây khung nhỏ nhất -> Đồ thị có trọng số
// Thuật toán tìm cây khung nhỏ nhất nếu duyệt theo đỉnh [Ma trận kề]: Prim

// Thuật toán Prim
// Prim(u):
//      visited[u] = true
//      while size(T) < n - 1:
//          tìm cạnh (x, y) min sao cho:
//              visited[x] = true
//              visited[y] = false
//          thêm (x, y) vào cây khung
//          visited[y] = true


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, u;
vector<vector<int>> matrix(1005, vector<int>(1005, 0));
bool visited[1005];

struct Edge {
    int u, v, w;
};

vector<Edge> T;
int totalWeight = 0;

void Prim(int u) {
    visited[u] = true;
    while(T.size() < n - 1) {
        int minWeight = INT_MAX;
        int x = -1, y = -1;

        for(int i = 1; i <= n; i ++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j ++) {
                    if(!visited[j] && matrix[i][j] < minWeight) {
                        x = i, y = j;
                        minWeight = matrix[i][j];
                    }
                }
            }
        }

        if(x == -1) return;
        visited[y] = true;
        totalWeight += minWeight;
        T.push_back({min(x, y), max(x, y), minWeight});
    }
}


int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> u;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> matrix[i][j];
        }
    }

    Prim(u);

    if(T.size() != n - 1) {
        cout << 0;
        return 0;
    }

    cout << totalWeight << endl;
    for(auto e : T)
        cout << e.u << " " << e.v << " " << e.w << endl;
}
