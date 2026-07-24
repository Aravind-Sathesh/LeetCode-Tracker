class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        vector <int> A, B;

        if (n<=2) return false;
        char prev = colors[0];
        int cnt=1;
        colors.push_back(colors[n-1]=='A' ? 'B' : 'A');
        for (int i=1 ; i<n+1 ; i++) {
            if (prev == colors[i]) {
                cnt++;
            } else {
                if (colors[i]=='B') {
                    A.push_back(cnt);
                } else {
                    B.push_back(cnt);
                }
                cnt=1;
            }
            prev = colors[i];
        }

        int countA=0 , countB=0 ;
        for (int cA : A) if (cA >=3 ) countA+=(cA-2);
        for (int cB : B) if (cB >=3 ) countB+=(cB-2);

        return (countA+countB>0 ? countA>countB : false);

    }
};