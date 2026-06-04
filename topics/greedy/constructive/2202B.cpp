/*
Link: https://codeforces.com/problemset/problem/2202/B
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<ll, ll>;
using pll = pair<ll, ll>;

using vi  = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros
#define pb    push_back
#define eb    emplace_back
#define mp    make_pair
#define fi    first
#define se    second
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (ll)(x).size()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
using str = string;


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    ll l;
    cin >> l;
    str s;
    cin >> s;
    pii margin = {l % 2,l % 2};
    for(char c: s){
        if(c == 'a'){
            margin.fi--;
            margin.se--;
        }
        if(c == 'b'){
            margin.fi++;
            margin.se++;
        }
        if(c == '?'){
            margin.fi--;
            margin.se++;
        }
        if(margin.fi < -1){
            margin.fi += 2;
        }
        if(margin.se > 1){
            margin.se -= 2;
        }
        //cout << "( " << margin.fi << " , " << margin.se << ") ";
        if(margin.fi > 1 || margin.se < -1){
            cout << "NO";
            return;
        }
    } 
    cout << "YES";
   
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}
