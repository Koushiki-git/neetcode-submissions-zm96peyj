class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        unordered_map<char, int> freq;

        // Frequency of chars
        for (char ch : chars) {
            freq[ch]++;
        }

        int ans = 0;

        for (string word : words) {

            unordered_map<char, int> temp = freq;

            bool possible = true;

            for (char ch : word) {

                temp[ch]--;

                if (temp[ch] < 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans += word.size();
            }
        }

        return ans;
    }
};