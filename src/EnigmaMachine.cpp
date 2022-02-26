/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : EnigmaMachine.cpp
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Contains the implementation of the EnigmaMachine class defined in EnigmaMachine.h
 * Remarks  : Debug preprocessor comment available as required in the project sheet.
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */
#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine(const Rotor &lRotor, const Rotor &mRotor, const Rotor &rRotor, const Reflector &reflector)
        : rotors{rRotor, mRotor, lRotor}, reflector(reflector) {
#if ENABLE_DEBUG
    std::cout << *this;
#endif
}

void EnigmaMachine::setRotor(ROTOR_POSITIONS position, Rotor &rotor) {
    this->rotors[static_cast<size_t>(position)] = rotor;
}

void EnigmaMachine::setReflector(Reflector &reflector) {
    this->reflector = reflector;
}

void EnigmaMachine::setRotorPosition(ROTOR_POSITIONS rotor, char position) {
    this->rotors[static_cast<size_t>(rotor)].setPosition(position);
}

void EnigmaMachine::passThrough(char &letter) {

    //Rotating the rotor(s)
    if (this->rotors[0].rotate()) {
        if (this->rotors[1].rotate()) {
            this->rotors[2].rotate();
        }
    }

#if ENABLE_DEBUG
    char previous = letter;
#endif

    letter = this->rotors[0].passThroughRTL(letter); //No rotor before

#if ENABLE_DEBUG
    std::cout << this->rotors[0];
    std::cout << "Result       : " << letter << " <= " << previous << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->rotors[1].passThroughRTL(letter, this->rotors[0].getRotation());

#if ENABLE_DEBUG
    std::cout << this->rotors[1];
    std::cout << "Result       : " << letter << " <= " << previous << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->rotors[2].passThroughRTL(letter, this->rotors[1].getRotation());

#if ENABLE_DEBUG
    std::cout << this->rotors[2];
    std::cout << "Result       : " << letter << " <= " << previous << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->reflector.passThrough(letter, this->rotors[2].getRotation());

#if ENABLE_DEBUG
    std::cout << this->reflector;
    std::cout << "Result       : " << previous << " => " << letter << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->rotors[2].passThroughLTR(letter);    //No rotor before

#if ENABLE_DEBUG
    std::cout << this->rotors[2];
    std::cout << "Result       : " << previous << " => " << letter << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->rotors[1].passThroughLTR(letter, this->rotors[2].getRotation());

#if ENABLE_DEBUG
    std::cout << this->rotors[1];
    std::cout << "Result       : " << previous << " => " << letter << std::endl << std::endl;
    previous = letter;
#endif

    letter = this->rotors[0].passThroughLTR(letter, this->rotors[1].getRotation());

#if ENABLE_DEBUG
    std::cout << this->rotors[0];
    std::cout << "Result       : " << previous << " => " << letter << std::endl << std::endl;
    previous = letter;
#endif

    // Finding the "real letter index" (taking the previous rotor rotation into account)
    size_t realLetterIndex = ((letter - 'A') - this->rotors[0].getRotation() +26) % 26;

    letter = (char)('A' + realLetterIndex);
}

void EnigmaMachine::passThrough(std::string &phrase) {

    for (char &letter : phrase) {
        this->passThrough(letter);
    }

}

std::ostream &operator<<(std::ostream &os, const EnigmaMachine &enigmaMachine) {
    std::cout << "Enigma machine configuration:"    << std::endl;
    std::cout << "Left rotor:"                      << std::endl;
    std::cout << enigmaMachine.rotors[2]            << std::endl;
    std::cout << "Middle rotor:"                    << std::endl;
    std::cout << enigmaMachine.rotors[1]            << std::endl;
    std::cout << "Right rotor:"                     << std::endl;
    std::cout << enigmaMachine.rotors[0]            << std::endl;
    std::cout << "Reflector:"                       << std::endl;
    std::cout << enigmaMachine.reflector            << std::endl;
}
