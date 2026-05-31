#include <iostream>
#include <vector>
#include <set>
#include <map>
#include<algorithm>

using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m;

    // Ma trận n đỉnh, m cạnh
    vector<vector<int>> matrix(n , vector<int>(n, 0));
    int degrees[1000] = {0};

    for(int i = 0; i < m; i ++) {
        int u, v, w; // Trọng số cạnh i 
        cin >> u >> v >> w;

        matrix[u-1][v-1] = w;
        matrix[v-1][u-1] = w;

        degrees[u] ++;
        degrees[v] ++;
    }

    if(t == 2) {
        cout << n << endl;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] != 0) cout << matrix[i][j] << " ";
                else cout << (j == i ? 0 : 10000) << " ";
            }
            cout << endl;
        }
    }
    else for(int i = 1; i <= n; i ++) cout << degrees[i] << " ";
}