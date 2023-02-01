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

int N, a;
//first prime factorize the tc - sieve and loop until 1000

vi largestPrime;

void solve(){
    cin >> a;
    map<int, int> primeFact;
    for (int i = 2; i*i <= a; i++)
    {
        while(a % i == 0){
            primeFact[i]++;
            a/=i;
        }
    }
    if(a > 1){
        primeFact[a]++;
    }
    vvi merger; merger.rsz(31); ll runProd = 1;
    for(auto b = primeFact.begin(); b!=primeFact.end(); b++){
        // cout << (*b).f << " " << (*b).s << endl;
        runProd *= (*b).f;
        merger[(*b).s].pb((*b).f);
    }
    // cout << runProd;
    ll maxSum = 0, lastUsed = 0;
    for (int i = 1; i < sz(merger); i++)
    {
        if(sz(merger[i]) > 0){
            maxSum += runProd*(i-lastUsed);
            lastUsed = i;
            for (int j = 0; j < sz(merger[i]); j++)
            {
                runProd /= merger[i][j];
            }
        } 
        if(runProd <= 1){
            break;
        }
    }
    cout << maxSum << endl;
}

void sieve(){
    largestPrime.rsz(pow(10, 6) + 1); fill(all(largestPrime), 0);
    for (int i = 2; i < sz(largestPrime); i++)
    {
        if(largestPrime[i] == 0){
            largestPrime[i] = i;
            for (int j = 2; i*j < sz(largestPrime); j++)
            {
                largestPrime[i*j] = i;
            }
        }
    }
}

int main(){
    cin >> N;
    // sieve();
    for (int i = 0; i < N; i++)
    {
        solve();
    }
    
}
//then always merge as many distinct factors as possible - repeat as long as you can form numbers that consist of more than one distinct prime factor