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

// Constants
const ll INF  = 1e18;
const int INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void solve()
{
    int n_apartments;
    int n_people;
    int diff;
    vi p;

    vi a;
    cin >> n_people;
    cin >> n_apartments;
    cin >> diff;
    int input;
    rep(i,0,n_people){
        cin >> input;
        p.push_back(input);
    }
    rep(i,0,n_apartments){
        cin >> input;
        a.push_back(input);
    }
    sort(all(a));
    sort(rall(p));
    int n = 0;
    for(int c: p){
        n_apartments--;
        int capacity = a[n_apartments];
        while(capacity > diff+c){
            n_apartments--;

            if(n_apartments<0){
                break;
            }
            capacity = a[n_apartments];
        }
        
        cout << capacity << "," << c << " ";
        if(capacity+diff >= c and capacity-diff <= c){
            n++;
            continue;
        }
    }
    cout << n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
