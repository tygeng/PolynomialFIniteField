#include"FiniteField.h"
#include"Integer.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using namespace Polyff;
Integer N(5);

int main () {
	Integer i1(3);
	Integer i2(4);
	cout<<i1<<endl;
	cout<<i2<<endl;
	cout<<(i1+i2)<<endl;
	 
	FiniteField<Integer, N> f1(7);
	FiniteField<Integer, N> f2(9);
	cout<<(f1+f2)<<endl;
	cout<<(f1*f2)<<endl;
	cout<<(f1-f2)<<endl;
	cout<<(f1/f2)<<endl;
	cout<<f1.inverse()<<endl;
	cout<<xgcd(Integer(144),Integer(1024))<<endl;
	
}
