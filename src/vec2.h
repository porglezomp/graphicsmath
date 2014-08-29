#ifndef GRAPHICSMATH_VEC_VEC2_H_
#define GRAPHICSMATH_VEC_VEC2_H_

/**
 * @file
 * @section DESCRIPTION
 * A 2 dimensional vector class.
 */

// Forward-declare the needed types
struct vec4;
struct vec3;
struct mat2;

class vec2 {
public: 
	float x; /// @brief The x (first) component of the vector 
	float y; /// @brief The y (second) component of the vector
/// @brief The default constructor, which produces the zero vector.
	vec2();
/**
 *@brief The fill constructor.
 *@param The value to fill the vector with.
 */
	vec2(float);
/// @brief Constructor.
	vec2(float, float);
/// @brief Conversion constructor from vec4.
	explicit vec2(const vec4&);
/// @brief Conversion constructor from vec3.
	explicit vec2(const vec3&);
/**
 * @brief Subscript operator.
 * @param The index to the element (0 or 1)
 * @return Returns a reference to the element.
 */
	float& operator[] (const int);
/**
 * @brief Addition assignment.
 * @param The vec2 to be added.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator+= (const vec2&);
/**
 * @brief Subtraction assignment.
 * @param The vec2 to subtract by.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator-= (const vec2&);
/**
 * @brief Componentwise multiplication assignment.
 *
 * Each component of the left hand vector is multiplied by
 * 		the corresponding component of the right hand vector.
 * @param The vec2 to multiply by.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator*= (const vec2&);
/**
 * @brief Scalar multiplication assignment.
 *
 * Each component of the vector is multiplied by the scalar.
 * @param The scalar to multiply by.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator*= (const float);
/**
 * @brief Componentwise division assignment.
 * 
 * Each component of the vector is divided by the corresponding
 *		component of the right hand vector.
 * @param The vec2 to divide by.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator/= (const vec2&);
/**
 * @brief Scalar division assignment
 *
 * Each component of the vector is divided by the scalar.
 * @param The scalar to divide by.
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator/= (const float);
/**
 * @brief Matrix multiplication assignment.
 * 
 * Left-multiplies the vec2 by the mat2 and assigns it to the vec2
 * @param The matrix to multiply by
 * @return Returns a reference to the left hand vec2.
 */
	vec2& operator*= (const mat2&);
/**
 * @brief The length of the vector.
 * @return The length or magnitude of the vector.
 */
	float length();
};

/**
 * @brief Equality operator.
 * @param The left hand vec2.
 * @param The right hand vec2.
 * @return Returns a boolean indicating if the two vectors are equal.
 */
bool operator== (const vec2&, const vec2&);
/**
 *	@brief Inequality operator.
 * @param The left hand vec2.
 * @param The right hand vec2.
 * @return Returns a boolean indicating if the two vectors are not equal.
 */
bool operator!= (const vec2&, const vec2&);

/// Addition
vec2 operator+ (vec2, const vec2&);

/// Subtraction
vec2 operator- (vec2, const vec2&);

/// Negation
vec2 operator- (const vec2&);

/// Componentwise vector multiplication
vec2 operator* (vec2, const vec2&);

/// Scalar multiplication of the vector
vec2 operator* (vec2, const float);
vec2 operator* (const float, vec2);

/// Componentwise vector division
vec2 operator/ (vec2, const vec2&);

/// Scalar division of the vector
vec2 operator/ (vec2, const float);

/// Length of the vector
float length(const vec2&);

/// Return a unit vector of the input
vec2 normalize(const vec2&);

/// The angle that the vector points
float angle(const vec2&);

/// Compute the dot product of two vectors
float dot(const vec2&, const vec2&);

#endif