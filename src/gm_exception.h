#ifndef GRAPHICS_MATH_EXCEPTION_H
#define GRAPHICS_MATH_EXCEPTION_H
#include <exception>

struct singular_matrix : public std::exception {
    const char* what() const throw(){
        return "Singular matrix cannot be inverted";
    }
};

#endif
