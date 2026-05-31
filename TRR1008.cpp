#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int t, n;
vector<pair<int, vector<int>>> vp;

int main() {
    if(!(freopen("DT.INP", "r", stdin))) return 0;
    if(!(freopen("DT.OUT", "w", stdout))) return 0;
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t >> n;

    int degree[1000] = {0};

    set<pair<int, int>> sp;

    for(int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        degree[i + 1] = k; // Số bậc

        for(int j = 0; j < k; j ++) {
            int val;
            cin >> val;

            if(i + 1 < val) sp.insert({i + 1, val});
            else sp.insert({val, i + 1});
        }
    }

    if(t == 1) {
        for(int i = 1; i <= n ; i += 1) {
            cout << degree[i] << " ";
        }
    }
    else {
        cout << n << " " << sp.size() << endl;

        for(auto [a, b] : sp) {
            cout << a << " " << b << endl;
        }
    }
   
    return 0;
}