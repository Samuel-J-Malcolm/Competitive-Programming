/*
    Rating 1000

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
using vpii = vector<pii>;


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
#define rep(i, a) for (int i = (0); i < (a); i++)


// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    vpii list;
    int c1;
    int n;
    cin >> n;
    cin >> c1;
    rep(i,n){
        int a;
        cin >> a;
        list.push_back({0,a});
    }
    rep(i,n){
        int a;
        cin >> a;
        list[i].fi = a;
    }
    list.push_back({c1,INF32});
    sort(all(list));
    ll cost = c1;
    n--;
    ll min1;
    for(pii i: list){
        min1 = min(i.se,n);
        n -= min1;
        cost += min1* ((ll)i.fi); 
        if(n == 0){
            break;
        }
    }
    cout << cost << "\n";
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
