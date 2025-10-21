#include "MyExceptions.hpp"

ModDivNullException::ModDivNullException() : AVMExceptions("Error: Division or modulo by zero")
{}

PopEmptyStackException::PopEmptyStackException() : AVMExceptions("Error: Cannot pop from an empty stack")
{}

NoExitException::NoExitException() : AVMExceptions("Error: Missing exit instruction")
{}

OverflowException::OverflowException() : AVMExceptions("Error: Value overflow")
{}

UnderflowException::UnderflowException() : AVMExceptions("Error: Value underflow")
{}

AssertFalseException::AssertFalseException() : AVMExceptions("Error: Assert failed")
{}

NotAnInstructionException::NotAnInstructionException() : AVMExceptions("Error: Unknown instruction")
{}

LexicalErrorException::LexicalErrorException() : AVMExceptions("Error: Lexical error")
{}

ArithmeticException::ArithmeticException() : AVMExceptions("Error: Arithmetic error")
{}

CantOpenFile::CantOpenFile() : AVMExceptions("Error: Cannot open file")
{}

TooManyParams::TooManyParams() : AVMExceptions("Error: ./avm <file> or ./avm")
{}
