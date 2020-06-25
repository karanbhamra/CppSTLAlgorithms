#include <iostream>
#include <vector>
#include "Algorithms.hpp"
#include <algorithm>
int main()
{
	std::vector<int> nums = { 1,2,3,4,5,5,5,6,7,8,9 };

	ksb::ForEach(nums.begin(), nums.end(), [](auto& val) {std::cout << val * 2 << std::endl; });



	/*std::vector<std::string> names = { "Karan", "Jessica", "Jimmy", "Bob" };
	std::vector<std::string> names2 = { "J", "B" };*/

	//auto itr = ksb::SearchN(nums.begin(), nums.end(), 2, 5);


	/*auto itr = ksb::Search(names.begin(), names.end(), names2.begin(), names2.end(), [](auto& val1, auto& val2) -> bool
		{
			if (val1[0] == val2[0])
			{
				return true;
			}
			return false;
		});

	if (itr != names.end())
	{
		std::cout << "Found at " << *itr << std::endl;
	}
	else
	{
		std::cout << "Not found\n";
	}*/


	return 0;
}