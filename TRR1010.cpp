#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    set<tuple<int, int, int>> edges;

    int degree[1000] = {0}; 
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];

            // Không có cạnh nối -> 1000 hoặc 0 -> đưa hết về 0
            if(matrix[i][j] == 10000) matrix[i][j] = 0;

            if(matrix[i][j] != 0) {
                degree[i+1] += 1;
                // edges.push_back({i + 1, j + 1, matrix[i][j]});
                edges.insert({min(i + 1, j + 1), max(i + 1, j + 1), matrix[i][j]});
            }
        }
    }


    if(t == 1) for(int i = 1; i <= n; i += 1) cout << degree[i] << " ";
    else {
        cout << n << " " << edges.size() << endl;
        vector<tuple<int, int, int>> result(edges.begin(), edges.end());
        for(int i = 0; i < result.size(); i ++) {
            auto [u, v, w] = result[i];
            cout << u << " " << v << " " << w << endl;
        }
    }
    return 0;
}