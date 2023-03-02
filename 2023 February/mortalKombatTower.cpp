#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
#include <string.h>
#include <fstream>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
//cin.tie(0)->sync_with_stdio(0);

int N, T;

void solve(){
    cin >> N;
    vi arr;
    vvi dp; arr.rsz(N); dp.rsz(N + 1);
    for (int i = 0; i < N; i++)
    {  
        cin >> arr[i];
    }

    for (int i = 0; i < sz(dp); i++)
    {
        dp[i].rsz(2);
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
    }
    
    dp[0][0] = 0; //[0][0] is first friend
    for (int i = 0; i < sz(dp) - 1; i++)
    {
        if(dp[i][0] != INT_MAX){
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (arr[i] == 1 ? 1 : 0));
            if(i < sz(dp) - 2){
                dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + (arr[i] == 1 ? 1 : 0) + (arr[i + 1] == 1 ? 1 : 0));
            }
        }
        if(dp[i][1] != INT_MAX){
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            if(i < sz(dp) - 2){
                dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]); 
            }
        }
    }
    cout << min(dp[sz(dp) - 1][0], dp[sz(dp) - 1][1]) << endl;
    
}


int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
        
    
}