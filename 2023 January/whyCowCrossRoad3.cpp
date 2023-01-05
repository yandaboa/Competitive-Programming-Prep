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

int N, K, R;
set<pair<pair<int, int>, pair<int, int> > > roads;
vector<vector<bool> > visited;
vector<vector<bool> > cowLoc;
int cows;
vi cowInComp;

void ff(int a, int b, int fa, int fb){
    if(a < 0 || a >= N || b < 0 || b >= N){
        return;
    }
    if(visited[a][b]){
        return;
    }
    if(roads.find(mp(mp(a,b), mp(fa, fb))) != roads.end()){
        return;
    }
    visited[a][b] = true;
    if(cowLoc[a][b]){
        cows++;
    }
    ff(a + 1, b, a, b);
    ff(a, b + 1, a, b);
    ff(a - 1, b, a, b);
    ff(a, b - 1, a, b);
}

int main(){
    ifstream input("countcross.in");
    ofstream output("countcross.out");
    input >> N >> K >> R;
    for (int i = 0; i < R; i++)
    {
        int a, b, c, d; input >> a >> b >> c >> d; a--; b--; c--; d--;
        roads.insert(mp(mp(a,b), mp(c,d)));
        roads.insert(mp(mp(c,d), mp(a,b)));
    }
    visited.rsz(N); cowLoc.rsz(N);
    for (int i = 0; i < N; i++)
    {
        visited[i].rsz(N);
        cowLoc[i].rsz(N);
    }
    for (int i = 0; i < K; i++)
    {
        int a, b; input >> a >> b; a--; b--;
        cowLoc[a][b] = true;
    }
    
    int components = 0, totalCows = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!visited[i][j]){
                cows = 0;
                ff(i, j, 0, 0);
                totalCows += cows;
                cowInComp.pb(cows);
                components++;
            }
        }
    }
    ll tots = 0;
    for (int i = 0; i < sz(cowInComp); i++)
    {
        // cout << cowInComp[i] << " ";
        tots += cowInComp[i]*(totalCows - cowInComp[i]);
    }
    tots /= 2;

    output << tots;
}