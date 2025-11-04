#include "MyExceptions.hpp"

ModDivNullException::ModDivNullException() : AVMExceptions("Division or modulo by zero")
{}

PopEmptyStackException::PopEmptyStackException() : AVMExceptions("Cannot pop from an empty stack")
{}

SwapManyParamsException::SwapManyParamsException() : AVMExceptions("Cannot swap due to too many parameters")
{}

NoExitException::NoExitException() : AVMExceptions("Missing exit instruction")
{}

OverflowException::OverflowException() : AVMExceptions("Value overflow")
{}

UnderflowException::UnderflowException() : AVMExceptions("Value underflow")
{}

AssertFalseException::AssertFalseException() : AVMExceptions("Assert failed")
{}

PrintFalseException::PrintFalseException() : AVMExceptions("Cannot print from an empty stack")
{}

MinOrMaxException::MinOrMaxException() : AVMExceptions("Cannot search min or max from an empty stack")
{}

AssertEmptyException::AssertEmptyException() : AVMExceptions("Cannot assert from an empty stack")
{}

NotAnInstructionException::NotAnInstructionException() : AVMExceptions("Unknown instruction")
{}

LexicalErrorException::LexicalErrorException() : AVMExceptions("Lexical error")
{}

ArithmeticException::ArithmeticException() : AVMExceptions("Arithmetic error")
{}

CantOpenFile::CantOpenFile() : AVMExceptions("Cannot open file")
{}

TooManyParams::TooManyParams() : AVMExceptions("./avm <file> or ./avm")
{}
