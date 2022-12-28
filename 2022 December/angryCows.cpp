#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N, K;
vi haybales;

bool works(int a){
    int maxLength = 2*a;
    int needed = 1, last = haybales[0];
    for (int i = 1; i < sz(haybales); i++)
    {
        if(haybales[i] - last > maxLength){
            needed++;
            last = haybales[i];
        }
    }
    return !(needed > K);
    
}

int main(){
    ifstream input("angry.in");
    ofstream output("angry.out");
    input >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a; input >> a;
        haybales.pb(a);
    }
    sort(all(haybales));

    int lo = 0, hi = pow(10, 9);
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(works(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    output << lo;
}