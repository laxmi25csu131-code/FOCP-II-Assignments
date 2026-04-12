#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        int count = 0;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) count++;

        long long answer = 1;
        for (int i = 0; i < count; i++) {
            answer *= 2;
        }
        cout << answer << "\n";
    }
    return 0;
}