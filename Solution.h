#include <vector>
using namespace std;

class Solution {
public:
    //80
    int removeDuplicates(vector<int>& nums);
    //27
    int removeElement(vector<int>& nums, int val);
    //75
    void sortColors(vector<int>& nums);

    //88
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

    //215，可以尝试使用堆排序
    int findKthLargest(vector<int>& nums, int k);
};
