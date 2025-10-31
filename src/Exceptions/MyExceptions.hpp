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
};

class LexicalErrorException : public AVMExceptions
{
    public :
        LexicalErrorException();
};

class ArithmeticException : public AVMExceptions
{
    public :
        ArithmeticException();
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