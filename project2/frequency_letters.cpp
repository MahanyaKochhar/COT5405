#include "frequency_letters.h"
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

map<char,double> readLetterFrequency()
{
    ifstream inputCsv("./frequencies.csv");
    string line;
    getline(inputCsv, line);
    map<char,double> frequencyMap;
    while (getline(inputCsv, line))
    {
        stringstream ss(line);
        string letterStr, freqStr;

        if (getline(ss, letterStr, ',') &&
            getline(ss, freqStr, ',')) {

            char letter = letterStr[0];
            double frequency = stod(freqStr);
            frequencyMap[letter] = frequency;
        }
    }
    inputCsv.close();
    return frequencyMap;
}