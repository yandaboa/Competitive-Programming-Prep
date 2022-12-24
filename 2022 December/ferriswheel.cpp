#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>
 
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
 
ll N, X;
vi children;
vb used;
priority_queue<ll> firstHalf, secondHalf;
 
int main(){
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        ll a; cin >> a;
        children.pb(a);
    }
    sort(all(children));
 
    for (int i = 0; i < sz(children); i++)
    {
        if(i >= sz(children)/2){
            secondHalf.push(children[i]);
        } else {
            firstHalf.push(-1*children[i]);
        }
    }
 
    ll needed = 0;
    while(sz(firstHalf) > 0 && sz(secondHalf) > 0){
        ll a = -1*firstHalf.top(), b = secondHalf.top();
        if(a + b <= X){
            firstHalf.pop();
            secondHalf.pop();
            needed++;
        } else {
            secondHalf.pop();
            needed++;
        }
    }

    if(!firstHalf.empty()){
        while(sz(firstHalf) > 1){
            ll a = -1*firstHalf.top(); firstHalf.pop(); ll b = -1*firstHalf.top();
            if(a + b <= X){
                firstHalf.pop();
                needed++;
            } else {
                firstHalf.pop();
                needed+=2;
            }
        }
        needed += sz(firstHalf);

    } else {
        while(sz(secondHalf) > 1){
            ll a = secondHalf.top(); secondHalf.pop(); ll b = secondHalf.top();
            if(a + b <= X){
                secondHalf.pop();
                needed++;
            } else {
                secondHalf.pop();
                needed+=2;
            }
        }
        needed += sz(secondHalf);
    }
    cout << needed;
 
}