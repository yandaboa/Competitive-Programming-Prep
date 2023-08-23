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

int T;

void solve(){
    ll N, numDoses, lifeTime, waitTime;
    ll lastsUntil = - 1, dLeft = -1;
    ll packsNeeded = 0;
    cin >> N >> numDoses >> lifeTime >> waitTime;
    for (int i = 0; i < N; i++)
    {
        ll a; cin >> a;
        // cout << lastsUntil << " " << dLeft << endl;
        if(lastsUntil == - 1 || lastsUntil < a || dLeft == 0){
            packsNeeded++;
            lastsUntil = a + waitTime + lifeTime;
            dLeft = numDoses - 1;
        } else {
            dLeft--;
        }
    }
    cout << packsNeeded << endl;
    
}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}