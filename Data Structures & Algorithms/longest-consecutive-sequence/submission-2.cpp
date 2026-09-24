class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());

        int mcnt = 0;

        for (auto num : mp) {
            // num is the beginning of a sequence
            if (mp.find(num - 1) == mp.end()) {

                int cnt = 0;
                int x = num;

                while (mp.find(x) != mp.end()) {
                    cnt++;
                    x++;
                }

                mcnt = max(mcnt, cnt);
            }
        }

        return mcnt;
    }
};
