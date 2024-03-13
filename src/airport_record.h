#pragma once

#include <iostream>
#include <string>

using namespace std;

typedef tuple<string, string, string, string, int, int, int, string, 
    int, int, int, string, int> ARTuple;

class AirportRecord {
    public:
        string code;
        string name;
        string city;
        string country;
        int latitudeDegrees;
        int latitudeMinutes;
        int latitudeSeconds;
        string latitudeDirection;
        int longitudeDegrees;
        int longitudeMinutes;
        int longitudeSeconds;
        string longitudeDirection;
        int altitude;

        AirportRecord(string cd, string nm, string ct, string ctry, int ltd, int ltm, int lts, 
            string ltdir, int lnd, int lnm, int lns, string lndir, int alt);

        friend ostream& operator<<(ostream& os, const AirportRecord rec);

        friend inline bool operator==(const AirportRecord &lhs, const AirportRecord &rhs);

        friend inline bool operator>(const AirportRecord &lhs, const AirportRecord &rhs);

        friend inline bool operator<(const AirportRecord &lhs, const AirportRecord &rhs);
};
