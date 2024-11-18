public class Solution {
    public int[] Decrypt(int[] code, int k) {
        int n = code.Length;
        int[] arr = new int[2*n];
        int[] res = new int[n];
       
        for(int i = 0;i<2*n;i++){
            arr[i] = code[i%n];
            if(i != 0) arr[i] = arr[i-1] + arr[i];
        }
        //for(int i = 0 ;i<2*n;i++)
        //Console.Write(arr[i]+" ");
        int last = n-1,first = n -1 - Math.Abs(k);
        for(int i = 0 ;i <n;i++){
            if(k >0){
                res[i] = arr[i+k] - arr[i];
            }else if(k<0){
                res[i] = arr[last++] - arr[first++];
            }else break;
        }
        return res;

    }
}