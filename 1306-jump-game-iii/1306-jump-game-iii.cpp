class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector <int> vis (n, 0);
        int i = start;

        queue <int> q;
        q.push(i);

        while (!q.empty()) {
            i = q.front();
            q.pop();

            vis[i] = 1;
            if (arr[i] == 0) return true;

            int left = i-arr[i];
            int right = i+arr[i];
            if (left>=0 && !vis[left]) q.push(left);
            if (right<n && !vis[right]) q.push(right);
        }
        return false;
    }
};