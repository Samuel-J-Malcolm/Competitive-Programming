/*
Link: https://codeforces.com/contest/2224/problem/B
Rating: 1049
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
    priority_queue<int> p;
    set<int> s;
    ll maxi = 0;
    int d = 0;
    ll in;
    rep(i,0,l){
        cin >> in;
        if(s.count(in)){
            d++;
        }
        else{
            p.emplace(-in);
            s.insert(in);
            maxi = max(maxi,in);
        }
    }
    ll total = maxi*l;
    ll mex = 0;
    if(maxi == 0){
        cout << l << "\n";
        return;
    }
    while(sz(p) > 1){
        if(mex == -p.top()){
            mex++;
        }
        else{
            d += sz(p) - 1;
            break;
        }
        if(maxi == mex){
            mex++;
        }
        total += mex;
        p.pop();
        

 //       cout << mex << "! ";

    }
    total += mex*d;
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
