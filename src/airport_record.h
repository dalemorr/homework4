#ifndef AIRPORT_RECORD_H
#define AIRPORT_RECORD_H

#include <string>

typedef struct AirportRecord {
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latitudeDegrees;
    int latitudeMinutes;
    int latitudeSeconds;
    std::string latitudeDirection;
    int longitudeDegrees;
    int longitudeMinutes;
    int longitudeSeconds;
    std::string longitudeDirection;
    int altitude;
} AirportRecord;

#endif // AIRPORT_RECORD_H
