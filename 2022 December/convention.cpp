#include <iostream>
#include <vector>
#include <limits>
#include <climits>
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

ll N, M, C;
vll cows;

bool timeValid(ll a){
    cout << endl;
    ll counter = 0, lastInd = 0, lastMin = cows[0], pointer = 0;

    while (pointer < N)
    {
        if(cows[pointer] - lastMin > a || pointer - lastInd > C - 1){
            cout << lastMin << " " << cows[pointer] << " " << lastInd << " " << pointer << endl;
            counter++;
            lastMin = cows[pointer];
            lastInd = pointer;
        }
        pointer++;
    }
    counter++;
    return !(counter > M);
}

int main(){
    ifstream input("convention.in");
    ofstream output("convention.out");
    input >> N >> M >> C;
    for (int i = 0, a; i < N; i++)
    {
        input >> a;
        cows.pb(a);
    }
    
    sort(all(cows));
    
    ll max = cows[sz(cows) - 1] - cows[0], min = 0;
    while(min < max){
        ll mid = (max + min)/2;
        if(timeValid(mid)){
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    timeValid(4);
    output << min;
}