#include <iostream>
#include <vector>
#define IN first 
#define OUT second
using namespace std;
int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n; 
    cin >> t >> n;
    vector<pair<int, int>> degs(n); // <in, out>
    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i += 1) {
        int k, val;
        cin >> k;
        for(int j = 0; j < k; j ++) {
            cin >> val;

            degs[val - 1].IN += 1;

            edges.push_back({i + 1, val});
        }

        degs[i].OUT = k;
    }

    if(t == 1) {
        for(int i = 0; i < degs.size(); i += 1)
            cout << degs[i].IN << " " << degs[i].OUT << endl;
    }
    else {
        cout << n << " " << edges.size() << endl;

        for(int i = 0; i < edges.size(); i ++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }
}