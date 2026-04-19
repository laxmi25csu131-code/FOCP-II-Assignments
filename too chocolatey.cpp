#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<int> k;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            k.insert(x);
        }
        int r = k.size();

        if (r % 2 == 1)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}