#include "airport_record.h"

#include <string>
#include <utility>
#include <tuple>

AirportRecord::AirportRecord(std::string cd, std::string nm, std::string ct, std::string ctry,
        int ltd, int ltm, int lts, std::string ltdir, int lnd, int lnm, int lns,
        std::string lndir, int alt) {
    code = std::move(cd);
    name = std::move(nm);
    city = std::move(ct);
    country = std::move(ctry);
    latitude_degrees = ltd;
    latitude_minutes = ltm;
    latitude_seconds = lts;
    latitude_direction = std::move(ltdir);
    longitude_degrees = lnd;
    longitude_minutes = lnm;
    longitude_seconds = lns;
    longitude_direction = std::move(lndir);
    altitude = alt;
}

bool AirportRecord::operator==(const AirportRecord &rhs) const {
    return altitude == rhs.altitude;
}

bool AirportRecord::operator!=(const AirportRecord &rhs) const {
    return !(rhs == *this);
}

bool AirportRecord::operator<(const AirportRecord &rhs) const {
    return altitude < rhs.altitude;
}

bool AirportRecord::operator>(const AirportRecord &rhs) const {
    return rhs < *this;
}

bool AirportRecord::operator<=(const AirportRecord &rhs) const {
    return !(rhs < *this);
}

bool AirportRecord::operator>=(const AirportRecord &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, AirportRecord const &rec) {
    os << rec.code << " " 
        << rec.name << " " 
        << rec.city << " " 
        << rec.country << " " 
        << rec.latitude_degrees << " "
        << rec.latitude_minutes << " "
        << rec.latitude_seconds << " "
        << rec.latitude_direction << " "
        << rec.longitude_degrees << " "
        << rec.longitude_minutes << " "
        << rec.longitude_seconds << " "
        << rec.longitude_direction << " "
        << rec.altitude;
    
    return os;
}
