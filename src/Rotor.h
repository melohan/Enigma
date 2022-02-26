/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : Rotor.h
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Defines the prototype of the Rotor class
 * Remarks  : The ID, wiring and notch are constant properties. For assignation when switching the rotors in the
 *            EnigmaMachine object, the const is casted to non-const&, see Rotor.cpp for that.
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#ifndef LAB_03_ROTOR_H
#define LAB_03_ROTOR_H

#include <string>
#include <iostream>

class Rotor {

    /**
     * Output stream operator overload.
     * @param os The output stream
     * @param rotor The rotor to output
     * @return The output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Rotor &rotor);

private:
    const short id;

    const std::string wiring;

    const size_t notch;

    size_t rotation;

public:

    /**
     * Constructor for the Rotor object.
     * @param id The rotor id (1,2,3,4 ou 5)
     * @param wiring The wiring of the rotor
     * @param notch The notch of the rotor
     */
    explicit Rotor(short id, const std::string &wiring, char notch);

    /**
     * Rotates the rotor by one step.
     * @return A boolean indicating whether or not the notch was passed
     */
    bool rotate();

    /**
     * Sets the position of the rotor.
     * @param position The position
     */
    void setPosition(char position);

    /**
     * Returns the rotation of the rotor
     * @return
     */
    size_t getRotation();

    /**
     * Passes a letter through the rotor and returns the matching letter.
     * Direction: Keyboard => Reflector (right to left in terms of rotors).
     * @param letter The letter
     * @param previousRotorRotation The previous rotor rotation (0 by default if no rotor in previous position)
     * @return The matching letter
     */
    char passThroughRTL(char letter, size_t previousRotorRotation = 0) const;

    /**
     * Passes a letter through the rotor and returns the matching letter.
     * Direction: Reflector => Display (left to right in terms of rotors).
     * @param letter The letter
     * @param previousRotorRotation The previous rotor rotation (0 by default if no rotor in previous position)
     * @return The matching letter
     */
    char passThroughLTR(char letter, size_t previousRotorRotation = 0) const;

    /**
     * Copy assignment operator overload.
     * @param rotor The rotor to copy
     * @return A reference to the new rotor
     */
    Rotor &operator=(const Rotor &rotor);
};

#endif //LAB_03_ROTOR_H