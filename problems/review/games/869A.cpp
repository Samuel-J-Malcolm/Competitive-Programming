/*


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

// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vi v1(n);
    vi v2;
    vi v3;
    unordered_set<int> m;
    int pairs = 0;
    rep(i,0,n){
        cin >> v1[i];
        m.emplace(v1[i]);
    }
    rep(i,0,n/2){
        rep(j,0,n/2){
            if(m.count(v1[i]^v1[j])){
                pairs ^= 1;
            }
        }

    }
    if(pairs == 1){
        cout << "Koyomi\n";
    }
    else{
        cout << "Karen\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    solve();
    return 0;
}
