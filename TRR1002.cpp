#include <vector>
#include <iostream>

using namespace std;

int t, n;
vector<vector<int>> v;

void degree(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); i ++) {
        int cnt = 0;
        for(int j = 0; j < v.size(); j ++) {
            if(v[i][j] == 1) cnt += 1;
        }
        cout << cnt << " ";
    }
}

void Vertices(vector<vector<int>> v) {
    cout << n << endl;

    for(int i = 0; i < v.size(); i ++) {
        vector<int> p;
        for(int j = 0; j < v.size(); j ++) {
            if(v[i][j] == 1) p.push_back(j + 1);
        }
        cout << p.size() << " ";
        for(int c : p) cout << c << " ";
        cout << endl;
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

    if(t == 1) degree(v);
    else Vertices(v);
}