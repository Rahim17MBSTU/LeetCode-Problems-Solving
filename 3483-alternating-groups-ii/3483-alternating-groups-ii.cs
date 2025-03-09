public class Solution {
    public int NumberOfAlternatingGroups(int[] colors, int k) {
        int answer = 0;
        int n = colors.Length;
        List<int> v = new List<int>();
        PriorityQueue<int,int> pq = new PriorityQueue<int,int>();
        foreach(var u in colors) v.Add(u);
        for(int i = 0 ;i < k-1;i++) v.Add(colors[i]);
        n = v.Count;
       // Console.WriteLine(n);
        for(int i = 0 ; i < k-1;i++){
            if(v[i] == v[i+1]){
                pq.Enqueue(i,i);
               // Console.Write(" "+i);
            }
        }
        if(pq.Count == 0) answer++;
        for(int i = 0, j = k;j<n;j++,i++){
            if(v[j] == v[j-1]){
                pq.Enqueue(j-1,j-1);
                //Console.Write(" "+j);
            }
            if(pq.Count!=0 && pq.Peek() == i){
                pq.Dequeue();
            }
            if(pq.Count == 0)answer++;
        }
        return answer;
    }
}