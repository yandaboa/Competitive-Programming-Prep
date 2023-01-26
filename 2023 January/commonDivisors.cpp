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
const int MAX_VAL = 1e6;

// divisors[i] = stores the count of numbers that have i as a divisor
int divs[MAX_VAL + 1];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        const int up = (int) sqrt(a);
        for (int j = 1; j <= up; j++)
        {
            if(a%j == 0){
                divs[j]++;
                if(a/j != j){
                    divs[a/j]++;
                }
            }
        }
    }

    for (int i = MAX_VAL; i >= 1; i--)
    {
        if(divs[i] >= 2){
            cout << i;
            return 0;
        }
    }
    
}