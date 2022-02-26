/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : EnigmaMachine.h
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Defines the prototype of the EnigmaMachine class
 * Remarks  : Strings & chars to convert are passed as reference. An overload exists for string and char.
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#ifndef LAB_03_ENIGMAMACHINE_H
#define LAB_03_ENIGMAMACHINE_H

// Whether or not to show the debug information
// Note: Enabling this will mess up the presentation of the main.cpp, use separately!
#define ENABLE_DEBUG false

#include "Rotor.h"
#include "Reflector.h"

#include <string>

// Be cautious with the order of the elements in the enum. The order in the enum must be the order in which rotors are
// "used". First the right rotor, then the middle rotor, then the left rotor, and back in the inverse order.
enum class ROTOR_POSITIONS {RIGHT, MIDDLE, LEFT};

class EnigmaMachine {

    /**
     * Output stream operator overload.
     * @param os The output stream
     * @param reflector The reflector to output
     * @return The output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const EnigmaMachine &enigmaMachine);

private:
    Rotor rotors[3];

    Reflector reflector;

public:

    /**
     * Constructor for the EnigmaMachine object.
     * @param lRotor The left rotor
     * @param mRotor The middle rotor
     * @param rRotor The right rotor
     * @param reflector The reflector
     */
    EnigmaMachine(const Rotor& lRotor, const Rotor& mRotor, const Rotor& rRotor,const Reflector& reflector);

    /**
     * Sets a rotor to a position.
     * @param position The position
     * @param rotor The rotor
     */
    void setRotor(ROTOR_POSITIONS position, Rotor& rotor);

    /**
     * Sets the reflector.
     * @param reflector The reflector
     */
    void setReflector(Reflector& reflector);

    /**
     * Sets the position of a rotor.
     * @param rotor The rotor (its position in the machine)
     * @param position The position to set it to
     */
    void setRotorPosition(ROTOR_POSITIONS rotor, char position);

    /**
     * Passes a letter through the machine (the equivalent of typing a letter on the machine).
     * @param letter The letter
     */
    void passThrough(char &letter);

    /**
     * Passes a complete string, letter by letter, through the machine.
     * @param phrase
     */
    void passThrough(std::string& phrase);
};

#endif //LAB_03_ENIGMAMACHINE_H