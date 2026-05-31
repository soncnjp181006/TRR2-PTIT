// matrix[n][n]

// 1. Tìm số lượng đường đi từ u -> v với độ dài k
// k = 2 -> 1 vòng lặp: 
//      for(k = 1 -> n) if(matrix[u][k] && matrix[k][v]) cnt += 1
// k = 3 -> 2 vòng lặp lồng:
//      for(a = 1 -> n) { for(b = 1 -> n) { if(matrix[u][a] && matrix[a][b] && matrix[b][v]) cnt += 1 } }

// 2. Tìm số thành phần trên u -> v theo DFS (đường đi từ u -> v)
// DFS(path, visited, u, v):
// 		visited[u], path.push_back(u)
// 		if(u == v) -> true
//		for(x : adj[u]) if(!visited[x]) { if(dfs(..., x,v)  -> true )}
// 		pop_back(), -> false

#include <iostream>
#include <vector>
using namespace std;

int t, n, u, v;
vector<int> adj[100];
vector<int> path;
vector<int> visited(1000);

bool dfs(vector<int>& path, vector<int>& visited, int u, int v) {
	visited[u] = 1; 	// Đánh dấu đỉnh đã thăm
	path.push_back(u);  // Cho u vào path

	// Nếu đã có đường đi từ u -> v
	if(u == v) return true;

	// Duyệt các đỉnh kề của u
	for(auto x : adj[u]) {
		// Nếu x chưa được thăm
		if(!visited[x]) {

			// Tìm đường đi từ x -> v
			if(dfs(path, visited, x, v)) return true;
		}
	}

	path.pop_back();    // Quay lui
	return false;
}

int main() {
	freopen("TK.INP", "r", stdin);	
	freopen("TK.OUT", "w", stdout);

	cin >> t >> n >> u >> v;

	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cin >> matrix[i][j];

			// Tìm danh sách kề
			if(matrix[i][j]) {
				adj[i].push_back(j);
			}
		}
	}

	// 1. Tìm số lượng đường đi có độ dài k = 2
	// u -> k -> v có: (u, k) và (k, v)						  [mảng k = 1-> n]
	// Nếu k = 3: u -> a -> b -> v có: (u, a), (a, b), (b, v) [ma trận a = 1 -> n, b = 1 -> n]
	if(t == 1) {
		int cnt = 0;
		for(int k = 0; k < n; k ++) {
			if(matrix[u-1][k] && matrix[k][v-1]) {
				cnt += 1;
			}
		}

		cout << cnt;
	}

	// 2. Tìm số thành phần trên đường đi từ u -> v
	else {
		if(dfs(path, visited, u-1, v-1))
			for(int vertex : path)
				cout << vertex + 1 << " ";
		else cout << 0;
	}
}