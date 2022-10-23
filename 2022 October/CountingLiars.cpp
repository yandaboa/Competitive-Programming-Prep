#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numCows = 0;
    vector<int> lessThans;
    vector<int> moreThans;
    int max = 0;
    cin >> numCows;
    for(int i = 0; i < numCows; i++){
        char LorG;
        int value;
        cin >> LorG;
        cin >> value;
        if(LorG == 'L'){
            lessThans.push_back(value);
        } else {
            moreThans.push_back(value);
        }
    }

    for(int i = 0; i < lessThans.size(); i++){
        int temp = 0;
        for(int j = 0; j < lessThans.size(); j++){
            if(lessThans.at(i) <= lessThans.at(j)){
                temp++;
            }
        }

        for(int j = 0; j < moreThans.size(); j++){
            if(moreThans.at(j) <= lessThans.at(i)){
                temp++;
            }
        }
        max = std::max(temp, max);
    }

    for(int i = 0; i < moreThans.size(); i++){
        int temp = 0;
        for(int j = 0; j < moreThans.size(); j++){
            if(moreThans.at(i) >= moreThans.at(j)){
                temp++;
            }
        }

        for(int j = 0; j < lessThans.size(); j++){
            if(lessThans.at(j) >= moreThans.at(i)){
                temp++;
            }
        }
        max = std::max(temp, max);
    }

    cout << numCows - max;
    return 0;
}