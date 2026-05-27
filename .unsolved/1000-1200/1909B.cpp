/*
Link: https://codeforces.com/contest/1909/problem/B
Rating: 1200
Duration: X
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll x, y;
    cin >> y;
    ll g = 0;
    while (y--){
        cin >> x;
        if(x == 0){
            continue;
        }
        if(g == 0){
            g = x;
        }
        else{
            g = gcd(x,g);
        }
        
    }
    cout << g*2 << "\n";
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
