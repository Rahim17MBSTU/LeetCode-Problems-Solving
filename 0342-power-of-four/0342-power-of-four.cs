public class Solution {
    public bool IsPowerOfFour(int n) {
        // here n must be positive integer 
        // n&n-1 == 0 then this number is power of 2 
        /*      8 = 1000
                7 = 0111
            -----------------
                0 = 0000

        */
        // n & 0x55555555 means hexadecimal representation
        // power of 4 mesna even postion any bit must be set bit
        // ex: 16 = 10000 
        // 10101010101010101010101 = means even postion now we (n&0x55555555) != 0 means power of 4
        
        if(n >= 1 && (n&(n-1)) == 0 && (n& 0x55555555) != 0)return true;
        return false;
    }
}