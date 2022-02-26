/**
 * =====================================================================================================================
 * Lab      : Labo 3 - Enigma Machine
 * Date     : 28.03.2020
 *
 * File     : Labo03_DaRochaCarvalho_Uhan_Boegli_main.cpp
 * Authors  : Da Rocha Carvalho Bruno, Uhan Mélodie, Boegli Noah
 * Purpose  : Tests the implementation of the Enigma Machine
 * Remarks  : An example of the following operations are available
 *              - Rotors & Reflector instantiations
 *              - Enigma machine instantiation with 3 rotors & 1 reflector
 *              - Changing the rotor & reflector in the Enigma Machine
 *              - Coding and decoding of a char
 *              - Decoding and coding of a string
 *            Debug logs can be turned on in EnigmaMachine.h
 *
 * Compiler : MinGW-g++ 6.3.0-1
 * Standard : C++11
 * =====================================================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <string>

// Useful macros
#define CLEAR_BUFFER while(getchar() != '\n')
#define PROGRAM_END cout << "Press enter to quit..." << endl; CLEAR_BUFFER

#include "EnigmaMachine.h"

using namespace std;

int main() {

    //========================================= Initializing all components ==========================================//
    Rotor r1 = Rotor(1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor r2 = Rotor(2, "AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor r3 = Rotor(3, "BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
    Rotor r4 = Rotor(4, "ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
    Rotor r5 = Rotor(5, "VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');


    Reflector ukw_a = Reflector('A', "EJMZALYXVBWFCRQUONTSPIKHGD");
    Reflector ukw_b = Reflector('B', "YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Reflector ukw_c = Reflector('C', "FVPJIAOYEDRZXWGCTKUQSBNMHL");

    //Initializing an enigma machine with some components
    EnigmaMachine em(r3, r5, r2, ukw_c);

    //============================================= Changing components ==============================================//

    //Changing the rotors
    em.setRotor(ROTOR_POSITIONS::LEFT, r3);
    em.setRotor(ROTOR_POSITIONS::MIDDLE, r2);
    em.setRotor(ROTOR_POSITIONS::RIGHT, r1);

    //Changing the reflector
    em.setReflector(ukw_b);
    //================================================================================================================//



    //===================================== Test 1: Encrypt then decrypt a char ======================================//

    //Rotating the rotors
    em.setRotorPosition(ROTOR_POSITIONS::LEFT, 'A');
    em.setRotorPosition(ROTOR_POSITIONS::MIDDLE, 'A');
    em.setRotorPosition(ROTOR_POSITIONS::RIGHT, 'A');

    cout << "==================================================================================" << endl
         << "Character encryption & decryption example:" << endl
         << endl;


    char c = 'B';
    cout << c << " => [Enigma Machine] => ";
    em.passThrough(c);
    cout << c << endl;

    // Again rotating the rotors to the initial position used to encrypt the char
    em.setRotorPosition(ROTOR_POSITIONS::LEFT, 'A');
    em.setRotorPosition(ROTOR_POSITIONS::MIDDLE, 'A');
    em.setRotorPosition(ROTOR_POSITIONS::RIGHT, 'A');

    cout << c << " => [Enigma Machine] => ";
    em.passThrough(c);
    cout << c << endl;
    //================================================================================================================//

    cout << "==================================================================================" << endl;

    //=================================== Test 2: Decrypt a super secret message =====================================//

    //Setting the correct rotors
    em.setRotor(ROTOR_POSITIONS::LEFT, r2);
    em.setRotor(ROTOR_POSITIONS::MIDDLE, r4);
    em.setRotor(ROTOR_POSITIONS::RIGHT, r1);

    // Rotating the rotors to the instructed position
    em.setRotorPosition(ROTOR_POSITIONS::LEFT, 'C');
    em.setRotorPosition(ROTOR_POSITIONS::MIDDLE, 'K');
    em.setRotorPosition(ROTOR_POSITIONS::RIGHT, 'M');

    cout << "String encryption & decryption example:" << endl
         << endl;

    string message = "CLZJVMUOAQAGFQJSMOYQLPLCTN";
    cout << message << " => [Enigma Machine] => ";
    em.passThrough(message);
    cout << message << endl;


    // Again rotating the rotors to the instructed position to decrypt the message
    em.setRotorPosition(ROTOR_POSITIONS::LEFT, 'C');
    em.setRotorPosition(ROTOR_POSITIONS::MIDDLE, 'K');
    em.setRotorPosition(ROTOR_POSITIONS::RIGHT, 'M');

    cout << message << " => [Enigma Machine] => ";
    em.passThrough(message);
    cout << message << endl
         << "==================================================================================" << endl;
    //================================================================================================================//

    PROGRAM_END;
    return EXIT_SUCCESS;
}