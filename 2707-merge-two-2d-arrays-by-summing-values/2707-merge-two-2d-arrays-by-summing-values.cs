public class Solution {
    public int[][] MergeArrays(int[][] nums1, int[][] nums2) {
        Array.Sort(nums1,(a,b) => a[0].CompareTo(b[0]));
        Array.Sort(nums2,(a,b) => a[0].CompareTo(b[0]));
        foreach(var u in nums1){
            Console.WriteLine(u[0]+" "+u[1]);
        }
        Console.WriteLine();
        foreach(var u in nums1){
            Console.WriteLine(u[0]+" "+u[1]);
        }
        Console.WriteLine();
        int n = nums1.Length;
        int m = nums2.Length;
        List<int[]> result = new List<int[]>();
        int i = 0 , j = 0 ;
        while(true){
            if( i < n && j < m && nums1[i][0] < nums2[j][0]){
                result.Add( new int[] {nums1[i][0],nums1[i][1]});
                i++;
            }
            if( i < n && j < m && nums1[i][0] > nums2[j][0]){
                result.Add( new int[] {nums2[j][0],nums2[j][1]});
                j++;
            }
            if( i < n && j < m && nums1[i][0] == nums2[j][0]){
                result.Add( new int[] {nums2[j][0],nums1[i][1]+nums2[j][1]});
                i++;j++;
            }
            if(i >= n && j < m){
                result.Add( new int[] {nums2[j][0],nums2[j][1]});
                j++;
            }if(i < n && j >= m){
                result.Add( new int[] {nums1[i][0],nums1[i][1]});
                i++;
            }
            if(i >= n && j >= m) break;
        }
        return result.ToArray();
    }
}