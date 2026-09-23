/*
Link: https://codeforces.com/contest/875/problem/A
Rating: 1200
Platform: Codeforces
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
    vll v;
    rep(i,max(l/10*10-100,0LL),l+10){
        str s = to_string(i);
        ll d = l - i;
        for(char c: s){
            d -= (c - '0');
        }
        if(d % 2 == 0 && d <= 18 && d >=0){
            v.push_back(i+d/2);
        }
        i+=9;
        
    }
    cout << sz(v);
    cout << "\n";
    for(ll l: v){
        cout << l << "\n";
    }
   
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}
