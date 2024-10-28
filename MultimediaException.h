// File: MultimediaException.h
#ifndef MULTIMEDIAEXCEPTION_H
#define MULTIMEDIAEXCEPTION_H

#include <stdexcept>
#include <string>

class MultimediaException : public std::runtime_error {
public:
    explicit MultimediaException(const std::string& message) : std::runtime_error(message) {}
};

class DuplicateNameException : public MultimediaException {
public:
    explicit DuplicateNameException(const std::string& message) : MultimediaException(message) {}
};

class NotFoundException : public MultimediaException {
public:
    explicit NotFoundException(const std::string& message) : MultimediaException(message) {}
};

class InvalidNameException : public MultimediaException {
public:
    explicit InvalidNameException(const std::string& message) : MultimediaException(message) {}
};

class InvalidDurationException : public MultimediaException {
public:
    explicit InvalidDurationException(const std::string& message) : MultimediaException(message) {}
};

#endif // MULTIMEDIAEXCEPTION_H