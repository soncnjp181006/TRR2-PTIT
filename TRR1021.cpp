#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;

    vector<pair<int, int>> degs(n); // <in, out>
    #define IN first
    #define OUT second

    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < n; i ++) {
        for(int j = 0;  j < n; j ++) {
            int val;
            cin >> val;

            // 10000 -> 0
            if(val == 10000) val = 0;

            // Ma trận có trọng số
            // Deg Out -> Số ô khác 0 trên hàng -> Deg out của index Hàng
            // Deg In -> Số ô khác 0 trên cột -> Deg in của index cột 

            // Tìm deg in, out
            if(val) {
                degs[j].IN += 1;  // Deg in tổng cột
                degs[i].OUT += 1; // Deg out tổng hàng
            }

            // Tìm Cạnh, Trọng số <Start, End, Weight>
            if(val) {
                edges.push_back({i + 1, j + 1, val});
            }
        }
    }
    
    if(t == 1) {
        for(int i = 0; i < degs.size(); i ++) {
            cout << degs[i].IN << " " << degs[i].OUT << endl;
        }
    }
    else {
        cout << n << " " << edges.size() << endl;
        for(int i = 0; i < edges.size(); i ++) {
            auto[u, v, w] = edges[i];
            cout << u << " " << v << " " << w << endl;
        }
    }
}