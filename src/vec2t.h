#ifndef GRAPHICSMATH_VEC_VEC2_H
#define GRAPHICSMATH_VEC_VEC2_H

/**
 * @file
 * @section DESCRIPTION
 * A 2 dimensional vector class.
 */

// Forward-declare the needed types
//struct vec4;
template <typename T> struct vec3t;
//struct mat2;


template <typename T>
struct vec2t {
	T x; /// @brief The x (first) component of the vector 
	T y; /// @brief The y (second) component of the vector
/// @brief The default constructor, which produces the zero vector.
	vec2t();
/**
 *@brief The fill constructor.
 *@param The value to fill the vector with.
 */
	vec2t(T);
/// @brief Constructor.
	vec2t(T, T);
/// @brief Conversion constructor from vec4.
	//explicit vec2t(const vec4<T>&);
/// @brief Conversion constructor from vec3.
	explicit vec2t(const vec3t<T>&);
/**
 * @brief Subscript operator.
 * @param The index to the element (0 or 1)
 * @return Returns a reference to the element.
 */
	T& operator[] (const int);
/**
 * @brief Addition assignment.
 * @param The vec2t to be added.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator+= (const vec2t<T>&);
/**
 * @brief Subtraction assignment.
 * @param The vec2t to subtract by.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator-= (const vec2t<T>&);
/**
 * @brief Componentwise multiplication assignment.
 *
 * Each component of the left hand vector is multiplied by
 * 		the corresponding component of the right hand vector.
 * @param The vec2t to multiply by.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator*= (const vec2t<T>&);
/**
 * @brief Scalar multiplication assignment.
 *
 * Each component of the vector is multiplied by the scalar.
 * @param The scalar to multiply by.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator*= (const T);
/**
 * @brief Componentwise division assignment.
 * 
 * Each component of the vector is divided by the corresponding
 *		component of the right hand vector.
 * @param The vec2t to divide by.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator/= (const vec2t<T>&);
/**
 * @brief Scalar division assignment
 *
 * Each component of the vector is divided by the scalar.
 * @param The scalar to divide by.
 * @return Returns a reference to the left hand vec2t.
 */
	vec2t<T>& operator/= (const T);
/**
 * @brief Matrix multiplication assignment.
 * 
 * Left-multiplies the vec2t by the mat2 and assigns it to the vec2t
 * @param The matrix to multiply by
 * @return Returns a reference to the left hand vec2t.
 */
	//vec2t<T>& operator*= (const mat2<T>&);
/**
 * @brief The length of the vector.
 * @return The length or magnitude of the vector.
 */
	T length();
};

/**
 * @brief Equality operator.
 * @param The left hand vec2t.
 * @param The right hand vec2t.
 * @return Returns a boolean indicating if the two vectors are equal.
 */
template <typename T>
bool operator== (const vec2t<T>&, const vec2t<T>&);
/**
 *	@brief Inequality operator.
 * @param The left hand vec2t.
 * @param The right hand vec2t.
 * @return Returns a boolean indicating if the two vectors are not equal.
 */
template <typename T> 
bool operator!= (const vec2t<T>&, const vec2t<T>&);

/// Addition
template <typename T>
vec2t<T> operator+ (vec2t<T>, const vec2t<T>&);

/// Subtraction
template <typename T>
vec2t<T> operator- (vec2t<T>, const vec2t<T>&);

/// Negation
template <typename T>
vec2t<T> operator- (const vec2t<T>&);

/// Componentwise vector multiplication
template <typename T>
vec2t<T> operator* (vec2t<T>, const vec2t<T>&);

/// Scalar multiplication of the vector
template <typename T>
vec2t<T> operator* (vec2t<T>, const T);
template <typename T>
vec2t<T> operator* (const T, vec2t<T>);

/// Componentwise vector division
template <typename T>
vec2t<T> operator/ (vec2t<T>, const vec2t<T>&);

/// Scalar division of the vector
template <typename T>
vec2t<T> operator/ (vec2t<T>, const T);

/// Length of the vector
template <typename T>
T length(const vec2t<T>&);

/// Return a unit vector of the input
template <typename T>
vec2t<T> normalize(const vec2t<T>&);

/// The angle that the vector points
template <typename T>
T angle(const vec2t<T>&);

/// Compute the dot product of two vectors
template <typename T>
T dot(const vec2t<T>&, const vec2t<T>&);

// Include the implementation of the templates
#include "vec2t.cpp"
typedef vec2t<double> vec2d;
typedef vec2t<float> vec2f;
#ifdef GRAPHICSMATH_DEFAULT_DOUBLE
typedef vec2t<double> vec2;
#else
typedef vec2t<float> vec2;
#endif

#endif