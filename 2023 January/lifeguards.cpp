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

int N;
map<int, vpi> timeline;

int main(){
    ifstream input("lifeguards.in");
    ofstream output("lifeguards.out");
    input >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b; input >> a >> b;
        timeline[a].pb(mp(i, 1));
        timeline[b].pb(mp(i, -1));
    }
    // for(auto a : timeline){
    //     cout << a.f << " ";
    //     for (int i = 0; i < sz(a.s); i++)
    //     {
    //         cout << a.s[i].f << " " << ;
    //     }
    //     cout << endl;
    // }
    vi aloneTimes; aloneTimes.rsz(N);
    // sort(all(timeline));
    int prevTime = 0;
    int totTime = 0;
    // timeline[pow(10, 9)].pb(mp(N, 1));
    set<int> active;
    for (auto itr = timeline.begin(); itr != timeline.end(); itr++)
    {
        // cout << timeline[i].f << " " << timeline[i].s << endl;
        auto val = *itr;
        if(sz(active) == 1){
            aloneTimes[*active.begin()] += val.f - prevTime;
        }
        if(sz(active) > 0){
            totTime += val.f - prevTime;
        }
        for (int i = 0; i < sz(val.s); i++)
        {
            if(val.s[i].s == 1){
                active.insert((val.s[i]).f);
            } else {
                active.erase((val.s[i]).f);
            }
            // cout << val.s[i] << " ";
        }
        // cout << endl;
        prevTime = val.f;
    }
    
    int minV = INT_MAX; bool allZero = true;
    for(int i = 0; i < sz(aloneTimes); i++){
        // cout << a << " ";
        if(aloneTimes[i] > 0){
            allZero = false;
            minV = min(minV, aloneTimes[i]);
        }
    }
    cout << totTime;
    if(allZero){
        output << totTime;
    } else {
        output << totTime - minV;
    }
}