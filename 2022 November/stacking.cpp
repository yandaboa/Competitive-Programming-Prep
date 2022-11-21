#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arrSize, numInstructions;
vector<int> prefixSumHeight;
vector<int> minInstruct, maxInstruct;
map<int, int> heightOccs;

int main() {
    // ifstream input("stacking.in");
    // ofstream output("stacking.out");

    cin >> arrSize >> numInstructions;

    minInstruct.resize(arrSize + 1, 0);
    maxInstruct.resize(arrSize + 1, 0);
    prefixSumHeight.resize(arrSize + 1);
    for(int i = 0; i < numInstructions; i++){
        int min, max;
        cin >> min >> max;
        minInstruct[min]++;
        maxInstruct[max]++; //remember to subtract from prefix sum only after the max index - max is the last container where there is still a box from that sequence
    }

    prefixSumHeight[0] = 0;
    for(int i = 1 ; i < prefixSumHeight.size(); i++){
        prefixSumHeight[i] = prefixSumHeight[i - 1] + minInstruct[i] - maxInstruct[i - 1];
        if(heightOccs.count(prefixSumHeight[i]) ==0){
            heightOccs[prefixSumHeight[i]] = 1;
        } else {
            heightOccs[prefixSumHeight[i]]++;
        }
    }

    map<int, int>::iterator itr;
    // cout << "\nThe map gquiz1 is : \n";
    // cout << "\tKEY\tELEMENT\n";
    // for (itr = heightOccs.begin(); itr != heightOccs.end(); ++itr) {
    //     cout << '\t' << itr->first << '\t' << itr->second
    //          << '\n';
    // }

    int sum = 0;
    for(int i = 0; i <= numInstructions; i++){
        if(heightOccs.count(i) > 0){
            sum += heightOccs[i];
        }
        if(sum > arrSize/2){
            cout << i;
            break;
        }
    }
    // output.close();
    // input.close();
}