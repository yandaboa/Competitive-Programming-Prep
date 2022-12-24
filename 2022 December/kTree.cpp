#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

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

int N, K, D;
vector<int> arr;

int dp(int a, bool hasD){
    if(a == N){
        if(hasD){
            return 1;
        } else {
            return 0;
        }
    } else if(a > N){
        return 0;
    } else {
        // cout << a << ": ";
        ll sum = 0;
        bool cont = hasD;
        for(int i = 1; i <= K; i++){
            if(i >= D){
                hasD = true;
            }
            int baseIndex = hasD ? 0 : N + 1;
            if(arr[i + a + baseIndex] != -1){
                sum += arr[i + a + baseIndex];
            } else {
                ll temp = dp(a + i, hasD);
                // cout << i << " "<<  temp << " ";
                sum += temp;
            }
        
        }
        cout << endl;
        int index = cont ? 0 : N + 1;
        arr[a + index] = sum;
        return sum;
    }
}

int main(){
    cin >> N >> K >> D;
    ll sum = 0;
    arr.rsz(2*N + 2);
    fill(all(arr), -1);
    for (int i = 1; i <= K; i++)
    {
        if(i >= D){
            sum += dp(i, true);
        } else {
            sum += dp(i, false);
        }
    }
    for (int i = 0; i < sz(arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << sum;
    
}