#include <vector>
#include <iostream>
using namespace std;

int t, n, m;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t >> n >> m;

    // Tính bậc đỉnh
    if (t == 1) {

        vector<int> degree(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            degree[a]++;
            degree[b]++;
        }

        for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
    }

    // Tạo ma trận kề
    else {
        cout << n << endl; 
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            v[a - 1][b - 1] = 1;
            v[b - 1][a - 1] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}