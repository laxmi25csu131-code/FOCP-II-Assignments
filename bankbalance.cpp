#include<bits/stdc++.h>
using namespace std;

class BankBalance {
    bool exist[101];
    int money[101];

    public :
    
    BankBalance() {
        memset(exist, false, sizeof(exist));
        memset(money, 0, sizeof(money));
    }

    bool create(int x, int y) {
        if (exist[x]) {
            cout<<"User Already Exist"<<endl;
            return false;
        }else {
            exist[x] = true;
            money[x] = y;
            cout<<"Account Created"<<endl;
            return true;
        }
    }
    bool debit(int x, int y) {
        if (!exist[x]) {
            cout<<"Account Not Existed"<<endl;
            return false;
        }else if (money[x] < y) {
            cout<<"Not Sufficient Money In Account"<<endl;
            return false;
        }else {
            money[x] -= y;
            cout<<"Money Debited"<<endl;
            return true;
        }
    }
    bool credit(int x, int y) {
        if (!exist[x]) {
            cout<<"Account Not Existed"<<endl;
            return false;
        }else {
            money[x] += y;
            cout<<"Money Credited"<<endl;
            return true;
        }
    }
    int balance(int x) {
        if(!exist[x]) {
            cout<<"Account Not Existed"<<endl;
            return false;
        }
        return money[x];
    }
};

int main() {
    BankBalance b1;
    b1.balance(1);
    b1.create(1, 6767);
    b1.credit(1, 6767);
    b1.debit(1, 6767);
    cout<<b1.balance(1)<<endl;
    return 0;
}