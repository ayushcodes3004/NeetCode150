
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return "";

        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int i = 0, j = 0;
        int required = n;
        int mini = INT_MAX;
        int idx = 0;

        while (j < m) {
            if (mp[s[j]] > 0) {
                required--;
            }
            mp[s[j]]--;

            while (required == 0) {
                if (j - i + 1 < mini) {
                    mini = j - i + 1;
                    idx = i;
                }

                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    required++;
                }

                i++;
            }

            j++;
        }

        return mini == INT_MAX ? "" : s.substr(idx, mini);
    }
};
