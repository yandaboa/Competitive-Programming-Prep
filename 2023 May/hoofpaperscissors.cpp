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

//unfinished

int N, K;
vector<char> moves;
vector<vector<pair<int, char> > > dp;

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        char a; cin >> a; moves.pb(a);
    }
    dp.rsz(N);
    for (int i = 0; i < sz(dp); i++)
    {
        dp[i].rsz(K + 1);
        fill(all(dp[i]), mp(-1, 'a'));
    }
    for (int i = 0; i < sz(dp) - 1; i++)
    {
        for (int j = 0; j < sz(dp[i]); j++)
        {
            pair<int, char> curr = dp[i][j];
            if(curr.f == -1){
                continue;
            }

            if(dp[i + 1][j].f <= )
        }
        
    }
    
}