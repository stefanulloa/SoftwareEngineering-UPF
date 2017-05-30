#include <iostream>
using namespace std;

template <typename Type>
class Fraction {
  private:
	Type _numerator;
	Type _denominator;
  public:
	Fraction(Type numerator, Type denominator){
		_numerator=numerator;
		_denominator=denominator;
	}

Type getNumerator(){return _numerator;}
Type getDenominator(){return _denominator;}

Type MCD(Type numerator, Type denominator){
	if(numerator%denominator==0){
		return denominator;
		}
	else if(numerator%denominator > 0){
		MCD(denominator,numerator%denominator);
	}
}

Fraction operator *(Fraction & other){
	Type A = _numerator * other.getNumerator();
	Type B = _denominator * other.getDenominator();
	Type M = MCD(A,B);
	return Fraction(A/M,B/M);
	}
	
Fraction operator +(Fraction & other) {
	Type A = (_numerator * other.getDenominator())+(_denominator*other.getNumerator());
	Type B = _denominator * other.getDenominator();
	Type M = MCD(A,B);
	return Fraction(A/M,B/M);

}
};

int main(){

	Fraction <int>f1 = Fraction <int>(1,8);
	Fraction <int>f2 = Fraction <int>(4,8);
	Fraction <int>f3= f1 + f2;
	Fraction <int>f4= f1 * f2;
	
	cout << "\n" << f1.getNumerator() << "/" << f1.getDenominator() << "+" << f2.getNumerator() << "/" << f2.getDenominator() << "=" << f3.getNumerator() << "/" << f3.getDenominator() << "\n";
	cout << f1.getNumerator() << "/" << f1.getDenominator() << "*" << f2.getNumerator() << "/" << f2.getDenominator() << "=" << f4.getNumerator() << "/" << f4.getDenominator() << "\n" << "\n";
	
	Fraction <short>f5 = Fraction <short>(10,8);
	Fraction <short>f6 = Fraction <short>(6,2);
	Fraction <short>f7= f5 + f6;
	Fraction <short>f8= f5 * f6;
	
	cout << f5.getNumerator() << "/" << f5.getDenominator() << "+" << f6.getNumerator() << "/" << f6.getDenominator() << "=" << f7.getNumerator() << "/" << f7.getDenominator() << "\n";
	cout << f5.getNumerator() << "/" << f5.getDenominator() << "*" << f6.getNumerator() << "/" << f6.getDenominator() << "=" << f8.getNumerator() << "/" << f8.getDenominator() << "\n" << "\n";
	
	Fraction <unsigned long long>f9 = Fraction <unsigned long long>(5,2);
	Fraction <unsigned long long>f10 = Fraction <unsigned long long>(9,3);
	Fraction <unsigned long long>f11= f9 + f10;
	Fraction <unsigned long long>f12= f9 * f10;
	
	cout << f9.getNumerator() << "/" << f9.getDenominator() << "+" << f10.getNumerator() << "/" << f10.getDenominator() << "=" << f11.getNumerator() << "/" << f11.getDenominator() << "\n";
	cout << f9.getNumerator() << "/" << f9.getDenominator() << "*" << f10.getNumerator() << "/" << f10.getDenominator() << "=" << f12.getNumerator() << "/" << f12.getDenominator() << "\n" << "\n";

}


