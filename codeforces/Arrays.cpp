#include <iostream>
using namespace std;

enum StudentNames{
        Kyle,
        Nate,
        Adam,
        Rebecca,
        Audrey
};

namespace gen {
    enum Animal {
        chicken, dog, cat, elephant, duck, snake, numAnimals
    };
}

int main(){
    int studentScores[10];
    studentScores[0] = 1;
    studentScores[1] = 1;
    // cout << studentScores[0] << "\n" << studentScores[1] << endl;
    for(int i = 2; i < sizeof(studentScores)/sizeof(studentScores[0]); i++){
        studentScores[i] = studentScores[i - 1] + studentScores[i - 2];
        // cout << studentScores[i] << " " << i << endl;
    }

    struct plane {
        int year;
        double height;
        int modelNum;
    };
    plane boeing747;
    boeing747.year = 1888;
    boeing747.height = 2.4;
    boeing747.modelNum =747;
    cout << boeing747.year << " " << boeing747.height << " " << boeing747.modelNum << endl;
    
    plane locket2;
    locket2.year = 1212;
    locket2.height = 2.5;
    locket2.modelNum = 2;
    cout << locket2.year << " " << locket2.height << " " << locket2.modelNum << endl;

    cout << Kyle << " " << Audrey << endl;


    int highTemp[365] = {};
    cout << highTemp[0] << endl;

    int animalLegs[gen::numAnimals] = {2, 4, 4, 4, 2, 0};
    cout << "an elephant has " << animalLegs[gen::elephant] << " legs" << endl;
    return 0;
}
