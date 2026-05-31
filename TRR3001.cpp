// Đồ thị vô hướng

// Đồ thị vô hướng G là đồ thị Euler:
// + Đồ thị liên thông (bỏ các đỉnh cô lập)
// + Với mọi v thuộc V: deg(v) % 2 == 0

// Đồ thị vô hướng G là đồ thị nửa Euler:
// + Đồ thị liên thông
// + Có 0 hoặc 2 deg(v) % 2 != 0
// 0 deg(v) % 2 != 0 -> Euler
// 2 deg(v) % 2 != 0 -> Nửa Euler

// Mô tả Thuật toán tìm chu trình/đường đi Euler:
// + Điều kiện: Đồ thị là Euler hoặc Nửa Euler
// + Đỉnh bắt đầu:
//      - Nếu đồ thị là Euler: Đỉnh nào cũng được
//      - Nếu đồ thị là nửa Euler: Bắt đầu tại 1 trong 2 đỉnh deg(v) % 2 != 0 (đỉnh có bậc lẻ)
// + Đi theo các cạnh chưa dùng
// + Xóa cạnh đã đi qua
// + Khi bí đường thì quay lui
// + Các đỉnh được lấy ra theo thứ tự ngược lại -> Chu trình Euler

// Thuật toán:
// + Bước 1. Chọn đỉnh bắt đầu u
// + Bước 2. push(u) vào stask
// While !stack.empty():
//      Lấy v trên cùng
//      if v còn cạnh chưa dùng:
//          Chọn đỉnh kề x
//          xóa cạnh (v, x)
//          push(x)
//      else: 
//          đưa v vào path
//          pop stack
// + Bước 3. Đảo ngược path

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int t, n, u;

// adj[u] = {v, id cạnh}
vector<pair<int, int>> adj[1005];

// used[id] = cạnh đã dùng chưa
bool used[200005];

int edge_id = 0;

// Thuật toán Hierholzer tìm chu trình / đường đi Euler
vector<int> EulerCycle(int start) {

    stack<int> st;
    vector<int> path;

    st.push(start);

    while(!st.empty()) {

        int u = st.top();

        // Xóa các cạnh đã dùng khỏi danh sách kề
        while(!adj[u].empty() &&
              used[adj[u].back().second]) {

            adj[u].pop_back();
        }

        // Nếu không còn cạnh để đi
        if(adj[u].empty()) {

            path.push_back(u);
            st.pop();
        }

        else {

            // Lấy cạnh chưa dùng
            auto [v, id] = adj[u].back();
            adj[u].pop_back();

            // Nếu cạnh đã dùng thì bỏ qua
            if(used[id]) continue;

            // Đánh dấu cạnh đã dùng
            used[id] = true;

            st.push(v);
        }
    }

    return path;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    if(!freopen("CT.INP", "r", stdin)) return 0;
    if(!freopen("CT.OUT", "w", stdout)) return 0;

    cin >> t >> n;

    // t = 2 -> tìm chu trình / đường đi Euler
    if(t == 2)
        cin >> u;

    // Nhập ma trận kề
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= n; j++) {

            int val;
            cin >> val;

            // Chỉ lấy nửa trên ma trận
            // để tránh thêm cạnh 2 lần
            if(i < j && val) {

                edge_id++;

                adj[i].push_back({j, edge_id});
                adj[j].push_back({i, edge_id});
            }
        }
    }

    // Kiểm tra Euler
    if(t == 1) {

        // odd = số đỉnh bậc lẻ
        int odd = 0;

        for(int i = 1; i <= n; i++) {

            if(adj[i].size() % 2 != 0)
                odd++;
        }

        // odd = 0 -> Euler
        // odd = 2 -> nửa Euler
        // odd > 2 -> không phải Euler

        if(odd == 0)
            cout << 1;

        else if(odd == 2)
            cout << 2;

        else
            cout << 0;
    }

    // Tìm chu trình / đường đi Euler
    else {

        vector<int> result = EulerCycle(u);

        // In ngược do Hierholzer backtrack
        for(int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }

    return 0;
}