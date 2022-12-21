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
#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;

int T;
vll movesToZero;

int main(){
    cin>>T;
    movesToZero.rsz(5000000 + 1);
    ll counter = 4;
    movesToZero[1] = 1;
    movesToZero[2] = 1;
    movesToZero[3] = 1;
    movesToZero[4] = 2;
    movesToZero[5] = 1;
    movesToZero[6] = 3;
    movesToZero[7] = 1;
    movesToZero[8] = 4;

    for (int i = 9; i < sz(movesToZero); i++)
    {
        if(i%4 ==0){
            counter+=2;
            movesToZero[i] = counter;
        } else {
            movesToZero[i] = movesToZero[i - 4] + 2;
        }
    }
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        ll minVal = LONG_MAX;
        for (int j = 0; j < N; j++)
        {
            ll a;
            cin >> a;
            minVal = min(minVal, movesToZero[a]);
        }

        if(minVal%2 == 0){
            cout << "Farmer Nhoj" << endl;
        } else {
            cout << "Farmer John" << endl;
        }
    }
}