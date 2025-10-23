#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include "Exceptions.hpp"

class ModDivNullException : public AVMExceptions
{
    public :
        ModDivNullException();
};

class PopEmptyStackException : public AVMExceptions
{
    public :
        PopEmptyStackException();
};

class NoExitException : public AVMExceptions
{
    public :
        NoExitException();
};

class OverflowException : public AVMExceptions
{
    public :
        OverflowException();
};

class UnderflowException : public AVMExceptions
{
    public :
        UnderflowException();
};

class AssertFalseException : public AVMExceptions
{
    public :
        AssertFalseException();
};

class NotAnInstructionException : public AVMExceptions
{
    public :
        NotAnInstructionException();
    // • An instruction is unknown not in ENUM push, pop, dump...
};

class LexicalErrorException : public AVMExceptions
{
    public :
        LexicalErrorException();
    // • The assembly program includes one or several lexical errors or syntactic errors.
    // trop d'arguments, mauvais formatage
};

class ArithmeticException : public AVMExceptions
{
    public :
        ArithmeticException();
    // • The stack is composed of strictly less that two values when an arithmetic instruction
    // is executed.
    // Si il y a une operation à faire et qu'il n'y a qu'un chiffre ou aucun alors c'est une erreur
};

class CantOpenFile : public AVMExceptions
{
    public :
        CantOpenFile();
};

class TooManyParams : public AVMExceptions
{
    public :
        TooManyParams();
};

#endif