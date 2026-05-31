#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");

    int t, n;
    if (!(inp >> t >> n)) return 0;

    int a[101][101] = {0};
    vector<int> deg(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int k;
        inp >> k;
        deg[i] = k;
        for (int j = 0; j < k; j++) {
            int v;
            inp >> v;
            a[i][v] = 1;
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            out << deg[i] << (i == n ? "" : " ");
        }
    } else if (t == 2) {
        out << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                out << a[i][j] << (j == n ? "" : " ");
            }
            out << endl;
        }
    }

    inp.close();
    out.close();
    return 0;
}