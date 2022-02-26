/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : Reflector.cpp
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Contains the implementation of the Reflector class defined in Reflector.h
 * Remarks  : None
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#include "Reflector.h"

Reflector::Reflector(char id, const std::string &wiring) : id(id), wiring(wiring) {}

char Reflector::passThrough(char letter, size_t previousRotorRotation) const {

    // Finding the "real letter index" (taking the previous rotor rotation into account)
    size_t realLetterIndex = ((letter - 'A')- previousRotorRotation + 26) % 26;

    return this->wiring[realLetterIndex];
}

Reflector &Reflector::operator=(const Reflector &reflector) {
    (char &) this->id = reflector.id;
    (std::string &) this->wiring = reflector.wiring;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Reflector &reflector) {
    os  << "reflector    : UKW-"    << reflector.id                     << std::endl
        << "entry        : "        << "ABCDEFGHIJKLMNOPQRSTUVWXYZ"     << std::endl
        << "wiring       : "        << reflector.wiring                 << std::endl;
    return os;
}