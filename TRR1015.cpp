#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m; // n = v, m = e

    vector<pair<int, int>> degs(n); // Deg in, Deg out

    // Ma trận kề
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < m; i += 1) {
        int u, v;
        cin >> u >> v;

        degs[u-1].second += 1;
        degs[v-1].first += 1;

        matrix[u-1][v-1] = 1;
    } 

    if(t == 1) {
        for(int i = 0; i < degs.size(); i ++) {
            cout << degs[i].first << " " << degs[i].second << endl;
        }
    }
    else {
        cout << n << endl;
        for(int i = 0; i < matrix.size(); i ++) {
            for(int j = 0; j < matrix[0].size(); j ++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
}