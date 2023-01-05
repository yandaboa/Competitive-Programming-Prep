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
vi divBy;

void sieve(){
    divBy.rsz(pow(10,6) + 1);
    divBy[1] = 1;
    for (int i = 2; i < sz(divBy); i++)
    {
        if(divBy[i] == 0){
            for (int j = 1; j*i < sz(divBy); j++)
            {
                divBy[i*j] = i;
            }
        }
    }
}

void divs(int a){
    vi prime;
    while(a != 1){
        prime.pb(divBy[a]);
        a /= divBy[a];
    }
    map<int, int> occs;
    for (int i = 0; i < sz(prime); i++)
    {
        occs[prime[i]]++;
    }
    ll product = 1;
    for(auto itr = occs.begin(); itr != occs.end(); itr++){
        product *= ((*itr).s + 1);
    }
    cout << product << " ";
    
}

int main(){
    cin >> N;
    sieve();
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        divs(a);
    }
    
}