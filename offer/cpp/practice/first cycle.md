#include "iostream"


int main()
{   
	bool inited = false;
	while (1) {
		if (!inited) {
			std::cout << inited << std::endl;
			inited = true;
		}
		else if (inited) {
			std::cout << inited << std::endl;
		}
	}

    return 0;
}