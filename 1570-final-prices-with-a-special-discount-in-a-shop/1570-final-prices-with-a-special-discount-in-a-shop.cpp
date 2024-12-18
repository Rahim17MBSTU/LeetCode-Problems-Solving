class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>>st;
        for(int i = 0 ; i < prices.size();i++){ // Monotonic Stack apply to solve this problem 
            if(!st.empty() && st.top().first >= prices[i]){
                
                while(!st.empty()&&st.top().first>= prices[i]){
                    int indx = st.top().second;
                    st.pop();
                    prices[indx] -= prices[i];
                }
                st.push({prices[i],i});
                
            }else{
               st.push({prices[i],i});
            }
        }
        return prices;
    }
};