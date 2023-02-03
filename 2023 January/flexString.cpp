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

ll T, maxV, K;
set<char> uniques;
string og, targ;

void check(vb use, int num, int next){
    if(num > K){
        return;
    }
    if(num >= K || num == sz(use)){
        vb inUse; inUse.rsz(26);
            int index = 0;
            for(auto a = uniques.begin(); a != uniques.end(); a++){
                if(use[index]){
                    inUse[*a - 'a'] = true;
                }
                index++;
            }
            // cout << sz(inUse) << endl;
            vi intervals;
            int soFar = 0;
            for (int i = 0; i < sz(og); i++)
            {
                if(og[i] != targ[i] && !inUse[og[i] - 'a']){
                    intervals.pb(soFar);
                    soFar = 0;
                } else {
                    soFar++;
                }
            }
            if(soFar > 0){
                intervals.pb(soFar);
            }
            ll valid = 0;
            for (int i = 0; i < sz(intervals); i++)
            {
                ll temp = intervals[i];
                temp *= (intervals[i] + 1);
                temp/=2;
                valid += temp;
            }
            maxV = max(valid, maxV);
    }
    
    if(next < sz(use)){
        check(use, num, next + 1);
        use[next] = true;
        check(use, num + 1, next + 1);
    }
}

void solve(){
    int N; cin >> N >> K; uniques.clear();
    cin >> og >> targ;
    for (int i = 0; i < N; i++)
    {
        uniques.insert(og[i]);
    }
    maxV = 0;
    vb use; use.rsz(sz(uniques));
    check(use, 0, 1);
    use[0] = true;
    check(use, 1, 1);
    cout << maxV << endl;
}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}