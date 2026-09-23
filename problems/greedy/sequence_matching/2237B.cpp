/*
Link: https://codeforces.com/contest/2237/problem/B
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
using str = string;

#define NO print("NO"); return;
#define YES print("YES"); return;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif

void printstruct(auto& s){
    cout << "(";
    for(auto c: s){
        cout << c << " ";
    }
    cout << ")";
    cout << "\n";
    
}


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    ll l;
    cin >> l;
    vll a(l);
    vll b(l);
    ll tot = 0;
    rep(i,0,l){
        cin >> a[i];
    }
    rep(i,0,l){
        cin >> b[i];
    }
    rep(i,0,sz(a)){
        //cout << i << " " << tot<< "\n";
       // printstruct(a);
      //  printstruct(b);
        if(a[i] > b[i]){
            auto idx = lower_bound(b.begin(),b.end(),a[i]);
            if(idx == b.end()){
                cout << -1;
                return;
            }
            int d = distance(b.begin(), idx) - i;
      //      cout << d << "\n";
            a.erase(a.begin()+i);
            b.erase(idx);
            i--;
            tot += d; 
        }
    }
    cout << tot;

   
    

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
