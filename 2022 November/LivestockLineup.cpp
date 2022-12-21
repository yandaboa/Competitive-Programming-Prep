#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int cows;
vector<vector<int> > adjList;
map<string, int> alphOrder;
vector<bool> isUsed;
vector<int> cowArrange;

int main(){
    ifstream input("lineup.in");
    ofstream output("lineup.out");
    alphOrder["Beatrice"] = 0;
    alphOrder["Belinda"] = 1;
    alphOrder["Bella"] = 2;
    alphOrder["Bessie"] = 3;
    alphOrder["Betsy"] = 4;
    alphOrder["Blue"] = 5;
    alphOrder["Buttercup"] = 6;
    alphOrder["Sue"] = 7;

    input >> cows;
    isUsed.resize(8, false);
    adjList.resize(8);

    for(int i = 0; i < cows; i++){
        string a, trash, f;
        input >> a >> trash >> trash >> trash >> trash >> f;
        // cout << a << " " << f << endl;
        adjList[alphOrder[a]].push_back(alphOrder[f]);
        adjList[alphOrder[f]].push_back(alphOrder[a]);
        // cout << adjList[alphOrder[a]][0] << " " << adjList[alphOrder[f]][0] << endl;
    }
    
    // cout << "done";

    for(int i = 0; i < 8; i++){
        // cout << i;
        if(!isUsed[i] && adjList[i].size() == 0){
            cowArrange.push_back(i);
            isUsed[i] = true;
        }

        if(adjList[i].size() == 1 && !isUsed[i]){
            cowArrange.push_back(i);
            isUsed[i] = true;
            int x = i;
            while(adjList[x].size() > 0){
            
                if(adjList[x].size() == 1){
                    if(!isUsed[adjList[i][0]]){
                        cowArrange.push_back(adjList[x][0]);
                        isUsed[adjList[x][0]] = true;
                        x = adjList[x][0];
                        continue;
                    } else {
                        break;
                    }
                }

                if(adjList[x].size() == 2){
                    if(!isUsed[adjList[x][0]]){
                        cowArrange.push_back(adjList[x][0]);
                        isUsed[adjList[x][0]] = true;
                        x = adjList[x][0];
                    } else if (!isUsed[adjList[x][1]]){
                        cowArrange.push_back(adjList[x][1]);
                        isUsed[adjList[x][1]] = true;
                        x = adjList[x][1];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 8; i++){
        // cout << cowArrange[i] << " ";
        for(auto const& [key, val] : alphOrder){
            if(val == cowArrange[i]){
                output << key << endl;
                break;
            }
        }
    }
}