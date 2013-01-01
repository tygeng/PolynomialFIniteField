#ifndef INTEGER
#define INTEGER

#include<iostream>

namespace Polyff{
	class Integer;
	std::ostream& operator<<(std::ostream& out, const Integer& i);
	class Integer {
	public:
		static const Integer zero;
		static const Integer one;
		Integer():value(0){}
		Integer(int i):value(i){}
		Integer operator+(const Integer& i) const{
			return Integer(i.value+value);
		}
		Integer operator*(const Integer& i) const{
			return Integer(i.value*value);
		}
		Integer operator%(const Integer& i) const{
			return Integer((value%i.value+i.value)%i.value);
		}
		Integer operator-(const Integer& i) const{
			return Integer(value-i.value);
		}
		Integer operator/(const Integer& i) const{
			return Integer(value/i.value);
		}
		Integer operator-() const {
			return Integer(-value);
		}
		const Integer& operator=(const Integer& i) {
			value=i.value;
			return *this;
		}
		bool operator==(const Integer& i) const {
			return value==i.value;
		}
		operator int () {return value;}

		friend std::ostream& operator<< (std::ostream&, const Integer&);
	private:
		int value;
	};
}
#endif
