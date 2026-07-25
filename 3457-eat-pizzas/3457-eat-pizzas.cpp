class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        
        int total_days = n / 4;
        int odd_days = (total_days + 1) / 2;
        int even_days = total_days / 2;
        
        long long sum = 0;
        int j = n - 1;
        
        for (int i=0 ; i<odd_days ; i++,j--) sum += pizzas[j];
        
        j--;
        for (int i=0 ; i<even_days ; i++,j-=2) sum += pizzas[j];
        
        return sum;
    }
};
