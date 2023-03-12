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
 
int T, N;
 
void solve(){
    cin >> N;
    vpi stores;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        stores.pb(mp(a, b));
    }
    sort(all(stores));
    vi largestFromBack; largestFromBack.rsz(N);
    int maxV = 0;
    for (int i = sz(stores) - 1; i > -1; i--)
    {
        maxV = max(maxV, stores[i].s);
        largestFromBack[i] = maxV;
    }
    set<int> soFar;
    int biggestDiff = INT_MAX;
    for (int i = 0; i < sz(stores); i++)
    {
        int mostExpensive = stores[i].f;
        int forcedExpense = i + 1 < sz(stores) ? largestFromBack[i + 1]: 0;
        int smallestBefore;
        if(sz(soFar)==0){
            smallestBefore = INT_MAX;
        } else {
            auto itr = soFar.upper_bound(mostExpensive);
            if(itr == soFar.end()){
                itr--;
                smallestBefore = *itr >= forcedExpense ? mostExpensive - *itr : INT_MAX;
            } else if(itr == soFar.begin()){
                smallestBefore = *itr >= forcedExpense ? *itr - mostExpensive : INT_MAX;
            } else {
                auto temp = itr; temp--;
                smallestBefore = min(*temp >= forcedExpense ? mostExpensive - *temp : INT_MAX, *itr > forcedExpense ? *itr - mostExpensive : INT_MAX);
            }
        }
        // cout << smallestBefore << " " << forcedExpense << endl;
        biggestDiff = min(min(i + 1 < sz(stores) ? abs(forcedExpense - mostExpensive) : INT_MAX, smallestBefore), biggestDiff);
        soFar.insert(stores[i].s);
    }
    cout << biggestDiff << endl;
}
 
int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}