#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>

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
multiset<pair<int, int> > rightHalf, leftHalf;
priority_queue<pair<int, int> > byX;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        rightHalf.insert(mp(y, x));
        byX.push(mp(x, y));
    }

    int maxApp = INT_MAX;
    while(!byX.empty()){
        auto point = byX.top(); byX.pop();
        rightHalf.erase(rightHalf.find(mp(point.s, point.f)));
        leftHalf.insert(mp(point.s, point.f));
        int index = -1;
        for(auto it = leftHalf.begin(); it != leftHalf.end(); it++){
            index++;
            int edge = (*it).f - 1;
            auto itr = rightHalf.upper_bound(mp(edge, 0)); itr--;
            maxApp = max(index, sz(leftHalf) - index);
        }
    }
}