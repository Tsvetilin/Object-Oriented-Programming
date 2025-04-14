#include <iostream>

#include "Vector.h"

int main()
{
	{
		Vector arr;

		std::cin >> arr;

		arr.insert(7, 3);

		std::cout << arr;
	}
	{
		Vector arr;

		arr.push_back(3);
		arr.push_back(7);
		arr.push_back(21);
		arr.push_back(18);

		std::cout << arr;
	}

	return 0;
}