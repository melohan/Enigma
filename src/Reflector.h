/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : Reflector.h
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Defines the prototype of the Reflector class
 * Remarks  : The ID and wiring are constant properties. For assignation when changing the reflector in the
 *            EnigmaMachine object, the const is casted to non-const&, see Reflector.cpp for that.
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#ifndef LAB_03_REFLECTOR_H
#define LAB_03_REFLECTOR_H

#include <string>
#include <iostream>


class Reflector {

    /**
     * Output stream operator overload.
     * @param os The output stream
     * @param reflector The reflector to output
     * @return The output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Reflector &reflector);

private:
    const char id;

    const std::string wiring;

public:

    /**
     * Constructor for the Reflector object.
     * @param id The ID of the reflector (A, B or C)
     * @param wiring The wiring of the reflector
     */
    explicit Reflector(char id, const std::string &wiring);

    /**
     * Passes a letter through the reflector and returns the matching letter.
     * @param letter The letter
     * @return The matching letter
     */
    char passThrough(char letter, size_t previousRotorRotation) const;

    /**
     * Copy assignment operator overload.
     * @param reflector The reflector to copy
     * @return A reference to the new reflector
     */
    Reflector &operator=(const Reflector &reflector);
};

#endif //LAB_03_REFLECTOR_H