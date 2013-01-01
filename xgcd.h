#ifndef XGCD
#define XGCD
#include<vector>
namespace Polyff {
	template<class T>
	const T xgcd(T m, T n, T* pp = 0, T* qp = 0) {
		T temp;
		std::vector<T> quotients;
		while(!(m==T::zero)) {
			quotients.push_back(n/m);
			temp = m;
			m = n%m;
			n = temp;
		}
		quotients.back() = T::one;
		quotients.push_back(T::zero);
		typename std::vector<T>::reverse_iterator rip = quotients.rbegin();
		rip+=2;
		while(rip!=quotients.rend()) {
			*rip=*rip * *(rip-1) + *(rip-2);
			rip++;
		}
		if(quotients.size() % 2) {
			if(pp!=0)
			*pp=-quotients[0];
			if(qp!=0)
			*qp=quotients[1];
		}else{
			if(pp!=0)
			*pp=quotients[0];
			if(qp!=0)
			*qp=-quotients[1];

		}


		return temp;
	}
}


#endif
