//Q Turn Off Lights
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string bulbs;
    cin >> bulbs;
    for (int k = 1; k <= n; k++) {
        int operations = 0;
        for (int i = 0; i < n; ) {
            if (bulbs[i] == '1') {
                operations++;      
                i += k; } else {i++; }
        }
        if (operations <= m) {
            cout << k << endl;
            return 0;}
    }
    return 0;
}
