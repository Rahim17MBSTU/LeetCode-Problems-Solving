public class Solution {
    public int[] PivotArray(int[] nums, int pivot) {
        List<int> Less = new List<int>();
        List<int> Equal = new List<int>();
        List<int> Greater = new List<int>();
        List<int> Result = new List<int>();
        foreach(var u in nums){
            if(pivot < u) Greater.Add(u);
            else if(pivot > u) Less.Add(u);
            else Equal.Add(u);
        }

        Result.InsertRange(Result.Count,Less);
        Result.InsertRange(Result.Count,Equal);
        Result.InsertRange(Result.Count,Greater);
        return Result.ToArray();
    }
}