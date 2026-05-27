/*
Link: https://codeforces.com/contest/2230/problem/D
Rating: 1588
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using pil = pair<ll, ll>;

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
#define rep(k, a, b) for (ll k = (a); k < (b); k++)
#define sint int
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
    vector<pii> v(l);
    for(auto& x: v){
        cin >> x.fi;
    }
    for(auto& x: v){
        cin >> x.se;
    }
    vector<ll> v2;
    for(pii p: v){
        if(p.fi == p.se){
            v2.emplace_back(p.fi);
        }
        else{
            v2.emplace_back(-1);
        }
    }
    ll sum = 0;
    ll tot = 0;
    ll cur = 0;
    vll alls(l+1);
    for(ll i = 0;i<l;i++){
        sum++;
        alls[1]++;
        ll j = v2[i];
        if(j > 0){
            if(j < l){
                alls[j+1] += alls[j];
                alls[j] = 0;
            }
        }
        else{
            sum -= alls[v[i].fi];
            alls[v[i].fi] = 0;
            sum -= alls[v[i].se];
            alls[v[i].se] = 0;
        }
        tot += sum;

    }
    cout << tot << "\n";


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
