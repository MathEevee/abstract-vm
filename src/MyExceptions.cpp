#include "MyExceptions.hpp"

ModDivNullException::ModDivNullException() : AVMExceptions("Error: Division or modulo by zero")
{}

ModDivNullException::~ModDivNullException()
{}

PopEmptyStackException::PopEmptyStackException() : AVMExceptions("Error: Cannot pop from an empty stack")
{}

PopEmptyStackException::~PopEmptyStackException()
{}

NoExitException::NoExitException() : AVMExceptions("Error: Missing exit instruction")
{}

NoExitException::~NoExitException()
{}

OverflowException::OverflowException() : AVMExceptions("Error: Value overflow")
{}

OverflowException::~OverflowException()
{}

UnderflowException::UnderflowException() : AVMExceptions("Error: Value underflow")
{}

UnderflowException::~UnderflowException()
{}

AssertFalseException::AssertFalseException() : AVMExceptions("Error: Assert failed")
{}

AssertFalseException::~AssertFalseException()
{}

NotAnInstructionException::NotAnInstructionException() : AVMExceptions("Error: Unknown instruction")
{}

NotAnInstructionException::~NotAnInstructionException(){}

LexicalErrorException::LexicalErrorException() : AVMExceptions("Error: Lexical error")
{}

LexicalErrorException::~LexicalErrorException(){}


ArithmeticException::ArithmeticException() : AVMExceptions("Error: Arithmetic error")
{}

ArithmeticException::~ArithmeticException(){}

CantOpenFile::CantOpenFile() : AVMExceptions("Error: Cannot open file")
{}

CantOpenFile::~CantOpenFile(){}


TooManyParams::TooManyParams() : AVMExceptions("Error: ./avm <file> or ./avm")
{}

TooManyParams::~TooManyParams()
{}
