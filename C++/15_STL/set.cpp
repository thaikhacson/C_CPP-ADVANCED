#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    map<int, int> s;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        s[x]++;
    }
    bool ok = false;
    for(auto x : a) {
        if(s.find(x) == s.end()){
            cout << x << " Found!" << endl;
            ok = true;
        }
    }
    if(!ok) cout << "Not Found!" << endl;
    return 0;
}
