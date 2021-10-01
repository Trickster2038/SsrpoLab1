#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;

struct Candidate {
    enum Fraction {
        FRACTION_EDRO,
        FRACTION_YABLOKO,
        FRACTION_LDPR,
        FRACTION_NOVYE_LUDI,
        FRACTION_KPRF
    };

    string fio;
    uint age;
    float income;
    Fraction fraction;
    uint voices;
};

int main(){
    list<Candidate> candidates_list
    {
        Candidate{"Zhirinovsky V.V.", 75, 2000000.156, 
            Candidate::FRACTION_LDPR, 42345},
        Candidate{"Kaz M.E", 36, 1000000.3, 
            Candidate::FRACTION_YABLOKO, 12043},
        Candidate{"Zyganov G.A", 77, 1500000.3452,
            Candidate::FRACTION_KPRF, 24021}
    };



    for(const auto o: candidates_list){
        cout << o.fio 
        << "\nage: " << o.age 
        << "\nincome: " << setprecision(9) << o.income 
        << "\nfraction: " << o.fraction 
        << "\nvoices:" << o.voices << endl << endl;
    }

    return 0;
}