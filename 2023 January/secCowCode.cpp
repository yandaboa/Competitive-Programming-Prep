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
string str;
ll N;
vll strLengths;

int main(){
    ifstream input("cowcode.in");
    ofstream output("cowcode.out");
    // cin.tie(0)->sync_with_stdio(0);
    input >> str >> N;
    for (ll i = sz(str); i < N; i*=2)
    {
        strLengths.pb(i);
        // cout << i << " ";
    }
    while(N > sz(str)){
        auto itr = lower_bound(all(strLengths), N); itr--;
        N -= *itr;
        N--;
        if(N==0){
            N = *itr;
        }
    }
    output << str[N - 1];
}