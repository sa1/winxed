#ifndef INCLUDE_ERRORS_H
#define INCLUDE_ERRORS_H

// errors.h
// Revision 3-feb-2011

#include "token.h"

#include <stdexcept>

class InternalError : public std::runtime_error
{
public:
	InternalError(const std::string &msg);
	~InternalError() throw () {}
};

class CompileError : public std::runtime_error
{
public:
	CompileError(const std::string &msg);
	CompileError(const std::string &msg, const Token &where);
	~CompileError() throw () {}
	unsigned int linenum() const;
	std::string file() const;
private:
	Token w;
};

class Unsupported : public CompileError
{
public:
	Unsupported(const std::string &msg, const Token &where);
};

class UnsupportedInStage : public CompileError
{
public:
	UnsupportedInStage(const std::string &msg, const Token &where);
};

class SyntaxError : public CompileError
{
public:
	SyntaxError(const std::string &msg, const Token &where);
};

class Expected : public SyntaxError
{
public:
	Expected(char msg, const Token &where);
	Expected(const std::string &msg, const Token &where);
};

#endif

// End of errors.h
