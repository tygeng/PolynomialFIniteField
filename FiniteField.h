/* This class represents a finite field generated on the given integral
 * domain. T is the class representing the integral domain and N is the
 * uppder bound for to generate this finite field.
 *
 * The basic operations are overloaded.
 */
#ifndef FINITEFIELD
#define FINITEFIELD
#include<iostream>
#include"xgcd.h"
namespace Polyff {
	//Forward declaration of the friend operator<<.
template <class T, T& n> class FiniteField;
template <class T, T& n> std::ostream& operator<< (std::ostream&, const FiniteField<T,n>&);

template <class T, T& n> class FiniteField {
public:
    static const FiniteField<T,n> zero;
    static const FiniteField<T,n> one;
    FiniteField() : _val(T::zero) {};
    FiniteField(T val) : _val(val%n) {};

    const FiniteField<T, n> operator+ (const FiniteField<T, n> &f) const;
    const FiniteField<T, n> operator- (const FiniteField<T, n> &f) const;
    const FiniteField<T, n> operator* (const FiniteField<T, n> &f) const;
    const FiniteField<T, n> operator/ (const FiniteField<T, n> &f) const;
    const FiniteField<T, n>& operator= (const FiniteField<T, n> &f);
    const FiniteField<T, n> operator- () const;
    bool operator==(const FiniteField<T, n> &f) const;
    const FiniteField<T, n> inverse() const;


private:
    friend std::ostream& operator<< <>(std::ostream& out, const FiniteField<T,n>& obj);
    T _val;
};

template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::zero;
template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::one(T::one);

template <class T, T& n>
std::ostream& operator<< (std::ostream& out, const FiniteField<T,n>& f) {
    return	out<<f._val;
}


template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::operator+ (const FiniteField<T, n> &f) const {
    return (_val + f._val) % n;
}

template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::operator- (const FiniteField<T, n> &f) const {
    return (_val - f._val) % n;
}

template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::operator* (const FiniteField<T, n> &f) const {
    return (_val * f._val) % n;
}

template <class T, T& n>
const FiniteField<T, n> FiniteField<T, n>::operator/ (const FiniteField<T, n> &f) const {
    return FiniteField(((*this)*f.inverse()));
}
template <class T, T& n>
const FiniteField<T, n>& FiniteField<T, n>::operator= (const FiniteField<T, n> &f) {
    _val = f._val;
    return *this;
}
template <class T, T& n>
const FiniteField<T,n> FiniteField<T,n>::operator-() const {
    return -_val%n;
}
template <class T, T& n>
bool FiniteField<T,n>::operator==(const FiniteField<T, n>& f) const {
    return _val==f._val;
}
template <class T, T& n>
const FiniteField<T,n> FiniteField<T,n>::inverse() const {
    T result;
    xgcd(_val, n, &result);
    return result%n;
}

}
#endif
