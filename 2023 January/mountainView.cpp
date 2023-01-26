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


struct Mountain {
    int x;
    int y;
};

bool operator<(const Mountain& a, const Mountain& b){
    if(a.x == b.x){
        return a.y > b.y;
    }
    return a.x < b.x;
}

int N;
vector<Mountain> mts;

int main(){
    ifstream input("mountains.in");
    ofstream output("mountains.out");
    input >> N;
    for (int i = 0; i < N; i++)
    {
        int xV, yV; input >> xV >> yV;
        // cout << xV << " " << yV << endl;
        Mountain mt; mt.x = xV; mt.y = yV;
        mts.pb(mt);
    }
    sort(all(mts));
    // output << "debug";
    // for(auto a : mts){
    //     cout << a.x << " " << a.y << endl;
    // }
    vector<Mountain> fromLeft;
    for(int i = 0; i < sz(mts); i++){
        Mountain curr = mts[i]; int index = 1;
        if(i == 0){
            fromLeft.pb(curr);
        }
        bool erased = true;
        while(index + i < sz(mts) && erased){
            Mountain smaller = mts[index + i];
            if(smaller.x - curr.x <= curr.y - smaller.y){
                index++;
            } else {
                fromLeft.pb(smaller);
                i += index - 1;
                erased = false;
            }
        }
    }
    vector<Mountain> ans;
    for(int i = sz(fromLeft) - 1; i > -1; i--){
        Mountain curr = fromLeft[i]; auto index = -1;
        if(i == sz(fromLeft) - 1){
            ans.pb(curr);
        }
        bool erased = true;
        while(index + i > -1 && erased){
            Mountain smaller = fromLeft[index + i];
            if(curr.x - smaller.x <= curr.y - smaller.y){
                index--;
            } else {
                ans.pb(smaller);
                i += index + 1;
                erased = false;
            }
        }
    }
    output << sz(ans);
}