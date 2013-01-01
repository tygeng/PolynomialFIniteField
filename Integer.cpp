
#include"Integer.h"
#include<iostream>
using Polyff::Integer;

const Integer Integer::zero;
const Integer Integer::one(1);
std::ostream& Polyff::operator<<(std::ostream& out, const Integer& i) {
	return out<<(i.value);
}
