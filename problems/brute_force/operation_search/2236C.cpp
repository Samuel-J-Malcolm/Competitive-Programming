/*
Link: https://codeforces.com/contest/2236/problem/C
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
    ll a;
    cin >> a;
    ll b;
    cin >> b;
    ll c;
    cin >> c;
    if(a == b){
        cout << 0;
        return;
    }
    ll origA = a; 
    ll maxl = abs(b-a);
    ll curlB = 0;
    ll curlA = 0;
    while(b > 0){
        a = origA;
        curlA = 0;
        while(a > 0){
            maxl = min(maxl,curlA+curlB+abs(b-a));
            a /= c;
            curlA++;
            maxl = min(maxl,curlA+curlB+abs(b-a));
        }
        b /= c;
        curlB++; 
        maxl = min(maxl,curlA+curlB+abs(b-a));
    }
    cout << maxl;

    
   
    

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
