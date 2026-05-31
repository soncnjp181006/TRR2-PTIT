#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int t, n;
vector<vector<int>> v;

void degree(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i ++) {
        int cnt = 0;
        for(int j = 0; j < v[0].size(); j ++) {
            if(v[i][j] == 1) cnt += 1;
        }
        cout << cnt << " ";
    }
}

void edge(vector<vector<int>> v) {
    vector<pair<int, int>> p;
    for(int  i = 0; i < v.size(); i ++) {
        for(int j = i + 1; j < v[0].size(); j ++) {
            if(v[i][j] == 1) p.push_back({i + 1, j + 1});
        }
    }
    cout << n << " " << p.size() << endl;

    for(int i = 0; i < p.size(); i ++) {
        cout << p[i].first << " " << p[i].second << endl;
    }
}

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t >> n;
    v.assign(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> v[i][j];
        }
    }

    if(t == 1) {
        degree(v);
    }
    else {
        edge(v);
    }

    return 0;
}