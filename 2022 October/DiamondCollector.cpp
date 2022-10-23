// reading a text file
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main () {
  string line;
  ifstream fin("diamond.in");
  ofstream fout("diamond.out");
  int numDiamond, diff;
  fin >> numDiamond >> diff;
  vector<int> diamonds;
  for(int i = 0; i < numDiamond; i++){
    int temp;
    fin >> temp;
    diamonds.push_back(temp);
  }
  int res = 0;
  for(int i = 0; i < diamonds.size(); i++){
    int counter = 0;
    for(int j = 0; j < diamonds.size(); j++){
        if(diamonds[j] <= diamonds[i] + diff && diamonds[j] >= diamonds[i]){
            counter++;
        }
    }
    res = std::max(res, counter);
  }
  fout << res;
  return 0;
}