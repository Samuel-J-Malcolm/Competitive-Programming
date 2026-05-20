#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


int segments(std::vector<std::pair<int,int>>& s){
    ordered_set st;
    int n = s.size();
    sort(s.begin(), s.end());
 
    long long ans = 0;
    st.clear();
 
    for(auto p : s){
        ans += st.size() - st.order_of_key(p.second);
 
        st.insert(p.second);
    }
 
    return ans;
}
