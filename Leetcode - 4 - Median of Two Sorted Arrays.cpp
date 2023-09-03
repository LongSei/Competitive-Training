class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int newSiz = nums1.size() + nums2.size();
        int index1 = 0;
        int index2 = 0;
        int n = nums1.size(); 
        int m = nums2.size();
        int canCheck = (n + m) / 2 + 1;
        double preLastValue = 0;
        double LastValue = 0;
        while (index1 < n || index2 < m) {
            if (index1 + index2 == canCheck) {
                if ((n + m) % 2 == 0) {return ((preLastValue + LastValue) / 2);}
                else {return LastValue;}
            } 
            if (index1 < n && index2 < m) {
                if (nums1[index1] <= nums2[index2]) {
                    preLastValue = LastValue;
                    LastValue = nums1[index1];
                    index1 += 1;
                }
                else {
                    preLastValue = LastValue;
                    LastValue = nums2[index2];
                    index2 += 1;
                }
            }
            else if (index1 < n) {
                preLastValue = LastValue;
                LastValue = nums1[index1];
                index1 += 1;
            }
            else {
                preLastValue = LastValue;
                LastValue = nums2[index2];
                index2 += 1;
            }
        }
        if ((n + m) % 2 == 0) {return ((preLastValue + LastValue) / 2);}
        else {return LastValue;}
    }
};