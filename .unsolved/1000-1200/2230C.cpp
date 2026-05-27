/*
Link: https://codeforces.com/contest/2230/problem/C
Rating: 1184
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
    ll l;
    cin >> l;
    map<ll,ll> m;
    priority_queue<ll> p;
    ll in = 0;
    rep(i,0,l){
        cin >> in;
        p.emplace(in);
    }
    if(p.top() == 1){
        cout << 0 << "\n";
        return;
    }
    ll total = p.top();
    ll r = total / 2 - 1;
    if(p.top() == 1){
        r = total / 2;
    }
    p.pop();
    rep(i,0,r){
        if(sz(p) == 0){
            break;
        }

        total += p.top();
        if(p.top() != 1){
            r += p.top()/2;
        }
        p.pop();
    }
    if(total < 3){
        total = 0;
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
