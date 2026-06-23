/*
Link: https://codeforces.com/contest/2236/problem/E
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;


using ll  = int;
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
#define repinv(i, a, b) for (ll i = (b-1); i >= (a); i--)

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

long long key(int a, int b,int l){
    return a*(l+1)+b;
}

void solve()
{
    int l;
    cin >> l;
    vector<char> subsegments((l+1)*(l+1));
    subsegments[key(1,0,l)] = 1;

    vi v(l);
    rep(i,0,l){
        cin >> v[i];
    }
    vector<char> freq(l+1);
    rep(i,0,l){
        ll maxe = v[i];
        ll mine = v[i];
        rep(j,i,l){
            mine = min(mine,v[j]);
            maxe = max(v[j],maxe);
            if(freq[v[j]] == 1){
                break;
            }
            fill(freq.begin(), freq.end(), 0);
            
            if(maxe - mine == j-i){
                subsegments[key(mine,maxe,l)] = 1;
            }
        }
        rep(j,i,l){
            freq[v[j]] = 0;
        }

    }
    repinv(i,0,(l/2+1)){
        rep(j,0,l){
            if(subsegments[key(1+j,i+j,l)] == 1 && subsegments[key(i+1+j,2*i+j,l)] == 1){
                cout << i;
                return;
            }
        }
        
    }
   
    

}

int main(){
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
