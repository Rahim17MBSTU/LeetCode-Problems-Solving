public class Solution {
    public int FindLengthOfShortestSubarray(int[] arr) {
        int n = arr.Length,low = 0, high = n-1, ans ;
       
        while (high > 0 && arr[high - 1] <= arr[high]) {
            high--;
        }

        ans = high;
        int last = high;
        Console.WriteLine(low+" "+high);
        while(low < high ){
           while(high < n && arr[low] > arr[high]) high++;
            ans = Math.Min(ans,(high-low-1));
            low++;
            if (low > 0 && arr[low] < arr[low - 1]) {
                break;
            }
        }
    
       
        return ans;

    }
}