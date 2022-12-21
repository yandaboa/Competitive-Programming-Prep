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

int N, K;
vi diamonds;
vi intervals;

int main(){
    ifstream input("diamond.in");
    ofstream output("diamond.out");
    input >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a;
        input >> a;
        diamonds.pb(a);
    }
    sort(all(diamonds));
    intervals.rsz(N);
    for (int i = 0; i < N; i++)
    {
        intervals[i] =lower_bound(all(diamonds), diamonds[i] - K) - diamonds.begin();
    }
    
    int longestLeng = 1, leng = 1, val = 0;

    for (int i = 1; i < N; i++)
    {
        if(intervals[i] != intervals[i - 1]){
            if(leng > longestLeng){
                longestLeng = leng;
                val = intervals[i - 1];
                leng = 1;
            } else {
                leng = 1;
            }
        } else {
            leng++;
        }
    }

    int longestLeng2 = 1;
    leng = 1;

    for (int i = 1; i < N; i++)
    {
        if(intervals[i] != intervals[i - 1]){
            if(leng > longestLeng2 && intervals[i - 1] != val){
                longestLeng2 = leng;
                leng = 1;
            } else {
                leng = 1;
            }
        } else {
            leng++;
        }
    }
    output << longestLeng + longestLeng2;
    
    
}