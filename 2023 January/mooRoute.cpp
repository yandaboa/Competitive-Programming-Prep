//unsolved... from the january contest period

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
vi bets;
string res;

string solve(int first, int last){
    vpi intervs;
    int lastLarger = -1;
    for (int i = last; i > first; i--)
    {
        if(bets[i] < bets[i + 1]){
            lastLarger = i;
        }
        if(bets[i] > bets[i + 1]){
            solve(i, lastLarger);
        }
        res += 'L';
    }
}

int main(){
    cin >> N; bets.rsz(N); int minV = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        cin >> bets[i];
    }
    res = "";
    for (int i = 0; i < sz(bets); i++)
    {
        res += 'R';
    }
    
    cout << solve(0, N - 1);
    
}