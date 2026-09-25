/*
Link: https://codeforces.com/problemset/problem/2117/D
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

void printstruct(auto& s){
    cout << "(";
    for(auto c: s){
        cout << c << " ";
    }
    cout << ")";
    cout << "\n";
    
}


void solve()
{
    ll l;
    cin >> l;
    vll v(l);
    ll m = 0;
    rep(i,0,l){
        cin >> v[i];
        m = max(v[i]/(l+1),m);
    }
    ll cdiff = v[1]-v[0];
    if(cdiff>0){
        rep(i,0,l){
            v[i] -= (i+1)*cdiff;
        }
    }
    else if(cdiff<0){
        rep(i,0,l){
            v[i] += (l-(i+1)+1)*cdiff; // - cdiff * -1
        }
    }
    if(v[0] < 0 || v[0] % (l+1) != 0){
        NO
    }
    rep(i,0,l){
        if(v[i] != v[0]){
            NO
        }
    }
    YES



    
    

    

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
