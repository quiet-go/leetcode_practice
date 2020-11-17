#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main(int argc, char **argv)
{
	Solution solution;
	vector<int> nums = {0};
	solution.sortColors(nums);

	for(auto i : nums){
        cout << i << ",";
	}
	return 0;
}
