#include <iostream>
#include <vector>
#include <map>
using namespace std;

int t, n, m;
vector<pair<int, int>> p;

void Degree() {
    int degree[1000] = {0};
    for(int i = 0; i < m; i ++) {
        degree[p[i].first] ++;
        degree[p[i].second] ++;
    }

    for(int i = 1; i <= n; i ++) {
        cout << degree[i] << " ";
    }
}

void Neighbor() {
    cout << n << endl;
    map<int, vector<int>> mp;

    for(int i = 0; i < m; i ++) {
        mp[p[i].first].push_back(p[i].second);
        mp[p[i].second].push_back(p[i].first);
    }

    for(int i = 1; i <= n; i ++) {
        cout << mp[i].size() << " ";

        for(int val: mp[i]) {
            cout << val << " ";
        }

        cout << endl;
    }
}

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t >> n >> m;
    p.resize(m);

    for(int i = 0; i < m; i += 1) {
        cin >> p[i].first >> p[i].second;
    } 
 
    if(t == 1) Degree();
    else Neighbor();
}