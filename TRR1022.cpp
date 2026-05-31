#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m;

    vector<pair<int, int>> degs(n);
    vector<vector<int>> matrix(n, vector<int>(n, 10000)); // Ma trận trọng số (kề)

    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;


        degs[u-1].second += 1; // Deg in
        degs[v-1].first += 1;  // Deg out

        matrix[u-1][v-1] = w;
    }

    if(t == 1)
        for(int i = 0; i < degs.size(); i += 1)
            cout << degs[i].first << " " << degs[i].second << endl;
    else {
        cout << n << endl;
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < n; j += 1) {
                if(matrix[i][i] == 10000) matrix[i][i] = 0;
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}