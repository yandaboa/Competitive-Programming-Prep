#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

set<string> created;
string ogString;

void create(int a, string soFar, string left){
    if(a == sz(ogString)){
        created.insert(soFar);
        return;
    }
    for(int i = 0; i < sz(left); i++){
        string temp;
        temp = left.substr(0, i) + left.substr(i + 1, sz(left) - i - 1);
        string temp2 = soFar + string(left.substr(i, 1));
        create(a + 1, temp2, temp);
    }
}

int main() {
    setIO();
    cin >> ogString;
    vector<string> allStrs;
    sort(all(ogString));
    do{
        allStrs.push_back(ogString);
    } while(next_permutation(all(ogString)));
    cout << sz(allStrs) << endl;
    for (int i = 0; i < sz(allStrs); i++)
    {
        cout << allStrs[i] << endl;
    }
    

    // create(0, "", ogString);
    // for(auto i : created){
    //     allStrs.pb(i);
    // }

    // sort(all(allStrs));
    // cout << sz(allStrs) << endl;
    // for (int i = 0; i < sz(allStrs); i++)
    // {
    //     cout << allStrs[i] << endl;
    // }
    
}