/*


*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

void solve()
{
    int n = 1;
    cin >> n;
    str v = "";
    cin >> v;
    int sum = 0;
    set<char> a = {};
    for(char i: v){
        a.insert(i);
        sum += a.size();
    }
    cout << sum <<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
