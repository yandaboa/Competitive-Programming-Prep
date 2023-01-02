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
//cin.tie(0)->sync_with_stdio(0);

int N;
pair<int, int> alone;
vpi shifts;
set<int> onShift;
vi aloneTime;

void process(int a){
    if(shifts[a].s > 0){
        onShift.insert(shifts[a].f);
    } else {
        onShift.erase(shifts[a].f);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    aloneTime.rsz(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int a, b; cin >> a >> b;
        shifts.pb(mp(a, i)); shifts.pb(mp(b + 1, -1*i));
    }
    // shifts.pb(mp(0,0));
    sort(all(shifts));
    for (int i = 1; i < sz(shifts); i++)
    {
        process(i);
        while(i + 1 < sz(shifts) && shifts[i] == shifts[i + 1]){
            i++;
            process(i);
        }
        if(sz(onShift) == 1){
            alone = *onShift.begin();
        } else {
            if(alone.s != 0){
                aloneTime[alone.s] += alone.f - shifts[i].s;
                alone = mp(0, 0);
            }
        }
    }
    //write some code to get total time i give up on this tonight bruh i am not focused
}