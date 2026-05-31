#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t;

    cin >> n;

    vector<pair<int, int>> degs(n); // <in, out>
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        int k, val;
        cin >> k;
        for(int j = 0; j < k; j ++) {
            cin >> val;

            degs[val - 1].first += 1;

            matrix[i][val-1] = 1;
        }
        degs[i].second = k; // Deg out
    }



    if(t == 1) {
        for(int i = 0; i < degs.size(); i ++)
            cout << degs[i].first << " " << degs[i].second << endl;
    }   
    else {
        cout << n << endl;
        for(int i = 0; i < degs.size(); i ++) {
            for(int j = 0; j < degs.size(); j ++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
}