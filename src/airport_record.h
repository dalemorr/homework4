#ifndef AIRPORT_RECORD_H
#define AIRPORT_RECORD_H

#include <string>

using namespace std;

typedef struct AirportRecord {
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
} AirportRecord;

#endif // AIRPORT_RECORD_H
