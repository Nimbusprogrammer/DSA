class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;//don't think to loop arr[st.top()] like that instead you are storing all inside the stack including element and its span.As stack only has ascending order the span of top most element is will be sum of spans of all lower elements until its bigger that top as eg : 5 , 4 ,3, ,2 here when we do 8 as next element then span of 2 will cover >= 2 then span of 3 will cover that so on so no double counting
    int next(int price) { 
        int span = 1;
        while ( !st.empty() && st.top().first <= price ){
            span+= st.top().second;
            st.pop();
            
        }
        st.push({price , span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */