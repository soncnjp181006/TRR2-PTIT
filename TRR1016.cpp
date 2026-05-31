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
    
    int t, n , m;
    cin >> t >> n >> m;

    vector<pair<int, int>> degs(n); // Deg in, Deg out
    map<int, vector<int>> mp;            // <Số đỉnh kề, <Các đỉnh>>
    for(int i = 0; i < m; i += 1) {
        int u, v;
        cin >> u >> v;

        degs[u-1].second += 1;
        degs[v-1].first += 1;

        mp[u].push_back(v);
        // mp[v].push_back(u);
    }

    if(t == 1) {
        for(int i = 0; i < degs.size(); i ++)
            cout << degs[i].first << " " << degs[i].second << endl;
    }
    else {
        cout << n << endl;

        for(auto it = mp.begin(); it != mp.end(); it ++) {
            cout << it -> second.size() << " ";

            for(auto i = 0; i < it -> second.size(); i ++) 
                cout << it -> second[i] << " ";
            
                cout << endl;
        }
    }
}