#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

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

int N, trash, minSoFar, maxSoFar;
vi arr;

void allPossible(int start, int intakeNum){
    
}

int main(){
    cin >> N;
    arr.rsz(N);
    cin >> arr[0];
    cin >> arr[1];
    minSoFar = 0;
    maxSoFar = arr[1];

    allPossible(2, N - 2);
}