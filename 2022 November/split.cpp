#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

int n;
vector<pair<int, int> > cowsX, cowsY;
vector<pair<int, int> > backPrefSumX, backPrefSumY;

int main(){
    ifstream input("split.in");
    ofstream output("split.out");
    input >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        input >> x >> y;
        cowsX.push_back(make_pair(x, y));
        cowsY.push_back(make_pair(y, x));
    }
    sort(cowsX.begin(), cowsX.end());
    sort(cowsY.begin(), cowsY.end());
    
    cout << endl;
    for (int i = 0; i < cowsX.size(); i++)
    {
        cout << cowsX[i].first << " " << cowsX[i].second << endl;
    }
    cout << endl;
    for (int i = 0; i < cowsY.size(); i++)
    {
        cout << cowsY[i].second << " " << cowsY[i].first << endl;
    }
    cout << endl;

    backPrefSumX.resize(n + 1);
    backPrefSumX[backPrefSumX.size() - 1] = make_pair(1000000001, 0);
    for(int i = backPrefSumX.size() - 2; i >= 0; i--){
        backPrefSumX[i] = make_pair(min(backPrefSumX[i + 1].first, cowsX[i].second), max(backPrefSumX[i + 1].second, cowsX[i].second));
    }

    backPrefSumY.resize(n + 1);
    backPrefSumY[backPrefSumY.size() - 1] = make_pair(1000000001, 0);
    for(int i = backPrefSumY.size() - 2; i >= 0; i--){
        backPrefSumY[i] = make_pair(min(backPrefSumY[i + 1].first, cowsX[i].second), max(backPrefSumY[i + 1].second, cowsY[i].second));
    }


    int overallArea = (cowsX[cowsX.size() - 1].first - cowsX[0].first) * (cowsY[cowsY.size() - 1].first - cowsY[0].first);

    int maxYSoFar = -1;
    int minArea = 1000000001;
    int minYSoFar = 1000000001;
    for(int i = 0; i < cowsX.size() - 1; i++){
        maxYSoFar = max(maxYSoFar, cowsX[i].second);
        minYSoFar = min(minYSoFar, cowsX[i].second);
        if(cowsX[i].first == cowsX[i+1].first){
            continue;
        }
        int areaA, areaB;
        areaA = (cowsX[i].first - cowsX[0].first)*(maxYSoFar - minYSoFar);
        int next = min(int(cowsX.size() - 1), i + 1);
        areaB = (cowsX[cowsX.size() - 1].first - cowsX[next].first)*(backPrefSumX[next].second - backPrefSumX[next].first);
        minArea = min(minArea, areaA + areaB);
        output << areaA + areaB << endl;

    }


    int maxXSoFar = -1;
    int minXSoFar = 1000000001;
    for(int i = 0; i < cowsY.size() - 1; i++){
        maxXSoFar = max(maxXSoFar, cowsY[i].second);
        minXSoFar = min(minXSoFar, cowsY[i].second);
         if(cowsY[i].first == cowsY[i+1].first){
            continue;
        }
        int areaA, areaB;
        areaA = (cowsY[i].first - cowsY[0].first)*(maxXSoFar - minXSoFar);
        int next = min(int(cowsY.size() - 1), i + 1);
        if(cowsY[i].first == cowsY[i + 1].first){
            next = min(int(cowsY.size() - 1), i + 2);
        }
        areaB = (cowsY[cowsY.size() - 1].first - cowsY[next].first)*(backPrefSumY[next].second - backPrefSumY[next].first);
        minArea = min(minArea, areaA + areaB);
        output << areaA + areaB << " " << cowsY[i].first << " | " <<maxXSoFar << " " << minXSoFar << " | " << backPrefSumY[next].second << " " << backPrefSumY[next].first << endl;
    }


    cout << endl << overallArea;

    output << overallArea - minArea;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << backPrefSumY[i] << " ";
    // }

    input.close();
    output.close();

    
}