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

int G, N;
vector<pair<ll, pair<ll, ll> > > grazings;

long double dist(ll x, ll y, ll endX, ll endY){
    ll xDiff = abs(x - endX), yDiff = abs(y - endY);
    if(xDiff > pow(10, 9) || yDiff > pow(10,9)){
        return pow(10, 9) + 1;
    }
    xDiff *= xDiff;
    yDiff *= yDiff;
    long double dist = xDiff + yDiff;
    dist = sqrt(dist);
    // cout << dist << endl;
    return dist;
    // return sqrt(pow(endX - x, 2) + pow(endY - y, 2));
}

int main(){
    cin >> G >> N;

    for (int i = 0; i < G; i++)
    {
        int t, x, y; cin >> x >> y >> t;
        grazings.pb(mp(t, mp(x, y)));
    }
    sort(all(grazings));
    // for(int i = 0; i < sz(grazings); i++){
    //     cout << grazings[i].s.f << " " << grazings[i].s.s << " " << grazings[i].f << endl;
    // }
    int works = 0;
    for (int i = 0; i < N; i++)
    {
        ll t, x, y; cin >> x >> y >> t;
        pair<ll, pair<ll, ll> > alibi = mp(t, mp(x, y));
        int lo = 0, hi = sz(grazings) - 1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(grazings[mid].f < alibi.f){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        // cout << lo << endl;
        bool cantReachSmaller;
        if(lo == 0){
            if(dist(alibi.s.f, alibi.s.s, grazings[lo].s.f, grazings[lo].s.s) > grazings[lo].f - alibi.f){
                // cout << alibi.s.f << " " << alibi.s.s << " " << alibi.f << endl;
                works++;
            }
        } else if (lo == sz(grazings) - 1 && alibi.f > grazings[lo].f){
            if(dist(alibi.s.f, alibi.s.s, grazings[lo].s.f, grazings[lo].s.s) > alibi.f - grazings[lo].f){
                // cout << "o" << alibi.s.f << " " << alibi.s.s << " " << alibi.f << endl;
                works++;
            }
        } else {
            cantReachSmaller = (dist(alibi.s.f, alibi.s.s, grazings[lo - 1].s.f, grazings[lo - 1].s.s) > alibi.f - grazings[lo - 1].f);
            if(dist(alibi.s.f, alibi.s.s, grazings[lo].s.f, grazings[lo].s.s) > grazings[lo].f - alibi.f || cantReachSmaller){
                // cout << alibi.s.f << " " << alibi.s.s << " " << alibi.f << endl;
                works++;
            }
        }
        
    }
    cout << works;
    
}