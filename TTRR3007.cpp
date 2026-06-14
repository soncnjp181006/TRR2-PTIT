// Chu trình Hamilton
// Tìm tất cả chu trình Hamilton bắt đầu tại đỉnh u, của ma trận kề
// Nếu có chu trình in từng chu trình, dòng cuối in số lượng t chu trình
// Nếu không có chu trình, in 0

// Thuật toán quay lui

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n, u;
vector<vector<int>> matrix(105, vector<int>(105, 0));
vector<int> path(105);      // path[k] là đỉnh thức k trong đường đi hiện tại
bool visited[105];          // visited[v] = true nếu đỉnh v đã được dùng
vector<vector<int>> Cycles; // lưu các chu trình Hamilton tìm được

void Try(int k) {
    // k là vị trí đang cần chọn trong dãy path

    for(int v = 1; v <= n; v ++) {
        // Chọn v nếu:
        // 1. v chưa đi qua
        // 2. Có cạnh từ path[k-1] đến v

        if(!visited[v] && matrix[path[k-1]][v] == 1) {
            path[k] = v;
            visited[v] = true;

            // Nếu đã chọn đủ n đỉnh
            if(k == n) {
                // Kiểm tra có cạnh từ đỉnh cuối quay về u không
                if(matrix[path[n]][u] == 1) {
                    vector<int> cycle;

                    // Lưu n đỉnh của chu trình
                    for(int i = 1; i <= n; i ++) {
                        cycle.push_back(path[i]);
                    }

                    // Thêm đỉnh u ở cuối để biểu diễn chu trình khép kín
                    cycle.push_back(u);

                    Cycles.push_back(cycle);
                }
            }
            else {
                // Chưa đủ n đỉnh thì tiếp tục chọn đỉnh kế tiếp
                Try(k + 1);
            }

            // Quay lui: bỏ chọn v
            visited[u] = false;
        }
    }
}

int main() {
    if(!freopen("CT.INP", "r", stdin));
    if(!freopen("CT.OUT", "w", stdout));
    cin >> n >> u;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j ++) {
            cin >> matrix[i][j];
        }
    }

    // Khởi tạo chu trình bắt đầu tại u
    path[1] = u;
    visited[u] = true;
    
    // Bắt đầu chọn ở vị trí thứ 2
    Try(2);

    if(Cycles.empty()) cout << 0;
    else {
        for(auto cycle : Cycles) {
            for(auto v : cycle) {
                cout << v << " ";
            }
            cout << endl;
        }
        cout << Cycles.size();
    }

}