//
// Created by YandaBao on 11/17/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "GrassPlanting.in"
//#include "GrassPlanting.out"

using namespace std;

string currLine;
int numCows;
vector<int> adjs;
int a, b;
int maxSoFar = 0;

int main(){
    ifstream inputFile("planting.in");
    ofstream outputFile("planting.out");

    inputFile >> numCows;
    adjs.resize(numCows);
    for(int i = 0; i < numCows - 1; i++){
        inputFile >> a >> b;
        adjs[a - 1]++;
        adjs[b - 1]++;
        maxSoFar = max(max(maxSoFar, adjs[a - 1]), max(maxSoFar, adjs[b - 1]));
    }

    outputFile << maxSoFar + 1 << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}