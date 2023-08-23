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
#include <stack>
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

//take all the mirrors and assign each an ID, then sort by both x and y. Construct an adjList where a mirror can reach all mirrors with the same y horizontally and all x vertically. Then run a BFS from 1 to get to the barn

//DONT CONNECT INDIVIDUAL MIRRORS - connect ranges??

int N;
int startx, starty, endx, endy;
vector<pair<pair<int, int>, int> > byX, byY;
vvi adjList;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> startx >> starty >> endx >> endy;
    for (int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        byX.pb(mp(mp(x, y), i));
        byY.pb(mp(mp(y, x), i));
    }
    sort(all(byX));
    sort(all(byY));
    adjList.rsz(N);
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
}
