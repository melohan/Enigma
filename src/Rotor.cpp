/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : Rotor.cpp
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Contains the implementation of the Rotor class defined in Rotor.h
 * Remarks  : There are two approaches to the concept of rotating the rotor:
 *            - Rotating the ring (wiring) such as you imitate the real rotation of the rotor, this approach is more
 *              realistic but more resource consuming
 *            - Keeping the ring (wiring) static and using a rotation variable as a "pointer" to your "first position"
 *              as if you were rotating the ring. This approach is less realistic but much more resource efficient.
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#include "Rotor.h"

Rotor::Rotor(short id, const std::string &wiring, char notch) : id(id), wiring(wiring), rotation(0), notch(notch - 'A') {}

bool Rotor::rotate() {

    bool rotateNextRotor = false;

    if (this->rotation++ == this->notch)
        rotateNextRotor = true;

    this->rotation %= 26;

    return rotateNextRotor;
}

void Rotor::setPosition(char position) {
    this->rotation = (size_t) (position - 'A');
}

size_t Rotor::getRotation() {
    return this->rotation;
}

char Rotor::passThroughRTL(char letter, size_t previousRotorRotation) const {

    // Finding the "real letter index" (taking the previous rotor rotation into account)
    size_t realLetterIndex = ((letter - 'A') + this->rotation - previousRotorRotation + 26)%26;

    return this->wiring[realLetterIndex];
}

char Rotor::passThroughLTR(char letter, size_t previousRotorRotation) const {

    // Finding the "real letter index" (taking the previous rotor rotation into account)
    size_t realLetterIndex = ((letter - 'A') + this->rotation - previousRotorRotation + 26) % 26;

    return char('A' + this->wiring.find((char)('A' + realLetterIndex)));
}

Rotor &Rotor::operator=(const Rotor &rotor) {
    (short &) this->id = rotor.id;
    (std::string &) this->wiring = rotor.wiring;
    (size_t &) this->notch = rotor.notch;
    (size_t &) this->rotation = rotor.rotation;
}

std::ostream &operator<<(std::ostream &os, const Rotor &rotor) {
    os << "rotor id     : " << rotor.id << std::endl
       << "entry        : " << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << std::endl
       << "wiring       : " << rotor.wiring << std::endl
       << "position     : " << (char) ('A' + rotor.rotation) << std::endl
       << "notch        : " << (char) ('A' + rotor.notch) << std::endl;
    return os;
}