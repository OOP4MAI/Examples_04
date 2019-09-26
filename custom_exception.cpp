#include <cmath>
#include <iostream>
#include <exception>

class WrongArgumentException : public std::exception {
public:

    virtual const char* what() {
        //throw int(1);
        return "Wrong argument exception";
    }
};

class SquareEquation {
private:
    double a;
	double b;
	double c;
public:
	SquareEquation(double aa,double bb,double cc): a(aa),b(bb),c(cc){
         if((b*b-4*a*c)<0) throw WrongArgumentException();
	}

	double FindX1(){
		return (-b-sqrt(b*b-4*a*c))/(2*a);
	}

	double FindX2(){
		return (-b+sqrt(b*b-4*a*c))/(2*a);
	}
};

int main(){
	double a, b, c;

    std::cout << "Enter a:";
    std::cin >> a;

    std::cout << "Enter b:";
    std::cin >> b;

    std::cout << "Enter c:";
    std::cin >> c;

    try{
		SquareEquation se(a, b, c);
		
		std::cout << "X1=" << se.FindX1() << "\n";
		std::cout << "X2=" << se.FindX2() << "\n";
    
    }catch(WrongArgumentException &ex){
        std::cout << "Exception in runtime:" << ex.what() << std::endl;
    }
    
    return 0;
}
