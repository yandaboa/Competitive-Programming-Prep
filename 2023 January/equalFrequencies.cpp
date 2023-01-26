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

int T;
int l, r;
int minl, minr;

int findEff(int N, int factor, vector<pair<int, char> >& freq){
    int left = 0, right = 0;
    int uniques = N/factor;
    int smallest = INT_MAX;
    int eff = 0;
    while(right - left + 1 <= uniques && right < sz(freq)){
        eff += abs(freq[right].f - factor);
        if(right - left + 1 == uniques){
            if(eff < smallest){
                l = left, r = right;
                smallest = eff;
            }
            eff -= abs(freq[left].f - factor);
            left++;
            right++;
        } else {
            if(right == sz(freq) - 1){
                l = 0, r = right;
                smallest = min(smallest, eff);
            }
            right++;
        }
    }
    return smallest;
}

int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N; string str; cin >> str;
        map<char, int> appear;
        vector<pair<int, char> > freq;
        for (int j = 0; j < sz(str); j++)
        {
            appear[str[j]]++;
        }
        for(auto a = appear.begin(); a != appear.end(); a++){
            freq.pb(mp((*a).s, (*a).f));
        }
        sort(all(freq));
        //find all factors of N, test their efficiencies
        vi factors;
        int bound = N;
        for(int j = 1; j*j <= bound; j++){
            if(bound%j == 0){
                factors.pb(j);
                if(j != bound/j){
                    factors.pb(bound/j);
                }
            }
        }
        int minV = INT_MAX;
        int bestFactor = -1;
        for (int j = 0; j < sz(factors); j++)
        {
            // cout << factors[j] << " ";
            if(N/factors[j] > 26){
                continue;
            }
            int eff = findEff(N, factors[j], freq);
            // cout << eff << " ";
            if(eff < minV){
                minV = eff;
                bestFactor = factors[j];
                minl = l, minr = r;
            }
        }
        // cout << minV << endl;
        //generate astring of the most efficient factor
        map<char, int> res;
        map<char, int> extra;
        for (int j = minl; j <= minr; j++)
        {
            if(appear[freq[j].s] < bestFactor){
                extra[freq[j].s]+= bestFactor;
            }
            res[freq[j].s] += bestFactor;
        }
        string alph = "abcdefghijklmnopqrstuvwxyz";
        if(N/bestFactor > sz(freq)){
            int needed = sz(freq);
            // cout << sz(freq) << " " <<N/bestFactor << " ";
            int index = 0;
            while(index < sz(alph) && needed < N/bestFactor){
                if(appear.find((alph[index])) == appear.end()){
                    // cout << "here";
                    extra[alph[index]] += bestFactor;
                    res[alph[index]] += bestFactor;
                    needed+=bestFactor;

                }
                index++;
            }
        }
        // cout << (*extra.begin()).f << " ";
        string answer = "";
        for (int j = 0; j < sz(str); j++)
        {
            if(res[str[j]] > 0){
                // cout << res[str[j]] << endl;
                answer += str[j];
                res[str[j]]--;
            } else{
                // cout << "here";
                for(auto a = extra.begin(); a != extra.end(); a++){
                    // cout << (*a).f << " " << (*a).s << endl;
                    if((*a).s > appear[(*a).f]){
                        answer += (*a).f;
                        extra[(*a).f]--;
                        res[(*a).f]--;
                        break;
                    }
                }
            }
        }

        int diff = 0;
        for (int j = 0; j < sz(answer); j++)
        {
            if(answer[j] != str[j]){
                diff++;
            }
        }
        
        cout << diff << endl << answer << endl;
        
    }
}