public class Solution {
    public int MaxChunksToSorted(int[] nums) {
        int n = nums.Length;
        int answer = 0 ; 
        SortedSet<int> set = new SortedSet<int>();
        for(int i = 0 ; i < n ; i++){
            set.Add(nums[i]);
            int lastValue = set.Max();
            if(lastValue == i){
                set.Clear();
                answer++;
            }
        }
         return answer;
    }
}