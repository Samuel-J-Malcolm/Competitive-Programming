/*
Link: https://codeforces.com/problemset/problem/2051/E
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

#define print(a) cout << a;
#define println(a) cout << a << "\n";
#define NO print("NO"); return;
#define YES print("YES"); return;


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

// 0 is a swap from + to -
// 1 is a swap from - to !buy

void solve()
{
    ll l;
    cin >> l;
    ll k;
    cin >> k;

    vector<pll> v(2*l);
    rep(i,0,l){
        cin >> v[i].fi;
    }
    rep(i,l,2*l){
        cin >> v[i].fi;
        v[i].se = 1;

    }
        

    ll buyers = l;
    ll nReviews = 0;
    sort(all(v));
    ll maxR = (v[0].fi)*buyers;
    v.emplace_back(pair((ll) 2e9+1,-1LL));
    rep(i,0,l*2){
        if(v[i].se == 0){
            nReviews++;
        }
        else{
            nReviews--;
            buyers--;
        }
        if(v[i+1].fi == v[i].fi){
            continue;
        }
        if(nReviews > k){
            continue;
        }
        if(buyers == 0){
            continue;
        }
        else{
            maxR = max(maxR,buyers*(v[i+1].fi));
        }
    }
    cout << maxR;

   
    

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
