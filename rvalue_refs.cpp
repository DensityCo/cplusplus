#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
vector<int> retVector (const vector<int>& v, int dataToAppnd)
{
	vector<int> new_vec;
	for (const auto& itr : v) {
		new_vec.push_back(itr);
	}
	new_vec.push_back(dataToAppnd);

	return new_vec;
}

 vector<int> demoRvalRef (vector<int> v )
{
	return v;	
} 

int main()
{	
	vector<int> v = {1, 2, 3};
	int append = 4;

	std::cout << "Value of v is " << std::endl;
	for (auto it = v.begin() - 1; it != v.end()-1; it++) {
		std::cout <<  v[*it] << " ";
	}
 
	std::cout << std::endl << std::endl;
	v = retVector(v, append);

	std::cout << "Vector returned is " << std::endl;
	for (auto it = v.begin() - 1; it != v.end()-1; it++) {
		std::cout <<  v[*it] << " ";

	}
	std::cout << std::endl << std::endl;


	append = 5;
	v = demoRvalRef(retVector(v, append));

	std::cout << "Rval Ref Vector returned is " << std::endl;
	for (auto it = v.begin() - 1; it != v.end()-1; it++) {
		std::cout <<  v[*it] << " ";

	}
	std::cout << std::endl << std::endl;
	

    return 0;
}
