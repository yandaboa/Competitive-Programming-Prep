#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N, minX, minY, maxX, maxY;
vpi byX, byY;

void updateMinMax(){
    minX = byX[0].f;
    maxX = byX[sz(byX) - 1].f;
    minY = byY[0].f;
    maxY = byY[sz(byY) - 1].f;
}

void removeOutlier(){
    vpi::iterator itr, yItr; int diff, yDiff;
    if(byX[sz(byX) - 1].f - byX[sz(byX) - 2].f > byX[1].f - byX[0].f){
        itr = byX.end(); itr--;
        if((*itr).s == maxY){
            maxY = byY[sz(byY) - 2].f;
        } else if ((*itr).s == minY){
            minY = byY[1].f;
        }
        diff = (byX[sz(byX) - 1].f - byX[sz(byX) - 2].f)*(maxY - minY);
    } else if (byX[sz(byX) - 1].f - byX[sz(byX) - 2].f == byX[1].f - byX[0].f){
        pi yIncom = byX[sz(byX) - 1], secondYIncom = byX[0];
        int firstDiff = lower_bound(all(byY), mp(yIncom.s, yIncom.f)) - byY.begin();
        int secondDiff = lower_bound(all(byY), mp(secondYIncom.s, secondYIncom.f)) - byY.begin();
        if(sz(byY) - firstDiff - 1 > secondDiff){
            itr = byX.end(); itr--;
            if((*itr).s == maxY){
                maxY = byY[sz(byY) - 2].f;
            } else if ((*itr).s == minY){
                minY = byY[1].f;
            }
            diff = (byX[sz(byX) - 1].f - byX[sz(byX) - 2].f)*(maxY - minY);
        } else {
            itr = byX.begin();
            if((*itr).s == maxY){
                maxY = byY[sz(byY) - 2].f;
            } else if ((*itr).s == minY){
                minY = byY[1].f;
            }
            diff = (byX[1].f - byX[0].f)*(maxY - minY);
        }
    } else {
        itr = byX.begin();
        if((*itr).s == maxY){
            maxY = byY[sz(byY) - 2].f;
        } else if ((*itr).s == minY){
            minY = byY[1].f;
        }
        diff = (byX[1].f - byX[0].f)*(maxY - minY);
    }
    if(byY[sz(byY) - 1].f - byY[sz(byY) - 2].f > byY[1].f - byY[0].f){
        yItr = byY.end(); yItr--;
        if((*yItr).s == maxX){
            maxX = byX[sz(byX) - 2].f;
        } else if ((*yItr).s == minX){
            minX = byX[1].f;
        }
        yDiff = (byY[sz(byY) - 1].f - byY[sz(byY) - 2].f)*(maxX - minX);
    } else if (byY[sz(byY) - 1].f - byY[sz(byY) - 2].f == byY[1].f - byY[0].f){
        pi xIncom = byY[sz(byY) - 1], secondXIncom = byY[0];
        int firstDiff = lower_bound(all(byX), mp(xIncom.s, xIncom.f)) - byX.begin();
        int secondDiff = lower_bound(all(byX), mp(secondXIncom.s, secondXIncom.f)) - byX.begin();
        if(sz(byX) - firstDiff - 1 > secondDiff){
            yItr = byY.end(); yItr--;
            if((*yItr).s == maxX){
                maxX = byX[sz(byX) - 2].f;
            } else if ((*yItr).s == minX){
                minX = byX[1].f;
            }
            yDiff = (byY[sz(byY) - 1].f - byY[sz(byY) - 2].f)*(maxX - minX);
        } else {
            yItr = byY.begin();
            if((*yItr).s == maxX){
                maxX = byX[sz(byX) - 2].f;
            } else if ((*yItr).s == minX){
                minX = byX[1].f;
            }
            yDiff = (byY[1].f - byY[0].f)*(maxX - minX);
        }
    } else {
        yItr = byY.begin();
        if((*yItr).s == maxX){
            maxX = byX[sz(byX) - 2].f;
        } else if ((*yItr).s == minX){
            minX = byX[1].f;
        }
        yDiff = (byY[1].f - byY[0].f)*(maxX - minX);
    }
    if(yDiff > diff){
        pi point = *yItr;
        byY.erase(yItr);
        byX.erase(lower_bound(all(byX), mp(point.s, point.f)));
    } else {
        pi point = *itr;
        byX.erase(itr);
        byY.erase(lower_bound(all(byY), mp(point.s, point.f)));
    }
    updateMinMax();
}

int main(){
    ifstream input("reduce.in");
    ofstream output("reduce.out");
    input >> N;
    minX = INT_MAX, minY = INT_MAX, maxY = 0, maxX = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y; input >> x >> y;
        minX = min(x, minX); minY = min(y, minY); maxY = max(maxY, y); maxX = max(x, maxX);
        byX.pb(mp(x, y)); byY.pb(mp(y, x));
    }
    sort(all(byX)); sort(all(byY));

    for (int i = 0; i < 3; i++)
    {
        removeOutlier();
    }
    
    output << (maxX - minX)*(maxY - minY);
}