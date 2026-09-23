/*


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


int firstTrue(vector<int>& ls){
    int sz = size(ls);
    int l = 0;
    int r = sz;
   // cout << ls[0];
    while(r>l){
        int m = (l+r)/2;
       // cout << ls[m] << "," << sz-m << "\n";
        if(ls[m] >= sz-m){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    if(l == sz){
        return -1;
    }
    return min(l,sz);
}


void solve()
{
    int l;
    cin >> l;
    vi v;
    int i = 0;
    int c;
    rep(i,0,l){
        int input;
        cin >> input;
        v.push_back(input);
        c = firstTrue(v);
        if(c < 0){
            c = i;
    //        cout << "!";
        }
        cout << i-c+1 << " ";
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
