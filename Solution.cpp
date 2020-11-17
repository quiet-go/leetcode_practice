#include <vector>
#include "Solution.h"
#include <iostream>

using namespace std;

int Solution::removeDuplicates(vector<int>& nums){

	if(nums.size()==0){
		return 0;
	}
	int k = 0;
	int max = 1;
	for(int i = 1; i < nums.size(); ++i){
		if(nums[i] == nums[i-1]){
            max++;
            if(max > 2){
                continue;
            }else{
                nums[++k] = nums[i];
            }
		}else{
            nums[++k] = nums[i];
            max = 1;
		}
	}

	nums.erase(nums.begin() + k + 1, nums.end());
	return nums.size();
}

int Solution::removeElement(vector<int>& nums,  int val){

	if(nums.size() == 0){
        return 0;
	}

	for(int i = 0; i < nums.size(); i++){
        if(nums[i] == val){
            nums.erase(nums.begin() + i);
            //删除一个元素后需要将i回退
            i--;
        }
	}
	return nums.size();
}

void Solution::sortColors(vector<int>& nums){
    if(nums.size() == 0){
        return;
    }

    int k = 0;
    int j = nums.size() - 1;
    //越界判断置前
    while(k < nums.size() && nums[k] == 0) k++;
    while(j >= 0 && nums[j] == 2) j--;

    for(int i = k ;i <= j; i++){
        if(nums[i] == 0){
            if(nums[i] != nums[k]){
                swap(nums[i], nums[k++]);
                i--;
            }
            while(nums[k] == 0 && k < nums.size()) k++;
            if(i < k){
                i = k - 1;
            }
        }else if(nums[i] == 2){
            if(nums[i] != nums[j]){
                swap(nums[i], nums[j--]);
            }
            while(nums[j] == 2 && j >= 0) j--;
            i--;
        }
    }
}
