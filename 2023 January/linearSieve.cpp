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

vi prime;
int maxN = pow(10, 2);
vb isComponsite(pow(10, 2));

int main(){
    for (int i = 2; i < maxN; i++)
    {
        if(!isComponsite[i]){
            prime.pb(i);
        }
        for (int j = 0; j < sz(prime) && prime[j]*i < maxN; j++)
        {
            isComponsite[i*prime[j]] = true;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
    for (int i = 0; i < sz(prime); i++)
    {
        cout << prime[i] << " ";
    }
    
    
}