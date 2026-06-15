// Cây khung nhỏ nhất
// Điều kiện tồn tại cây khung: G vô hướng liên thông

// Cây khung nhỏ nhất -> Đồ thị có trọng số
// Thuật toán tìm cây khung nhỏ nhất nếu duyệt theo danh sách cạnh: Kurskal

// Thuật toán:
// 1. Đưa tất cả vào danh sách cạnh
// 2. Sắp xếp cạnh theo trọng số tăng dần
// 3. Duyệt từng cạnh nhỏ nhất
//         Nếu thêm cạnh đó -> không thạo chu trình:
//              Thêm vào cây khung nhỏ nhất
// 4. Dừng khi có n - 1 cạnh

// Mã giả:
// Kurskal():
//      sort danh sách cạnh theo trọng số tăng dần
//      for mỗi cạnh e(u, v, w):
//          if Find(u) != Find(v):
//              thêm e vào T
//              Union(u, v)
//          if T.size() == n -1
//              dừng


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int u, v;   // Hai đỉnh 
    int w;      // Trọng số
    int id;     // Thứ tự xuất hiện
};

int n, m; // G = <V = n, E = m>
vector<Edge> Edges; // Danh sách tất cả các cạnh
vector<Edge> T;     // Danh sách cạnh thuộc cây khung
vector<int> parent(105);    // parent[i]: cha của đỉnh i trong DSU
vector<int> sz(105);        // kích thước tập hợp đại diện là i
int totalWeight = 0l;       // tổng trọng số cây khung nhỏ nhất

// Khởi tạo DSU
// Ban đầu mỗi đỉnh là 1 tập hợp riêng
void makeSet(){
    for(int i = 1; i <= n; i ++) {
        parent[i] = i;      // mỗi đỉnh tự làm cha của chính nó
        sz[i] = 1;          // mỗi đỉnh tự làm cha của chính nó
    }
}

// Tìm đại diện của tập chứa đỉnh u
int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

// Gộp 2 tập chứa u, v
// Trả về true nếu gộp được
// Trả về false nếu u, v đã cùng tập
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    // Nếu cùng đại diện, thêm cạnh sẽ tạo chu trình
    if(u == v) return false;

    // Gộp tập nhỏ vào tập lớn
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
    
    return true;
}

// Hàm so sánh để sắp xếp cạnh
bool cmp(Edge& a, Edge& b) {
    if(a.w < b.w) return a.w < b.w;
    return a.id < b.id;
}

// Thuật toán Kruskal
void Kruskal() {
    sort(Edges.begin(), Edges.end(), cmp);
    for(auto e : Edges) {
        if(Union(e.u, e.v)) {
            T.push_back(e);
            totalWeight += e.w;
        }

        if(T.size() == n - 1) break;
    }
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edges.push_back({u, v, w});
    }

    makeSet();
    Kruskal();
    if(T.size() != n - 1) {
        cout << 0;
        return 0;
    }

    cout << totalWeight << endl;
    for(auto e : T)
        cout << e.u << " " << e.v << " " << e.w << endl;
    
}