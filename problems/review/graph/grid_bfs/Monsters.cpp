/*
Link: $url$
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <iomanip>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


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
#define repp(i, a, b, c) for (ll i = (a); i < (b); i+=c)
#define repn(i, a, b, c) for (ll i = (a); i > (b); i-=c)

using str = string;
#include <bit> // Required for bit operations

#define NO cout << ("No"); return;
#define YES cout << ("Yes"); return;

#ifdef LOCAL
#define dbg(x) cout << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


int bw(unsigned long long x) {
    return x == 0 ? 0 : 64 - __builtin_clzll(x);
}

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

#ifdef LOCAL
#define ps(x) printstruct(x) << "\n"
#else
#define ps(x)
#endif

template<typename... Args>
void in(Args&... args) {
    ((cin >> args), ...);
}

template<typename... Args>
void out(const Args&... args) {
    ((cout << args), ...);
}

string search1(int n,int m, vvint& v,int start, int end,set<int> monsters){
    if(start == end){
        return "!";
    }
    vector<str> paths(n,"");
    vector<int> parent(n);
    vector<char> dir(n);
    vector<bool> visited(n);
    vector<int> szpath(n,1e9);
    int lowmonster = 1e9;
    str path = "";
    visited[start] = true;
    queue<int> q;
    q.push(start);
    szpath[start] = 0;
    int path_len = 1e9;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i: v[cur]){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            char direction = 'L';
            if(cur - i == m){
                direction = 'D';
            }
            else if(cur - i == 1){
                direction = 'R';
            }
            else if(i - cur == m){
                direction = 'U';
            }
            dir[i] = direction;
            parent[i] = cur;
            szpath[i] = szpath[cur]+1;
            if(szpath[cur] > lowmonster && szpath[end] != 1e9){
                return path;
            }
            if(lowmonster == 1e9 && monsters.count(i)){
                lowmonster = i;
                if(szpath[end] == 1e9){
                    return "";
                }
            }
            if(i == end && path == ""){
                path = "";
                while(i != start){
                    path.push_back(dir[i]);
                    i = parent[i];
                }
                path_len = sz(path);
            }
            q.push(i);
        }
    }
    for(int i: monsters){
        if(szpath[i] <= szpath[end]){
            //out("MONSTER ",i," ",end,"\n");
            return "";
        }
    }
    if(szpath[end] != 1e9 && path == ""){
        return "!";
    }
    return path;



}


void solve(){
    ll m,n,k,x,inp;
    bool b;
    str s;
    in(n);
    in(m);
    vector<string> vs(n,"");
    vvint adj(n*m);
    std::vector<int> boundaries = {};
    std::set<int> monsters = {};

    rep(i,0,n){
        cin >> vs[i];
    }
    char c;
    int num;
    int start = 0;
    int end = 0;
    rep(i,0,n){
        rep(j,0,m){
            c = vs[i][j];
            if(c == '#'){
                continue;    
            }
            
            num = i*m+j;
            if(c == 'A'){
                start = num; 
            }
            if(c == 'M'){
                monsters.insert(num);
            }
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                boundaries.push_back(num);
            }
            if(i != 0 && vs[i-1][j] != '#'){
                adj[num].push_back(num-m);
            }
            if(j != 0 && vs[i][j-1] != '#'){
                adj[num].push_back(num-1);
            }
            if(i != n-1 && vs[i+1][j] != '#'){
                adj[num].push_back(num+m);
            }
            if(j != m-1 && vs[i][j+1] != '#'){
                adj[num].push_back(num+1);
            }
        }
    }
    for(int i: boundaries){
        string path = search1(n*m,m,adj,i,start,monsters);
        if(path == ""){
            continue;
        }
        else if(path == "!"){
            out("YES\n0");
            return;
        }
        else{
            out("YES\n",sz(path),"\n");
            out(path);
            return;
        }
    }
    out("NO");

    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool multi = true;
    multi = false;
    ll t = 1;
    if(multi){
        cin >> t;
    }
    
    while (t--){
        solve();
        if(multi){
            out("\n");
        }
    }
    return 0;
}
