#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> point;
    int q;
    cin >> q;
    while(q--) {
        int s;
        cin >> s;
        if(s==1) {
            string x; int y;getline(cin, x); cin >> y;
            point[x]+=y;
        }
        if(s==2) {
            string x;
            getline(cin, x);
            point[x] = 0;
        }
        if(s==3) {
            string x;
            getline(cin, x);
            cout << point[x] << "\n";
        }
    }
    return 0;
}