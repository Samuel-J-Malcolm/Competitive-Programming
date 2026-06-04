/*
Link: https://codeforces.com/contest/2117/problem/E
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

void printstruct(auto& s){
    cout << "(";
    for(ll c: s){
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
    vi a(l);
    vi b(l);
    rep(i,0,l){
        cin >> a[i];
    }
    rep(i,0,l){
        cin >> b[i];
    }
    set<ll> s;
    for(int i = l-1;i>=0;i--){
        if(a[i] == b[i]){
            cout << i+1;
            return;
        }
        else if(s.count(a[i]) == 1|| s.count(b[i]) == 1){
            cout << i+1;
            return;
        }
        if(i == l-1){
            continue;
        }
        
        s.emplace(a[i+1]);
        s.emplace(b[i+1]);
        if(a[i] == a[i+1] || b[i] == b[i+1]){
            cout << i+1;
            return;
        }
        
        
        
    }
    cout  << 0;
    return;

    
    

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
