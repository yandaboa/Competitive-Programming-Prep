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
multiset<pair<int, int> > cows;

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
        cows.insert(mp(a, b));
    }
    auto itr = cows.begin();
    int total = 0;
    while(!chickens.empty() && itr != cows.end()){
        int cTime = -1*chickens.top(); chickens.pop();
        auto cow = *itr;
        while(cow.s < cTime){
            itr++; cow = *itr;
        }
        if(cow.f <= cTime && cow.s >= cTime){
            total++;
            itr++;
        }
    }
    output << total;
    
}