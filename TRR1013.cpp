#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;

    vector<pair<int, int>> degs(n);
    map<int, vector<int>> vertexs;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j ++) {
            int val;
            cin >> val;

            if(val) {
                degs[j].first += 1;     // Deg in
                degs[i].second += 1;    // Deg out
                vertexs[i+1].push_back(j + 1);                
            }
        }
    }

    if(t == 1) {
        for(int i = 0; i < degs.size(); i ++)
            cout << degs[i].first << " " << degs[i].second << endl;
    }
    else {
        cout << n << endl;
        for(auto it = vertexs.begin(); it != vertexs.end(); it ++) {
            cout << it -> second.size() << " ";
            for(int i = 0; i < it -> second.size();  i++) {
                cout << it -> second[i] << " ";
            }
            cout << endl;
        }
    }
}