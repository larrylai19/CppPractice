// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size() + nums2.size();
        nums1 = merge(nums1, nums2);
        return n % 2 ? nums1[n / 2] : double(nums1[n / 2] + nums1[n / 2 - 1]) / 2;
    }
private:
    vector<int> merge(vector<int>& v1, vector<int>& v2)
    {
        int n1 = v1.size(), n2 = v2.size();
        vector<int> v(n1 + n2);
        int i = 0, i1 = 0, i2 = 0;
        while(i1 < n1 || i2 < n2)
        {
            if(i1 >= n1) v[i++] = v2[i2++];
            else if(i2 >= n2) v[i++] = v1[i1++];
            else v[i++] = v1[i1] < v2[i2] ? v1[i1++] : v2[i2++];
        }
        return v;
    }
};