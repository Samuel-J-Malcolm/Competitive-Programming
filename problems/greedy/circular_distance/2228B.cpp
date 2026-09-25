/*
Link:
Rating: 967
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;

using vi  = vector<int>;
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
#define sz(x)   (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using str = string;


// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;


void solve()
{
    ll n = 0;
    ll x1 = 0; 
    ll x2 = 0;
    ll k = 0;
    cin >> n;
    cin >> x1;
    cin >> x2;
    cin >> k;
    ll d = min(abs(x1-x2),abs(abs(x1+n-x2)));
    d = min(d,abs(abs(x1-n-x2)));
    if(n <= 3){
        cout << 1 << "\n";
        return;
    }
    cout << d+k << "\n";
    

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
