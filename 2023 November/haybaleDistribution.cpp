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
#include <stack>
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
vll fromLeft, fromRight;
vi barns;

void solve(){
    int a, b; cin >> a >> b;
    int lo = 0, hi = 1000001;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        ll currValue = fromLeft[mid]*a + fromRight[mid]*b;
        ll leftValue = 1000000000, rightValue = 1000000000;
        if(mid > 0){
            leftValue = fromLeft[mid - 1]*a + fromRight[mid - 1]*b;
        }
        if(mid < 1000001){
            rightValue = fromLeft[mid+1]*a + fromRight[mid + 1]*b;
        }
        if((leftValue > currValue && rightValue > currValue) || (leftValue == currValue && rightValue > currValue) || (leftValue > currValue && rightValue == currValue)){
            cout << currValue << endl;
            return;
        } else if(leftValue > currValue && rightValue < currValue){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

}

int main(){
    cin >> N;
    fromLeft.rsz(1000001); fromRight.rsz(1000001); barns.rsz(N);
    for (int i = 0; i < N; i++)
    {
        cin >> barns[i];
    }
    sort(all(barns));

    int last = 0, j = 0, counter = 0;
    for (int i = 0; i < sz(barns); i++)
    {
        j = barns[i];
        // cout << barns[i] << " ";
        for (int a = last - 1 < 0 ? 1 : last; a <= j; a++)
        {
            fromLeft[a] = fromLeft[a-1]+counter;
            // cout << counter << " ";
        }
        counter++;
        last = j + 1;
    }
    // cout << endl;
    for (int i = j; i < sz(fromLeft); i++)
    {
        fromLeft[i] = fromLeft[i-1] + sz(barns);
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << fromLeft[i] << " ";
    // }
    
    int lastR = sz(fromRight) - 1, r = 0;
    counter = 0;
    for(int i = sz(barns) - 1; i > -1; i--){
        r = barns[i];
        for(int a = lastR; a >= r; a--){
            fromRight[a] = fromRight[a+1] +counter;
        }
        counter++;
        lastR = barns[i] - 1;
    }
    for (int i = lastR; i >= 0; i--)
    {
        fromRight[i] = fromRight[i+1] + sz(barns);
    }
    // cout << "checkpoint";
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        solve();
    }
}