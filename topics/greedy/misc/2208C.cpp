/*
Link: https://codeforces.com/problemset/problem/2208/C
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
    vector<pair<double,double>> values(l);
    rep(i,1,l+1){
        cin >> values[l-i].fi;
        cin >> values[l-i].se;
        values[l-i].se = 1-(values[l-i].se/100);
    }
    rep(i,1,l+1){
    }
    vector<double> maxvals(l+1);
    maxvals[0] = 0; 
    rep(i,0,l){
        maxvals[i+1] = max(maxvals[i],maxvals[i]*values[i].se+values[i].fi);
    }
    cout << fixed << setprecision(10) << maxvals[l];
   
    

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
