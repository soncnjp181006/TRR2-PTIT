// Đồ thị có hướng

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int t, n, u;

int edge_id = 0;
vector<pair<int, int>> adj[1005]; // <v, id cạnh uv>
bool used[1000005];

int in[1005], out[1005];

vector<int> EulerCycle(int start) {
    stack<int> st;
    vector<int> path;
    st.push(start);

    while(!st.empty()) {
        // Lấy đỉnh u trên cùng
        int u = st.top();

        // Xóa các cạnh đã dùng ra khỏi danh sách kề
        // Duyệt, loại bỏ từng đỉnh ở cuối danh sách kề về đầu
        while(!adj[u].empty() && used[adj[u].back().second]) {
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
    if(!freopen("CT.INP", "r", stdin)) return 0;
    if(!freopen("CT.OUT", "w", stdout)) return 0;

    cin >> t >> n;
    if(t == 2) cin >> u;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int val;
            cin >> val;

            if(val) {
                edge_id += 1;
                adj[i].push_back({j, edge_id});

                // Tăng bán bậc ra của i
                out[i] += 1;

                // Tăng bán bậc vào của j
                in[j] += 1;
            }
        }
    }

    // Kiểm tra đồ thị có hướng là Euler hay nửa Euler
    if(t == 1) {
        // Euler: in(u) == out(u)
        // Nửa Euler: có 1 đỉnh out(u) = in(u) + 1
        //             có 1 đỉnh in(u) = out(u) + 1
        //             các đỉnh còn lại in(u) == out(u)
        // Không phải Euler hoặc nửa Euler: không thỏa mãn 2 đk trên
        int start = 0, endd = 0;

        for(int i = 1; i <= n; i ++) {
            if(in[i] == out[i]) continue;
            else if(out[i] == in[i] + 1) start += 1;
            else if(in[i] == out[i] + 1) endd += 1;
            else {
                cout << 0;
                return 0;
            }
        }

        if(start == 0 && endd == 0) cout << 1;
        else if(start == 1 && endd == 1) cout << 2;
        else cout << 0;
    }
    else {
        vector<int> result = EulerCycle(u);

        // In ngược lại vector
        for(int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }
}