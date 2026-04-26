#include <iostream>
using namespace std;

class MovieTicket {
    int booked[1001][1001];
    int available[1001];

public:
    MovieTicket() {
        for (int i = 0; i <= 1000; i++) {
            available[i] = 100;
            for (int j = 0; j <= 1000; j++) {
                booked[i][j] = 0;
            }
        }
    }

    bool BOOK(int x, int y) {
        if (booked[x][y] == 1 || available[y] == 0)
            return false;

        booked[x][y] = 1;
        available[y]--;
        return true;
    }

    bool CANCEL(int x, int y) {
        if (booked[x][y] == 0)
            return false;

        booked[x][y] = 0;
        available[y]++;
        return true;
    }

    bool IS_BOOKED(int x, int y) {
        return booked[x][y];
    }

    int AVAILABLE_TICKETS(int y) {
        return available[y];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket obj;

    while (Q--) {
        string type;
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (obj.BOOK(x, y) ? "true" : "false") << endl;
        }

        else if (type == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (obj.CANCEL(x, y) ? "true" : "false") << endl;
        }

        else if (type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (obj.IS_BOOKED(x, y) ? "true" : "false") << endl;
        }

        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << obj.AVAILABLE_TICKETS(y) << endl;
        }
    }

    return 0;
}