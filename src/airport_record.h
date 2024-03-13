#pragma once

#include <iostream>
#include <string>

typedef struct AirportRecord {
public:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latitude_degrees;
    int latitude_minutes;
    int latitude_seconds;
    std::string latitude_direction;
    int longitude_degrees;
    int longitude_minutes;
    int longitude_seconds;
    std::string longitude_direction;
    int altitude;

    AirportRecord(std::string cd, std::string nm, std::string ct, std::string ctry, int ltd,
        int ltm, int lts, std::string ltdir, int lnd, int lnm, int lns, std::string lndir,
        int alt);

    friend std::ostream &operator<<(std::ostream &os, const AirportRecord& rec);

    bool operator==(const AirportRecord &rhs) const;

    bool operator!=(const AirportRecord &rhs) const;

    bool operator<(const AirportRecord &rhs) const;

    bool operator>(const AirportRecord &rhs) const;

    bool operator<=(const AirportRecord &rhs) const;

    bool operator>=(const AirportRecord &rhs) const;
} AirportRecord;
