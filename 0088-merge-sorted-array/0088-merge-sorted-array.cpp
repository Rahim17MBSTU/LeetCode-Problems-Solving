class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(i < m && j < n){// 1 , 2 , 2 , 0 , 0 , 0
                    //  3 , 5 , 6
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                i++;
                int k = j;
                for(;k < n-1;k++){
                    if(nums2[k] > nums2[k+1])
                        swap(nums2[k],nums2[k+1]);
                    else{
                        break;
                    }
                }
            }else{
                i++;
            }
        }
        //cout << i <<" "<<j<<endl;
        for(;i<n+m && j<n;i++)nums1[i] = nums2[j++];
        //return ;
    }
};