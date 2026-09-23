/*
Link: https://codeforces.com/contest/1931/problem/D
Rating: 1300
Duration: X
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

bool sortf(pii a,pii b){
    if(a.fi != b.fi){
        return a.fi>b.fi;
    }
    if(abs(a.se) != abs(b.se)){
        return abs(b.se) < abs(a.se);
    }
    return a.se > b.se;
}

void solve()
{
    int x,y,l;
    cin >> l;
    cin >> x;
    cin >> y;
    ll total = 0;
    map<pii,int> m;
    int in;
    rep(i,0,l){
        cin >> in;
        int xMod = in % x;
        int yMod = in % y;
        total += m[{yMod,(x-xMod) % x}];
        m[{yMod,xMod}]++;
    }
    
   cout << total << "\n";


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
