#pragma once

#include <iostream>
#include <string>

class AirportRecord {
    public:
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

        AirportRecord(std::string cd, std::string nm, std::string ct, std::string ctry, int ltd,
            int ltm, int lts, std::string ltdir, int lnd, int lnm, int lns, std::string lndir,
            int alt);

        friend std::ostream &operator<<(std::ostream &os, const AirportRecord rec);

        bool equals(const AirportRecord &rhs); // Compares all fields

        bool operator==(const AirportRecord &rhs); // Compares only altitudes

        inline bool operator<(const AirportRecord &rhs);

        inline bool operator>(const AirportRecord &rhs);

        inline bool operator<=(const AirportRecord &rhs);

        inline bool operator>=(const AirportRecord &rhs);
};
