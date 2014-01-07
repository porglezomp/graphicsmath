#ifndef GRAPHICS_MATH_EXCEPTION_H
#define GRAPHICS_MATH_EXCEPTION_H

struct SingularException: std::exception { const char* what() const throw();}

#endif