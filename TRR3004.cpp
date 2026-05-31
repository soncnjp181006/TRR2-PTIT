#include <iostream>
#include <vector>
using namespace std;

int t, n, u;


int main() {
    if(!freopen("CT.INP", "r", stdin)) return 0;
    if(!freopen("CT.OUT", "w", stdout)) return 0;
    if(!(cin >> t >> n)) return 0;
    if(t == 2 && !(cin >> u)) return 0;
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int val;
            if(!(cin >> val)) return 0;

            if(val) {

            }
        }
    }
}