public class Solution {
    public bool DoesValidArrayExist(int[] derived) {
        int res = 0;
        foreach(var item in derived) res ^= item;
        return res == 0 ? true : false;
    }
}