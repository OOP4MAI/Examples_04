#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

#define UNUSED(variable) (void)variable

void motivation() {
	std::vector<std::list<std::map<int, std::string>>> someStrangeVector;

	// Just an iterator
	std::vector<std::list<std::map<int, std::string>>>::const_iterator citer = someStrangeVector.cbegin();

	// for cycle
	for (std::vector<std::list<std::map<int, std::string>>>::const_iterator ci = someStrangeVector.cbegin();
		ci != someStrangeVector.cend();
		++ci) {
		// do something
	}

	// of cource, we may use using from C++11 (or typedef for legacy)
	using CIterForMyStrangeVector = std::vector<std::list<std::map<int, std::string>>>::const_iterator;
	using CIter = std::vector<std::list<std::map<int, std::string>>>::const_iterator;

	CIter citer2 = someStrangeVector.cbegin();

	// auto is much more pretty
	auto citer3 = someStrangeVector.cbegin();

	for(auto ci = someStrangeVector.cbegin(); ci != someStrangeVector.cend(); ++ci) {
		// do something
	}

	UNUSED(citer);
	UNUSED(citer2);
	UNUSED(citer3);
}


struct A{
	A(std::initializer_list<int> a){
		std::cout << a.size() << std::endl;
	}
};
void example_types() {

	int i = 0;
	auto ai = i; // ai is int

	std::string str = "Hello";
	auto astr = str; // astr is std::string

	auto errorstr = "Hello"; // errorstr type ?

	const int crefint = 42; //error because of reference
	const auto acrefint = crefint; // const int

	A a({1, 2, 3, 4, 5, 6, 7});
	auto il = {1, 2, 3, 4, 5, 6, 7};

}

auto someFunction2(int a, int b) { // return type ?
	return a + b;
}

auto someFunction3(int a, float b) { // return type ?
	return a + b;
}

//auto someFunction5(auto a){
//	return a;
//}

 auto someFunction4(int a, float b) -> int{ // return type ?
 	if (a)
 		return a;
 	else
 		return b;
 }

int main(int, char *[])
{
	motivation();
	example_types();

	
    return 0;
}
