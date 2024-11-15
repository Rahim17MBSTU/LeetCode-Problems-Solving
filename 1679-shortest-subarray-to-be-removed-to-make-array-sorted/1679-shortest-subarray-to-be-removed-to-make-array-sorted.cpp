class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
       vector<int>v(arr.size(),0);
       int cnt = 1,n = arr.size(),ans=1;
       v[n-1] = 1;
       for(int i = arr.size()-2;i>=0;i--){
         if(arr[i] <= arr[i+1]){
            v[i] = 1;
            cnt++;
         }else{
            break;
         }
       }
       ans = n-cnt;
       //cout <<" === "<< ans <<endl;
       for(auto u:v)cout<<u<<" ";
       cout<<endl;
       auto f = [&](int mid,int value){
           if(arr[mid] >= value && v[mid] == 1) return true;
           else return false;
       };
       for(int i = 0 ; i<n-1;i++){
         int value = arr[i],indx = n;
         int low = i+1;
         int high = n-1;
         
         while(low<=high){
            int mid = (low + high)>> 1;
            if(f(mid,arr[i])){
                indx = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
         }
         //cout<<i<< " "<<indx-1<<endl;
         ans = min(ans,indx - 1 - i);
         if(arr[i] > arr[i+1])break;
       }
     
        return ans;
    }
};