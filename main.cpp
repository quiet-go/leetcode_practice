#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main(int argc, char **argv)
{
	Solution solution;
	vector<int> nums1 = {3,2,1,5,6,4};
    vector<int> nums2 = {2,5,6};
	int i = solution.findKthLargest(nums1,2);
    cout << i << ",";

	//for(auto i : nums1){
      //  cout << i << ",";
	//}
	return 0;
}
