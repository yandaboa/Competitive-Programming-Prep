#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#include <climits>
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
vector<pair<int, int> > rightHalf, leftHalf;
vector<int> horzLines;
priority_queue<pair<int, int> > byX;

int main(){
    ifstream input("balancing.in");
    ofstream output("balancing.out");
    input >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y; input >> x >> y;
        rightHalf.pb(mp(y, x));
        byX.push(mp(x, y));
    }
    sort(all(rightHalf));
    horzLines.pb(0);
    horzLines.pb(pow(10, 9) + 2);
    for (int i = 1; i < sz(rightHalf); i++)
    {
        if(rightHalf[i].f != rightHalf[i - 1].f){
            horzLines.pb(rightHalf[i].f - 1);
        }
    }
    sort(all(horzLines));

    long maxApp = LONG_MAX;
    while(!byX.empty()){
        long currMax = 0;
        auto point = byX.top(); byX.pop();
        point = mp(point.s, point.f);
        auto itr = lower_bound(all(rightHalf), point);
        rightHalf.erase(itr);
        itr = upper_bound(all(leftHalf), point);
        leftHalf.insert(itr, point);
        for (int i = 0; i < sz(horzLines); i++)
        {
            auto leftItr = upper_bound(all(leftHalf), mp(horzLines[i], 0)); leftItr--;
            auto rightItr = upper_bound(all(rightHalf), mp(horzLines[i], 0)); rightItr--;
            long belowLeft = leftItr - leftHalf.begin() + 1, aboveLeft = sz(leftHalf) - (leftItr - leftHalf.begin() + 1);
            long belowRight = rightItr - rightHalf.begin() + 1, aboveRight = sz(rightHalf) - (rightItr - rightHalf.begin() + 1);
            // cout << belowLeft << " " << aboveLeft << " | " << belowRight << " " << aboveRight << endl;
            currMax = max(belowLeft, aboveLeft);
            currMax = max(belowRight, currMax);
            currMax = max(aboveRight, currMax);
            maxApp = min(maxApp, currMax);
        }
    }
    output << maxApp;
}