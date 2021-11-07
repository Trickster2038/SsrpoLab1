#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <map>

using namespace std;

enum Fraction
{
    FRACTION_EDRO,
    FRACTION_YABLOKO,
    FRACTION_LDPR,
    FRACTION_NOVYE_LUDI,
    FRACTION_KPRF
};

struct Candidate
{
    string fio;
    uint age;
    float income;
    Fraction fraction;
    uint voices;
};

class Converter
{
private:
    static inline map<Fraction, string> fraction_to_string = {{FRACTION_EDRO, "EDRO"},
                                                              {FRACTION_YABLOKO, "YABLOKO"},
                                                              {FRACTION_LDPR, "LDPR"},
                                                              {FRACTION_NOVYE_LUDI, "NOVIE LUDI"},
                                                              {FRACTION_KPRF, "KPRF"}};

public:
    static const string &toString(Fraction fraction_code)
    {
        return fraction_to_string.find(fraction_code)->second;
    }
};

int main()
{
    list<Candidate> candidates_list{
        Candidate{"Zhirinovsky V.V.", 75, 2000000.156,
                  FRACTION_LDPR, 42345},
        Candidate{"Kaz M.E", 36, 1000000.3,
                  FRACTION_YABLOKO, 12043},
        Candidate{"Zyganov G.A", 77, 1500000.3452,
                  FRACTION_KPRF, 24021}};

    for (const auto o : candidates_list)
    {
        cout << o.fio
             << "\nage: " << o.age
             << "\nincome: " << setprecision(9) << o.income
             << "\nfraction: " << Converter::toString(o.fraction)
             << "\nvoices:" << o.voices << endl
             << endl;
    }

    return 0;
}