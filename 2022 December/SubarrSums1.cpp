#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using pi = pair<int, int>;
using vll = vector<ll>;
#define pb push_back
#define mp makepair
#define rsz resize
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define f first
#define s second

int n, x;
vi arr;

int main(){
    cin >> n >> x;
    arr.rsz(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = 0, valid = 0;
    ll currSum = 0;
    while(right < sz(arr)){
        if(currSum == x){
            valid++;
            right++;
            if(right == sz(arr)){
                break;
            }
            currSum += arr[right];
            continue;
        }
        if(currSum < x){
            right++;
            if(right == sz(arr)){
                break;
            }
            currSum += arr[right];
        } else if(currSum > x){
            currSum -= arr[left];
            left++;
        }
    }
    
    cout << valid;
}