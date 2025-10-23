#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include "Exceptions.hpp"

class ModDivNullException : public AVMExceptions
{
    public :
        ModDivNullException();
        ~ModDivNullException();
};

class PopEmptyStackException : public AVMExceptions
{
    public :
        PopEmptyStackException();
        ~PopEmptyStackException();
};

class NoExitException : public AVMExceptions
{
    public :
        NoExitException();
        ~NoExitException();
};

class OverflowException : public AVMExceptions
{
    public :
        OverflowException();
        ~OverflowException();
};

class UnderflowException : public AVMExceptions
{
    public :
        UnderflowException();
        ~UnderflowException();
};

class AssertFalseException : public AVMExceptions
{
    public :
        AssertFalseException();
        ~AssertFalseException();
};

class NotAnInstructionException : public AVMExceptions
{
    public :
        NotAnInstructionException();
        ~NotAnInstructionException();
    // • An instruction is unknown not in ENUM push, pop, dump...
};

class LexicalErrorException : public AVMExceptions
{
    public :
        LexicalErrorException();
        ~LexicalErrorException();
    // • The assembly program includes one or several lexical errors or syntactic errors.
    // trop d'arguments, mauvais formatage
};

class ArithmeticException : public AVMExceptions
{
    public :
        ArithmeticException();
        ~ArithmeticException();
    // • The stack is composed of strictly less that two values when an arithmetic instruction
    // is executed.
    // Si il y a une operation à faire et qu'il n'y a qu'un chiffre ou aucun alors c'est une erreur
};

class CantOpenFile : public AVMExceptions
{
    public :
        CantOpenFile();
        ~CantOpenFile();
};

class TooManyParams : public AVMExceptions
{
    public :
        TooManyParams();
        ~TooManyParams();
};

#endif