#ifndef POLYNOMIAL
#define POLYNOMIAL
#include<vector>
namespace Polyff {
template<class F> class Polynomial;
template<class F>
std::ostream& operator<< (std::ostream&, const Polynomial<F> f);
template<class F>
class Polynomial {
public:
    static const Polynomial<F> zero;
    static const Polynomial<F> one;
    Polynomial(){}
    Polynomial(const Polynomial<F>& p): coefficients(p.coefficients){}
    Polynomial(std::vector<F> cs): coefficients(cs) {
        clean();
    }
    Polynomial(const F& f) {
        coefficients.push_back(f);
    }
    const Polynomial<F> operator+ (const Polynomial<F>& p) const;
    const Polynomial<F> operator* (const Polynomial<F>& p) const;
    const Polynomial<F> operator- (const Polynomial<F>& p) const;
    const Polynomial<F> operator/ (const Polynomial<F>& p) const;
    const Polynomial<F> operator% (const Polynomial<F>& p) const;
    const Polynomial<F> operator-() const;
    const Polynomial<F>& operator=(const Polynomial<F>& p) {
        coefficients=p.coefficients;
    }
    bool operator==(const Polynomial<F> p) const {
        return coefficients==p.coefficients;
    }

// private:
    std::vector<F> coefficients;
	friend std::ostream& operator<< <>(std::ostream& out, const Polynomial<F> f);
    int clean();
};

template<class F>
const Polynomial<F> Polynomial<F>::zero;
template<class F>
const Polynomial<F> Polynomial<F>::one(F::one);

template<class F>
std::ostream& operator<< (std::ostream& out, const Polynomial<F> f) {
// 	out<<f.coefficients.size();
	if(f.coefficients.empty()) {
		return out<<"0";
	}
	if(! (f.coefficients[0]==F::zero)) {
		out<<f.coefficients[0];
	}
	for (unsigned i=1;i<f.coefficients.size();i++) {
		if (f.coefficients[i]==F::zero) {
			continue;
		}else{
			if(f.coefficients[i]==F::one) {
				out<<" + x";
			}else{
				out<<" + "<<f.coefficients[i]<<"x";
			}
			if(i!=1) {
				out<<"^"<<i;
			}
		}
	}
	return out;
}

template<class F>
int Polynomial<F>::clean() {
	int counter = 0;
	while (!coefficients.empty() && (coefficients.back()==F::zero) ) {
		counter++;
		coefficients.pop_back();
	}
	return counter;
}

template<class F>
const Polynomial<F> Polynomial<F>::operator+ (const Polynomial<F>& p) const {
    Polynomial<F> result;
    if(coefficients.size()>p.coefficients.size()) {
        result.coefficients.reserve(coefficients.size());
        unsigned i;
        for(i = 0; i<p.coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]+p.coefficients[i]);

        }
        for(; i<coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]);
        }
    } else {
        result.coefficients.reserve(p.coefficients.size());
        unsigned i;
        for(i = 0; i<coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]+p.coefficients[i]);

        }
        for(; i<p.coefficients.size(); i++) {
            result.coefficients.push_back(p.coefficients[i]);
        }
    }
    result.clean();
    return result;
}
template<class F>
const Polynomial<F> Polynomial<F>::operator* (const Polynomial<F>& p) const {
	if(coefficients.size()==0 || p.coefficients.size()==0) {
		return Polynomial<F>();
	}
	Polynomial<F> result;
	result.coefficients.resize(coefficients.size()+p.coefficients.size()-1);
	for(unsigned i=0;i<coefficients.size();i++) {
		for(unsigned j=0;j<p.coefficients.size();j++) {
			result.coefficients[i+j] = result.coefficients[i+j] + coefficients[i]*p.coefficients[j];
		}
	}
	return result;

}
template<class F>
const Polynomial<F> Polynomial<F>::operator- (const Polynomial<F>& p) const {
    Polynomial<F> result;
    if(coefficients.size()>p.coefficients.size()) {
        result.coefficients.reserve(coefficients.size());
        unsigned i;
        for(i = 0; i<p.coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]-p.coefficients[i]);

        }
        for(; i<coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]);
        }
    } else {
        result.coefficients.reserve(p.coefficients.size());
        unsigned i;
        for(i = 0; i<coefficients.size(); i++) {
            result.coefficients.push_back(coefficients[i]-p.coefficients[i]);

        }
        for(; i<p.coefficients.size(); i++) {
            result.coefficients.push_back(-p.coefficients[i]);
        }
    }
    result.clean();
    return result;

}
template<class F>
const Polynomial<F> Polynomial<F>::operator/ (const Polynomial<F>& p) const { 
	if(coefficients.size()<p.coefficients.size()) {
		return Polynomial<F>(); //return zero
	}
	Polynomial<F> result;
	result.coefficients.resize(coefficients.size()-p.coefficients.size()+1);
	Polynomial<F> remainder(*this);
	int l = p.coefficients.size();
	for(int i = (int)(remainder.coefficients.size() - p.coefficients.size()); i>=0;) {
		F c = remainder.coefficients.back() / p.coefficients.back();
		result.coefficients[i]=c;
		unsigned L = remainder.coefficients.size();
		for (unsigned j = 1; j<= p.coefficients.size(); j++) {
			remainder.coefficients[L-j]=remainder.coefficients[L-j] - (p.coefficients[l-j]*c);
		}
		i-=remainder.clean();
	}
	return result;
}

template<class F>
const Polynomial<F> Polynomial<F>::operator% (const Polynomial<F>& p) const {
	Polynomial<F> remainder(*this);
	int l = p.coefficients.size();
	for(int i = (int)(remainder.coefficients.size() - p.coefficients.size()); i>=0;) {
		F c = remainder.coefficients.back() / p.coefficients.back();
		unsigned L = remainder.coefficients.size();
		for (unsigned j = 1; j<= p.coefficients.size(); j++) {
			remainder.coefficients[L-j]=remainder.coefficients[L-j] - (p.coefficients[l-j]*c);
		}
		i-=remainder.clean();
	}
	return remainder;
}
template<class F>
const Polynomial<F> Polynomial<F>::operator- () const {
	Polynomial<F> result;
	for(int i=0;i<coefficients.size();i++) {
		result.coefficients.push_back(-coefficients[i]);
	}
	return result;
}
}

#endif
