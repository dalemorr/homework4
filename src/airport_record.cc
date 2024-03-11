#include "airport_record.h"

#include <string>

using namespace std;

AirportRecord::AirportRecord(string cd, string nm, string ct, string ctry, int ltd, int ltm, 
        int lts, string ltdir, int lnd, int lnm, int lns, string lndir, int alt) {
    code = cd;
    name = nm;
    city = ct;
    country = ctry;
    latitudeDegrees = ltd;
    latitudeMinutes = ltm;
    latitudeSeconds = lts;
    latitudeDirection = ltdir;
    longitudeDegrees = lnd;
    longitudeMinutes = lnm;
    longitudeSeconds = lns;
    longitudeDirection = lndir;
    altitude = alt;
}

ostream& operator<<(ostream& os, const AirportRecord rec) {
    os << rec.code << " " 
        << rec.name << " " 
        << rec.city << " "
        << rec.country << " "
        << rec.latitudeDegrees << " "
        << rec.latitudeMinutes << " " 
        << rec.latitudeSeconds << " " 
        << rec.latitudeDirection << " " 
        << rec.longitudeDegrees << " " 
        << rec.longitudeMinutes << " " 
        << rec.longitudeSeconds << " " 
        << rec.longitudeDirection << " " 
        << rec.altitude;
    
    return os;
}
