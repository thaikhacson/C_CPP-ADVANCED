#include <iostream>
#include <map>
#include <unordered_map>
// #include <multimap>

using namespace std;

int main() {
    // map<int, int> mp;
    // mp[100] = 200;
    // mp[200] = 300;
    // mp.insert({300, 400});
    // mp.insert({400, 500});
    // mp[100];
    // //Duyệt các phần tử trong map
    //Cách 1
    // for(pair<int, int> x : mp) {
    //     cout << x.first << " " << x.second << endl;
    // }

    // //Cách 2
    // for(auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // //Cách 3
    // for(map<int, int> ::iterator it = mp.begin(); it != mp.end(); it++) {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }


    // Đếm số lần xuất hiện của phần tử trong mảng, sau đó in ra kèm theo tần suất của nó
    map<string, int> mp;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    //In ra phần tử xuất hiện nhiều nhất
    int max_fre = 0;
    string res;
    for(auto x : mp) {
        if(x.second >= max_fre) {
            max_fre = x.second;
            res = x.first;
        }
    }
    cout << res << " " << max_fre << endl;

}