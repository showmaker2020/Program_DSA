#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int q;
    vector<string> v;
    int ans = 0;
    map<string, int> mp;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "ADD") {
            string t;
            cin >> t;
            int x;
            cin >> x;
            mp[t] = x;
            ans += x;
            v.emplace_back(t);
        } else if (s == "REMOVE") {
            string t;
            cin >> t;
            v.erase(find(v.begin(), v.end(), t));
            ans -= mp[t];
        } else {
            printf("INVENTORY ");
            for (int i = 0; i < v.size(); i++) {
                if (i != 0) cout << ", ";
                cout << v[i];
            }
            printf(" TOTALS %d GOLD\n", ans);
        }
    }
}