/*
Link: https://codeforces.com/contest/2233/problem/C
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

void solve()
{
    ll l;
    cin >> l;
    ll r;
    cin >> r;
    str s;
    cin >> s;
    vll costs(l);
    ll maxcost = 0;
    rep(i,0,l){
        int margin = 0;
        rep(j,i,l){
            if(s[j] == '('){
                margin--;
            }
            else{
                margin++;
            }
            if(margin == 0){
                costs[i] = j-i+1;
                maxcost = max(j-i+1,maxcost);
                break;
            }
            if(margin < 0){
                break;
            }
        }
    }
    string s1(l,'0');
    
    rep(i,0,l){
        if(maxcost != 0 && costs[i] == maxcost){
            i += maxcost-1;
            rep(j,i,l){
                if(r == 0){
                    cout << s1;
                    return;
                }
                r--;
                s1[i] = '1';
                if(j == l-1 || s[j] != s[j+1]){
                    break;
                }
            }
        }
    }
    cout << s1;

    

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
