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

void solve(){
    int a, b;
    cin >>a >>b;
    int tempA, tempB; tempA = abs(a); tempB = abs(b);
    int needed = min(tempA, tempB)*2;
    needed += abs(tempA-tempB)*2;
    if(tempA != tempB){
        needed--;
    }
    cout << needed << endl;
}

int T;
int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}