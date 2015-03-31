#ifndef VECTOR2_H
#define VECTOR2_H

#define _USE_MATH_DEFINES

/*! \class Vector2D
 \brief A 2D vector template
 */

#include <stdio.h>
#include <cmath>
#include <iostream>

template <class N> class Vector2
{
private:
	N m_afData[2];//!< X & Y vector values
public:
	Vector2(){m_afData[0] = 0; m_afData[1] = 0;};//!< Default constuctor (sets all values to 0)
    Vector2(const N kAllValues /*!< Float to apply to both X and Y values*/){m_afData[0] = kAllValues; m_afData[1] = kAllValues;}; //!< Constructor which take a number to assign all values
	Vector2(const N kX /*!< X value*/, const N kY /*!< Y value*/) {m_afData[0] = kX; m_afData[1] = kY;};//!< Constructor which takes X and Y values

	void set(const N kX /*!< X value*/, const N kY /*!< Y value*/) {m_afData[0] = kX; m_afData[1] = kY;};//!< Sets the X and Y values
    void setX(const N kX /*!< X value*/) {m_afData[0] = kX;}; //!< Sets the X value
    void setY(const N kY /*!< Y value*/) {m_afData[1] = kY;}; //!< Sets the Y value

	float dotProduct(const Vector2<N>& other /*!< Other vector*/) const {return (x()*other.x()) + (y()*other.y());}; //!< Returns the dot product of the current vector and another vector
	float crossProduct(const Vector2<N>& other /*!< Other vector*/) const {return (x() * other.y()) - (y() * other.x());}; //!< Returns the cross product of the current vector and another vector

	Vector2<N> crossProduct(const float kfScalar /*!< Scalar value */) const {return Vector2<float>(y()* kfScalar,- kfScalar*x());}; //!< Returns the cross product of the vector
    Vector2<float> crossProduct(const float kfScalar /*!< Scalar value */, const Vector2<float>& kVec /*!< vector*/) const { return Vector2D<float>(-kfScalar * kVec.y(), kfScalar * kVec.x()); } //!< Returns the cross product of a scalar and a vector
	Vector2<N> unitVector() const {const float kfMag = magnitude(); return Vector2<N>(x()/kfMag, y()/kfMag);}; //!< Returns the unit vector

	N x() const {return m_afData[0];}; //!< Returns the X value of the vector
	N y() const {return m_afData[1];}; //!< Returns the Y value of the vector

	float magnitude() const {return sqrt(magnitudeSquared());}; //!< Returns the magnitude of the vector
	float magnitudeSquared() const {return (x()*x()) + (y()*y());}; //!< Returns the square of the length of the vector2D

	Vector2<N> operator-(const Vector2<N>& kOther /*!< Other vector*/) const {return Vector2<N>(x() - kOther.x(), y() - kOther.y());}; //!< Returns the value of the current vector minus another vector
	Vector2<N> operator-(const float kfScalar /*!< Scalar value */) const {return Vector2(x() - kfScalar, y() - kfScalar);}; //!< Returns the value of the current vector minus a float
    Vector2<N> operator-() const {return Vector2<N>(-x(),-y());};//!< Returns the negative of the vector
	Vector2<N>& operator-=(const Vector2<N>& kOther /*!< Other vector*/) {set(x() - kOther.x(), y() - kOther.y());return *this;};//!< Assigns the vector to its current value minus another vector

	Vector2<N> operator+(const Vector2<N>& kOther /*!< Other vector*/) const {return Vector2<N>(x() + kOther.x(), y() + kOther.y());}; //!< Returns the value of the current vector plus another vector
	Vector2<N> operator+(const float kfScalar /*!< Scalar value */) const {return Vector2<N>(x() + kfScalar, y() + kfScalar);}; //!< Returns the value of the current vector plus a float
	Vector2<N>& operator+=(const Vector2<N>& kOther /*!< Other vector*/) {set(x() + kOther.x(), y() + kOther.y()); return *this;};//!< Assigns the vector to its current value plus another vector

	Vector2<N> operator*(const Vector2<N>& kOther /*!< Other vector*/) const {return Vector2<N>(x() * kOther.x(), y() * kOther.y());}; //!< Returns the value of the current vector multiplied by another vector
	Vector2<N>& operator*=(const Vector2<N>& kOther /*!< Other vector*/) {set(x() * kOther.x(), y() * kOther.y()); return *this;};//!< Assigns the vector to its current value multiplied by another vector
	Vector2<N> operator/(const Vector2<N>& kOther /*!< Other vector*/) const {return Vector2<N>(x() / kOther.x(), y() / kOther.y());}; //!< Returns the value of the current vector divided by another vector
	Vector2<N> operator*(const float kfScalar /*!<Scalar value */) const {return Vector2<N>(x() * kfScalar, y() * kfScalar);}; //!< Returns the value of the current vector multiplied by a float

	Vector2<N> operator/(const float kfScalar /*!< Scalar value */) const {return Vector2<N>(x() / kfScalar, y() / kfScalar);}; //!< Returns the value of the current vector divided by a float
    Vector2<N>& operator/=(const Vector2<N>& kOther /*!< Other vector*/) {set(Vector2<N>(x()/kOther.x(),y()/kOther.y()));}; //!< Assigns the vector to its current value divided by another vector
    Vector2<N>& operator/=(const float kfScalar /*!< Scalar value */) {set(x()/kfScalar, y()/kfScalar); return *this;}; //!< Assigns the vector to its current value divided by a float scalar

	Vector2<N>& operator=(const Vector2<N>& kOther /*!< Other vector*/) {set(kOther.x(), kOther.y()); return *this;};//!< Assigns the value of a vector to another vector

    bool operator==(const Vector2<N>& kOther /*!< Other vector*/) const {if (x() == kOther.x() && y() == kOther.y()) return true; return false;}; //!< Returns true if the current vector has the same value as another vector
    bool operator!=(const Vector2<N>& kOther /*!< Other vector*/) const {if (x() != kOther.x() || y() != kOther.y()) return true; return false;}; //!< Returns true if the current vector has the same value as another vector
};

template <class N>
inline Vector2<N> operator*(const float kfScalar /*!< Scalar value */, const Vector2<N>& kVec /*!< vector*/) //!< Multiplies a float by a vector (returns a vector)
{
    return Vector2<N>(kVec * kfScalar);
}

template <class N>
inline Vector2<N> operator+(const float kfScalar /*!< Scalar value */, const Vector2<N>& vec /*!< vector*/) //!< Adds a vector to a float (returns a vector)
{
    return Vector2<N>(vec + kfScalar);
}

#endif