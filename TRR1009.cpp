#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t, n;
    int degree[1000] = {0};

    cin >> t >> n;

    set<pair<int, int>> sp;

    // Mỗi dòng là 1 đỉnh
    for(int i = 0; i < n; i ++) {
        int k;
        cin >> k;

        degree[i+1] = k;
        
        for(int j = 0; j < k; j ++) {
            int val;
            cin >> val;

            // Không lấy khuyên vì không liên thuộc
            if(val < i+1) sp.insert({val, i+1});
            else if(val > i+1) sp.insert({i+1, val});
        }
    }

    if(t == 1) for(int i = 1;  i <= n; i ++) cout << degree[i] << " ";
    else {
        vector<pair<int, int>> v(sp.begin(), sp.end());

        cout << n << " " << v.size() << endl;

        vector<vector<int>> matrix(n, vector<int>(v.size(), 0));

        // Duyệt qua từng cột của ma trận matrix
        // Số cột của ma trận matrix = số cạnh trong v
        for(int i = 0; i < v.size(); i += 1) {
            matrix[v[i].first - 1][i] = 1;
            matrix[v[i].second - 1][i] = 1;
        }

    
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < v.size(); j ++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

}