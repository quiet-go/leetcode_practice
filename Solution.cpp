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

        if(nums[i] < 2){
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

//合并后两个有序数组
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(m <= 0){
            nums1 = nums2;
            return;
        }

        if(n <= 0){
            return;
        }

        int i = m - 1;
        int j = n - 1;
        int k = m + n -1;
        while(k >= 0){
            if(i >= 0){
                if(j >= 0 && nums1[i] <= nums2[j]){
                    nums1[k--] = nums2[j--];
                }else{
                    nums1[k--] = nums1[i--];
                }
            }else{
                nums1[k--] = nums2[j--];
            }
        }
}

int quickSort(vector<int>& nums, int l, int r);

int Solution::findKthLargest(vector<int>& nums, int k){
    if(nums.size() == 0){
        return 0;
    }else if(nums.size() == 1){
        return nums[0];
    }

    //基于快速排序的方法
    int l = 0;
    int r = nums.size() - 1;
    int mid = (r - l) / 2 + l;
    while(mid != nums.size() - k){
        mid = (r - l) / 2 + l;
        while(mid != nums.size() - k){
            mid = (r - l) / 2 + l;
            while(l < r){
                while(l < r && nums[l] < nums[mid])
                    l++;
                while(r > l && nums[r] >= nums[mid])
                    r--;
                if(l < r){
                    swap(nums[l], nums[r]);
                }
            }

            if(mid < nums.size() - k){
                l = mid + 1;;
            }else if(mid > nums.size() - k){
                r = mid - 1;
            }
            swap(nums[l], nums[mid]);
        }
    }
}

int quickSort(vector<int>& nums, int l, int r){
    int mid = (r - l) / 2 +l;
    while(l < r){
        while(nums[l] < nums[mid])
            l++;
        while(nums[r] >= nums[mid])
            r--;
        if(l < r){
            swap(nums[l], nums[r]);
        }
    }
    return l;
}
