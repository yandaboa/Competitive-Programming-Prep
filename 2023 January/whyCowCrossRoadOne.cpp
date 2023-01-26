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

int C, N;
priority_queue<int> chickens;
priority_queue<pi> cows;
multiset<int> endTimes;

int main(){
    ifstream input("helpcross.in");
    ofstream output("helpcross.out");
    input >> C >> N;
    for (int i = 0; i < C; i++)
    {
        int a; input >> a;
        chickens.push(-1*a);
    }
    for (int i = 0; i < N; i++)
    {
        int a, b; input >> a >> b;
        cows.push(mp(-1*a, b));
    }
    int matches = 0;
    while(!chickens.empty()){
        int chick = chickens.top()*-1; chickens.pop();
        while(!cows.empty() && cows.top().f*-1 <= chick){
            endTimes.insert(cows.top().s);
            cows.pop();
        }
        auto itr = endTimes.lower_bound(chick);
        if(itr != endTimes.end()){
            matches++;
            endTimes.erase(endTimes.find(*itr));
        }
    }
    output << matches;
}