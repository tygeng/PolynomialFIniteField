#include"FiniteField.h"
#include"Integer.h"
#include"Polynomial.h"
#include<iostream>
#include<vector>
using namespace std;
using Polyff::Integer;
using Polyff::Polynomial;
using Polyff::operator<<;
using Polyff::FiniteField;
using std::cout;
using std::endl;
using std::cin;
Integer N(5);

int main () {
	cout<<N<<endl;
	cout<< "testing program is running"<<endl;
	std::vector<FiniteField<Integer,N> > cs;
	cs.push_back(FiniteField<Integer, N>(Integer(4)));
	cs.push_back(FiniteField<Integer, N>(Integer(3)));
	cs.push_back(FiniteField<Integer, N>(Integer(2)));
	cout<<cs[0]<<cs[1]<<cs[2]<<cs.size()<<endl;	
	Polynomial<FiniteField<Integer, N> > p1(cs);
	cout<< p1<<endl;
	cout<< (p1+p1) <<endl;
	cout<< (p1-p1) <<endl;
	cout<< (p1*p1) <<endl;
	cout<< (p1*p1/p1/p1) <<endl;
	cout<< ((p1+p1)/p1)<<endl;
	cout<< (p1+p1*p1)%(p1*p1)<<endl;
	

	
	
}
