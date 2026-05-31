#include <vector>
#include <iostream>
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

void Matrix() {
    cout << n << " " << m << endl;

    // Cách chuyển sang ma trận liên thuộc
    // 1. Tìm các cạnh (u_i, v_i)
    // 2. Lập ma trận: 1 cạnh (u_i, v_i) là một cột

    // Bước 1. Tạo ma trận n x m (n hàng, m cột)
    // Bước 2. Duyệt qua từng cột và điền
    // Điền như nào: Từ hàng đầu đánh dấu số 1 -> n ở mỗi hàng
    vector<vector<int>> matrix(n, vector<int>(m));

    // Duyệt qua các cột
    for(int j = 0; j < m; j ++) {
        // Giá trị trong pair là chỉ mục trục y
        // Điền vào bảng
        matrix[p[j].first-1][j] = 1;
        matrix[p[j].second-1][j] = 1;   
    }

    for(int i = 0; i < matrix.size(); i ++) {
        for(int j = 0; j < matrix[0].size(); j ++) {
            cout << matrix[i][j] << " ";
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
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }


    if(t == 1) Degree();
    else Matrix();
}