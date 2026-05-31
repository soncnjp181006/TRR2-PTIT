#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m;

    vector<pair<int, int>> degs(n);
    vector<vector<int>> matrix(n, vector<int>(m));

    // Duyệt qua các cột
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;

        degs[u-1].second += 1;
        degs[v-1].first += 1;

        matrix[u-1][i] = 1;
        matrix[v-1][i] = -1;
    }

    if(t == 1) {
        for(int i = 0; i < degs.size(); i += 1)
            cout << degs[i].first << " " << degs[i].second << endl;
    }
    else {
        cout << n << " " << m << endl;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}