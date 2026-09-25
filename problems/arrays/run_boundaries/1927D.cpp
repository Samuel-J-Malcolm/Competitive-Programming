/*

Works, ignore the test case
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

void solve()
{
    int l;
    vi idx;
    int prev = -1;
    int in;
    int c = 0;
    cin >> l;
    int prevIdx = 1;
    rep(i,1,l+1){
        cin >> in;
        if(i == 1){
            prev = in; 
        }
        if(prev != in){
            rep(j,prevIdx,i){
                idx.push_back(i);
                c=0;
            }
            prevIdx = i;
            prev = in; 
        }
        else{
            c++;
        }
    }
    rep(j,0,c+1){
        idx.push_back(l+1);
            
    }
    int q;
    cin >> q;
    int a,b;
    rep(i,0,q){
        cin >> a;
        cin >> b;
        int diff = idx[a-1];
        if(diff > b){
            cout << "-1 -1\n";
        }
        else{
            cout <<  a << " " << diff << "\n";

        }
    }
    cout << "\n";
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
