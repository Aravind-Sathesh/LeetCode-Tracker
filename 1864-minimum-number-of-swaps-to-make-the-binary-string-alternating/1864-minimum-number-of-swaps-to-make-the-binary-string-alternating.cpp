class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        vector <char> base1;
        vector <char> base2;

        int one=0, zero=0;
        for (int i=0 ; i<n ; i++) {
            base1.push_back(i%2);
            base2.push_back(i%2==0);
            one+=(s[i]-'0'==1);
            zero+=(s[i]-'0'==0);
        }
        if (zero-one>1 || zero-one<-1) return -1;

        int cnt1=0 , cnt2=0;
        for (int i=0 ; i<n ; i++) {
            cnt1+=(s[i]-'0'!=base1[i]);
            cnt2+=(s[i]-'0'!=base2[i]);
        }

        int minCount = min(cnt1, cnt2);
        if (cnt1%2) minCount = cnt2;
        if (cnt2%2) minCount = cnt1;
        cout << cnt1 << " " << cnt2;
        if (minCount%2) return -1;
        return minCount/2;
    }
};