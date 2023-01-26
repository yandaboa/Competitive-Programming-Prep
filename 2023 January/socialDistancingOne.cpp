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
int smallest;
vector<int> intervals;

int main(){
    ifstream input("socdist1.in");
    ofstream output("socdist1.out");
    input >> N;
    string str; input >> str;
    int zeroes = 0;
    multiset<int> seperate, together;
    bool first = true;
    for (int i = 0; i < sz(str); i++)
    {
        if(str[i] == '1'){
            first = false;
            if(i != 0){
                if(first){
                    seperate.insert(zeroes - 1);
                    first = false;
                    if(zeroes >= 2){
                        together.insert(((zeroes - 1) - 1)/2);
                    }
                } else {
                    intervals.pb(zeroes);
                }
            }
            zeroes = 0;
        } else {
            zeroes++;
        }
    }
    if(str[sz(str) - 1] == '0'){
        if(zeroes >= 2){
            if(first){
                together.insert(zeroes - 2);
            } else {
                together.insert(((zeroes - 1) - 1)/2);
            }
        }
        seperate.insert(zeroes - 1);
    }


    for (int i = 0; i < sz(intervals); i++)
    {
        // cout << intervals[i] << " ";
        if(intervals[i] >= 2){
            together.insert(((intervals[i] - 1) - 1)/3);
        }
        seperate.insert((intervals[i] - 1)/2);
    }

    for(auto a = seperate.begin(); a != seperate.end(); a++){
        cout << *a << " ";
    }
    cout << endl;
    for(auto a = together.begin(); a != together.end(); a++){
        cout << *a << " ";
    }
    cout << endl;
    int biggest;
    if(sz(seperate) > 1){
        auto itr = seperate.rbegin(); itr++;
        biggest = max(*together.rbegin(), *itr);
    } else {
        biggest = *together.rbegin();
    }
    output << biggest + 1;
}