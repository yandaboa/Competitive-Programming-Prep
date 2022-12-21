#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int cows;
map<pair<int, int>, set<int> > vertices;
vector<pair<int, int> > cowCoords;
vector<set<int> > subsetsSoFar;

set<int> diffInSets(set<int> a, set<int> b){
    if(a.size() > b.size()){
        for(auto c : b){
            a.erase(c);
        }
        return a;
    } else {
        for(auto c : a){
            b.erase(c);
        }
        return b;
    }
}

int main(){
    cin >> cows;

    for(int i = 0; i < cows; i++){
        int a, b;
        cin >> a >> b;
        cowCoords.push_back(make_pair(a, b));
    }

    // cout << endl;

    sort(cowCoords.begin(), cowCoords.end());
    
    // for (int i = 0; i < cowCoords.size(); i++)
    // {
    //     cout << cowCoords[i].first << " " << cowCoords[i].second << endl;
    // }
    // cout << endl;
    
    int maxYSoFar = cowCoords[0].second;
    set<int> empty;
    vertices[cowCoords[0]] = empty;
    for(int i = 1; i < cows; i++){
        set<int> currSet;
        for (int j = 0; j <= i; j++)
        {
            currSet.insert(j);
        }
        // cout << maxYSoFar << " ";
        if(cowCoords[i].second >= maxYSoFar){
            maxYSoFar = cowCoords[i].second;
            vertices[cowCoords[i]] = currSet;
        } else {
            vertices[make_pair(cowCoords[i].first, maxYSoFar)] = currSet;
            cowCoords.push_back(make_pair(cowCoords[i].first, maxYSoFar));
            set<int> allSmallerPoints;
            for(int j = 0; j < i; j++){
                if(cowCoords[j].second <= cowCoords[i].second){
                    allSmallerPoints.insert(j);
                }
            }
            vertices[cowCoords[i]] = allSmallerPoints;
        }
    }

    sort(cowCoords.begin(), cowCoords.end());
    // for (int i = 0; i < cowCoords.size(); i++)
    // {
    //     cout << cowCoords[i].first << " " << cowCoords[i].second << endl;
    // }

    // cout << endl;

    // for(auto const& [key, val] : vertices){
    //     cout << endl << "(" << key.first << ", " << key.second << ") - " << endl;
    //     for (auto a : val){
    //         cout << a << " ";
    //     }
    // }

    int total = 0;
    for(int i = 0; i < cowCoords.size(); i++){
        total++;
        set<int> temp;
        temp.insert(i);
        // subsetsSoFar.push_back(temp);
        for(int j = 0; j < i; j++){
            bool contains = false;
            set<int> diff = diffInSets(vertices[cowCoords[i]], vertices[cowCoords[j]]);
            for(int a = 0; a < subsetsSoFar.size(); a++){
                if(subsetsSoFar[a] == diff){
                    contains = true;
                }
            }
            if(!contains){
                total++;
                subsetsSoFar.push_back(diff);
            }
        }
    }
    total++;
    cout << total;

}