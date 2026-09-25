/*


*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    vector<int> a,b,c;
    int x1, z,x2,x3;
    cin >> z;
    int numbers[] = {0,0,0,0,0,0,0,0,0};
    int indices[] = {0,0,0,0,0,0,0,0,0};
    for(int y=0;y<3*z;y++){
        x1 = 0;
        x2 = 0;
        x3 = 0;
        if(y < z){
            cin >> x1;
        }
        else if(y < 2 * z){
            cin >> x2;
        }
        else{
            cin >> x3;
        }
        if(x1 > numbers[0]){
            numbers[2] = numbers[1];
            numbers[1] = numbers[0];
            numbers[0] = x1;
            indices[2] = indices[1];
            indices[1] = indices[0];
            indices[0] = y % z;
        }
        else if(x1 > numbers[1]){
            numbers[2] = numbers[1];
            numbers[1] = x1;
            indices[2] = indices[1];
            indices[1] = y % z;
        }
        else if(x1 > numbers[2]){
            numbers[2] = x1;
            indices[2] = y % z;
        }
        if(x2 > numbers[3]){
            numbers[5] = numbers[4];
            numbers[4] = numbers[3];
            numbers[3] = x2;
            indices[5] = indices[4];
            indices[4] = indices[3];
            indices[3] = y % z;
        }
        else if(x2 > numbers[4]){
            numbers[5] = numbers[4];
            numbers[4] = x2;
            indices[5] = indices[4];
            indices[4] = y % z;
        }
        else if(x2 > numbers[5]){
            numbers[5] = x2;
            indices[5] = y % z;
        }
        if(x3 > numbers[6]){
            numbers[8] = numbers[7];
            numbers[7] = numbers[6];
            numbers[6] = x3;
            indices[8] = indices[7];
            indices[7] = indices[6];
            indices[6] = y % z;
        }
        else if(x3 > numbers[7]){
            numbers[8] = numbers[7];
            numbers[7] = x3;
            indices[8] = indices[7];
            indices[7] = y % z;
        }
        else if(x3 > numbers[8]){
            numbers[8] = x3;
            indices[8] = y % z;
        }




    }
            int maximum = 0;

            for(int i = 0;i<3;i++){
            for(int j = 3;j<6;j++){
                for(int k = 6;k<9;k++){
                    if(indices[i] == indices[j] or indices[i] == indices[k] or indices[k] == indices[j]){
                        continue;
                    }
                    maximum = max(numbers[i]+numbers[j]+numbers[k],maximum);
                }
            }    
        }
        cout << maximum << "\n";

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
