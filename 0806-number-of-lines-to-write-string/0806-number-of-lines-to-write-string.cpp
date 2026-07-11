class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {

        int numLines = 0;
        int lastLineWidth = 0;

        for (int i = 0; i < s.size(); i++) {
            
            if (lastLineWidth + widths[s[i]-'a'] > 100) {
                lastLineWidth = widths[s[i]-'a'];
                numLines++;
            } else lastLineWidth += widths[s[i]-'a'];
        }
        return {numLines+1, lastLineWidth};
    }
};