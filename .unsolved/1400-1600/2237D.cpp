/*
Link: https://m1.codeforces.com/contest/2237/problem/D
Rating: ~1444
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
    str s;
    cin >> s;
    vector<vector<ll>> allb(l);
    //0, idx 0
    //1, idx 1
    //WAIT 1 -> 1 (01) 2
    //WAIT 0 -> 0 (10) 3
    //WAIT 1 -> 0 (101) 4
    //WAIT 0 -> 1 (010) 5
//0
    ll totalb = 0;
    if(s[0] == '0'){
        allb[0] = {1,0,0,0,0,0};
    }
    else{
        allb[0] = {0,1,0,0,0,0};
    }
    
    rep(i,1,l){
        allb[i] = vector<ll>(6,0);
        if(s[i] == '0'){
            allb[i][1] += allb[i-1][0];
            allb[i][3] += allb[i-1][1];
            allb[i][5] += allb[i-1][2];
            allb[i][0] += allb[i-1][3];

            allb[i][3] += allb[i-1][4];
            allb[i][1] += allb[i-1][5];
            allb[i][0]++;        }
        else{
            allb[i][2] += allb[i-1][0];
            allb[i][0] += allb[i-1][1];
            allb[i][1] += allb[i-1][2];
            allb[i][4] += allb[i-1][3];
            allb[i][0] += allb[i-1][4];
            allb[i][2] += allb[i-1][5];        
            allb[i][1]++;
        }
       // printstruct(allb[i]);
    }
    rep(i,0,l){
        totalb += allb[i][0]+allb[i][1];
    }
    cout << totalb;


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
