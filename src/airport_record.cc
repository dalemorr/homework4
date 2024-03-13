#include "airport_record.h"

#include <string>

AirportRecord::AirportRecord(std::string cd, std::string nm, std::string ct, std::string ctry,
        int ltd, int ltm, int lts, std::string ltdir, int lnd, int lnm, int lns,
        std::string lndir, int alt) {
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

bool AirportRecord::equals(const AirportRecord &rhs) {
    return this->code == rhs.code
        && this->name == rhs.name
        && this->city == rhs.city
        && this->country == rhs.country
        && this->latitudeDegrees == rhs.latitudeDegrees
        && this->latitudeMinutes == rhs.latitudeMinutes
        && this->latitudeSeconds == rhs.latitudeSeconds
        && this->latitudeDirection == rhs.latitudeDirection
        && this->longitudeDegrees == rhs.longitudeDegrees
        && this->longitudeMinutes == rhs.longitudeMinutes
        && this->longitudeSeconds == rhs.longitudeSeconds
        && this->longitudeDirection == rhs.longitudeDirection
        && this->altitude == rhs.altitude;
}

bool AirportRecord::operator==(const AirportRecord &rhs) {
    return this->altitude == rhs.altitude;
}

inline bool AirportRecord::operator>(const AirportRecord &rhs) {
    return this->altitude > rhs.altitude;
}

inline bool AirportRecord::operator<(const AirportRecord &rhs) {
    return this->altitude < rhs.altitude;
}

std::ostream& operator<<(std::ostream& os, const AirportRecord rec) {
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
