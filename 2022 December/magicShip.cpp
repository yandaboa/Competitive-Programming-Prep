#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

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

pair<ll, ll> start, finish;
ll N;
ll endV, endH;
string wind;
vll prefV, prefH;

bool works(ll a) {
    ll horzNeeded = finish.f - start.f, vertNeeded = finish.s - start.s;
    ll cycles = a/N;
    // cout << cycles << endl;
    ll b = a%N;
    ll currV = prefV[b] + cycles*endV;
    // cout << endV << endl;
    ll currH = prefH[b] + cycles*endH;
    // cout << currV << " " << vertNeeded << " | " << currH << " " << horzNeeded << endl;
    horzNeeded -= currH; vertNeeded -= currV;
    return (a >= (abs(horzNeeded) + abs(vertNeeded)));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a, b, c, d; cin >> a >> b >> c >> d;
    start = mp(a,b); finish = mp(c, d);
    cin >> N; cin >> wind;
    prefV.rsz(sz(wind) + 1); prefH.rsz(sz(wind) + 1);
    for (int i = 0; i < sz(wind); i++)
    {
        if(wind[i] == 'U'){
            prefV[i + 1] = prefV[i] + 1;
            prefH[i + 1] = prefH[i];
        } else if (wind[i] == 'D'){
            prefV[i + 1]  = prefV[i] - 1; 
            prefH[i + 1] = prefH[i];
        } else if (wind[i] == 'L'){
            prefH[i + 1] = prefH[i] - 1;
            prefV[i + 1] = prefV[i];
        } else {
            prefH[i + 1] = prefH[i] + 1;
            prefV[i + 1] = prefV[i];
        }
    }
    // for (int i = 0; i < sz(prefV); i++)
    // {
    //     cout << prefV[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < sz(prefH); i++)
    // {
    //     cout << prefH[i] << " ";
    // }
    // cout << endl;
    
    bool work = false;
    endV = prefV[sz(prefV) - 1], endH = prefH[sz(prefH) - 1];
    // prefV[0] = endV; prefH[0] = endH;
    ll lo = 0, hi = pow(10, 15);
    while(lo < hi){
        ll mid = (lo + hi)/2;
        if(works(mid)){
            work = true;
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if(work){
        cout << lo;
     }else {
        cout << -1;
     }
    
    // bool isThere = true; int notThere = -1;
    // for (int i = 8; i < 9000; i++)
    // {
    //     if(!works(i)){
    //         isThere = false;
    //         notThere = i;
    //     }
    //     cout << works(i) << endl;
    // }
    // cout << isThere << " " << notThere;
    // cout << endl << works(9);
    
}
