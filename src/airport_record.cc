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

inline bool operator==(const AirportRecord &lhs, const AirportRecord &rhs) {
    return lhs.code == rhs.code
        && lhs.name == rhs.name
        && lhs.city == rhs.city
        && lhs.country == rhs.country
        && lhs.latitudeDegrees == rhs.latitudeDegrees
        && lhs.latitudeMinutes == rhs.latitudeMinutes
        && lhs.latitudeSeconds == rhs.latitudeSeconds
        && lhs.latitudeDirection == rhs.latitudeDirection
        && lhs.longitudeDegrees == rhs.longitudeDegrees
        && lhs.longitudeMinutes == rhs.longitudeMinutes
        && lhs.longitudeSeconds == rhs.longitudeSeconds
        && lhs.longitudeDirection == rhs.longitudeDirection
        && lhs.altitude == rhs.altitude;
}

inline bool operator>(const AirportRecord &lhs, const AirportRecord &rhs) {
    return lhs.altitude > rhs.altitude;
}

inline bool operator<(const AirportRecord &lhs, const AirportRecord &rhs) {
    return lhs.altitude < rhs.altitude;
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
