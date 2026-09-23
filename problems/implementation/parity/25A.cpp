/*
Link: https://codeforces.com/problemset/problem/25/A
Rating: 1300
Duration: <10m
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
    vi v(l);
    for(auto& x: v){
        cin >> x;
    }
    int parity = v[0] % 2;
    if(parity != v[1] % 2){
        if(parity != v[2] % 2){
            cout << 1;
        }
        else{
            cout << 2;
        }
        return;
    }
    if(l == 3){
        cout << 3;
        return;
    }
    rep(i,2,l){
        if(parity != v[i] % 2){
            cout << i+1;
            return;
        }
    }
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    while (t--)
        solve();

    return 0;
}
