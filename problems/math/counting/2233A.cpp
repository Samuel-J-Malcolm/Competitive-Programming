/*
Link: https://codeforces.com/contest/2233/problem/A
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

void solve()
{
    ll n,x,y,z;
    cin >> n;
    cin >> x;
    cin >> y;
    cin >> z;
    ll nAI = (n/(x+y))+1;
    if(n % (x+y) == 0){
        nAI--;
    }
    ll AI = z;
    n -= x*z;
    AI += (n/(x+10*y))+1;
    if(n % (x+10*y) == 0){
        AI--;
    } 
    cout << min(AI,nAI);

    
    

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
