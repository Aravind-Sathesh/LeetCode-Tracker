class Solution {
public:
    int numTilings(int n) {
        long long MOD = 1e9 + 7;
        
        vector <long long> complete (n+1);
        vector <long long> incomplete (n+1) ;
        complete[0] = 1;
        complete[1] = 1;
        incomplete[0] = 0;
        incomplete[1] = 0;

        for (int i=2 ; i<=n ; i++) {
            complete[i] = (complete[i-1] + complete[i-2] + 2*incomplete[i-1]) % MOD;
            
            incomplete[i] = (incomplete[i-1] + complete[i-2]) % MOD;
        }
        return complete[n] % MOD;
    }
};