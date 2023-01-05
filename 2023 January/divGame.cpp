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

ll N;

int main(){
    cin >> N;
    vi factors;
    for (ll i = 2; i*i <= N; i++)
    {
        while(N%i == 0){
            N /= i;
            factors.pb(i);
        }
    }
    if(N > 1){
        factors.pb(N);
    }
    // for (int i = 0; i < sz(factors); i++)
    // {
    //     cout << factors[i] << " ";
    // }
    map<int, int> primeFact;
    for (int i = 0; i < sz(factors); i++)
    {
        primeFact[factors[i]]++;
    }
    int total = 0;
    for(auto a : primeFact){
        int largest = 0;
        for (int i = 1; i*(i+1)/2 <= a.s; i++)
        {
            largest = i;
        }
        total += largest;
    }
    cout << total;
    
}