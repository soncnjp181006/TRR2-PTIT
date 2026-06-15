// Đồ thị vô hướng
// G là Euler:      G liên thông, với mọi đỉnh u có deg chẵn
// G là nửa Euler:  G liên thông, chỉ có 2 đỉnh u có deg lẻ

// Chu trình Euler đồ thị vô hướng
// EulerCycle(start):
//      Cho start vào stack
//      while stack != empty:
//           u = top
//           for v in adj[u]:
//              if(!visited[v]): cho v vào stack, visited[v] = true
//              


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int t, n, u;


int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t >> n;
    if(t == 2) cin >> u;

    if(t == 1) {

    }
    else  {

    }

}