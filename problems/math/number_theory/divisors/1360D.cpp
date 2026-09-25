/*
Link: https://codeforces.com/problemset/problem/1360/D
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pintint = pair<int, int>;
using pintl = pair<int, ll>;
using pll = pair<ll, ll>;

using vint  = vector<int>;
using vll = vector<ll>;
using vvint = vector<vint>;
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
#define rep(i, a, b, c) for (ll i = (a); i < (b); i+=c)
#define repn(i, a, b, c) for (ll i = (a); i >= (b); i-=c)

using str = string;

#define NO print("NO"); return;
#define YES print("YES"); return;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    ll n;
    ll k;
    cin >> n;
    cin >> k;
    for(int i = 1;i*i <= n;i++){
        if(n % i == 0 && n/i <= k){
            cout << i;
            return;
        }
    }

    for(int i = (int) pow(n,0.5)+1;i>=1;i--){
        if(n % i == 0 && i <= k){
            cout << n/i;
            return;
        }
    }
    

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
