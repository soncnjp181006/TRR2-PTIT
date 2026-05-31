#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<vector<int>> v;

void Degree() {
    for(int i = 0; i < n; i ++) {
        int cnt  = 0;
        for(int j = 0; j < n; j ++) {
            if(v[i][j] == 1) cnt += 1;
        }
        cout << cnt << " ";
    }
}

// Cách chuyển ma trần kề -> ma trận liên thuộc 
// Bước 1. Liệt kê các cạnh từ ma trận kề: e_i = (u_i, v_i)
// Bước 2. Lấy e_i là index ngang, dóng index dọc: u_i = 1, v_i = 1
void Matrix() {

    // Bước 1. Tìm các cạnh
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(v[i][j] == 1) p.push_back({i, j});
        }
    }

    cout << n << " " << p.size() << endl;
    
    // Bước 2. Tạo ma trận liên thuộc
    // n = n, m = p.size()
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < p.size(); j ++ ) {
            if(p[j].first == i || p[j].second == i) cout << 1 << " ";
            else cout << 0 << " ";
        }
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

    if(t == 1) Degree();
    else Matrix();
}