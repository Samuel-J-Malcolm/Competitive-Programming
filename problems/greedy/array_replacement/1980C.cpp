/*
Link:
Rating:
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
    vi o(l);
    vi n(l);
    rep(i,0,l){
        cin >> o[i];
    }
    map<ll,ll> req;
    set<ll> cont;
    ll sum = 0;
    rep(i,0,l){
        cin >> n[i];
        if(n[i] != o[i]){
            req[n[i]]++;
            sum++;
        }
        cont.insert(n[i]);
    }
    ll l1;
    cin >> l1;
    ll in;
    rep(i,0,l1){
        cin >> in;
        if(req[in] > 0){
            req[in]--;
            sum--;
        }
        if(i == l1-1){
            if(cont.count(in)){
                if(sum == 0){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
    

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
