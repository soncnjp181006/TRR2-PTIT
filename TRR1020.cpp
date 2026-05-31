#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

#define IN first
#define OUT second

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t >> n;
    vector<pair<int, int>> degs(n);
    vector<pair<int, int>> edges;
    
    for(int i = 0; i < n; i += 1) {
        int k, val;
        cin >> k;
        for(int j = 0; j < k; j += 1) {
            cin >> val;

            degs[val - 1].IN += 1;

            edges.push_back({i, val-1});
        } 
        degs[i].OUT = k;
    } 

    if(t == 1) 
        for(int i = 0; i < degs.size(); i += 1)
            cout << degs[i].IN << " " << degs[i].OUT << endl;
    else {
        cout << n << " " << edges.size() << endl;

        vector<vector<int>> matrix(n, vector<int>(edges.size()));

        // Duyệt qua các cột
        for(int i = 0; i < edges.size(); i ++) {
            auto [u, v] = edges[i];

            matrix[u][i] = 1;
            matrix[v][i] = -1;
        }

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < edges.size(); j ++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
}