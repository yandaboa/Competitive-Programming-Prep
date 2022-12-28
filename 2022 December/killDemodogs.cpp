#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
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

unsigned long long mod(unsigned long long a){
    unsigned long long modulus = pow(10, 9) + 7;
    // cout << modulus << ' ';
    a = a%modulus;
    return a;
}

int T;
int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        unsigned long long N; cin >> N;
        unsigned long long product = N + 1;
        product *= N;
        
        product = mod(product);
        // cout << product << " ";
        unsigned long long mult = N; mult *= 2; mult++;
        mult = mod(mult);
        product *= mult;
        
        product /= 6;
        product = mod(product);
        // cout << product << ' ';
        unsigned long long again = product;
        product *= 2022;
        product = mod(product);
        unsigned long long minus = N + 1; minus *= N; minus /= 2;
        minus = mod(minus);
        minus *= 2022; minus = mod(minus);
        // cout << minus << ' ';
        // cout << minus << " " << again << " ";
        // cout << again << ' ';

        // cout << again << ' ';
        product *= 2;
        product -= minus;
        product = mod(product);
        cout << product << endl;
    }
    
}