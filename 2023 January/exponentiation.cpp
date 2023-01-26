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

void mod(int& a){
    int modulus = pow(10, 9);
    a %= (modulus + 7);
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        if(a == 0){
            if(b == 0){
                cout << 1 << endl;
                break;
            }
            cout << 0 << endl;
        }
        if(b == 0){
            cout << 1 << endl;
        }
        vi exponents; exponents.pb(a);
        int count = 2;
        while(count < pow(10, 9)){
            int val = pow(*exponents.rbegin(), 2);
            mod(val);
            exponents.pb(val);
            count *= 2;
        }
        
    }
    
}