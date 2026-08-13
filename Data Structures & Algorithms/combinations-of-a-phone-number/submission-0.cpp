class Solution {
public:

    // This stores the letters corresponding to each digit.
    // Example: map[3] = "def", map[4] = "ghi".
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    // Backtracking function.
    // idx tells us which digit we are currently processing.
    // curr stores the letters selected so far.
    // ans stores all complete combinations.
    void backtrack(
        string& digits,
        int idx,
        string& curr,
        vector<string>& ans
    ) {

        // If we have processed every digit,
        // curr is now a complete combination.
        if(idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        // Get all possible letters for the current digit.
        string letters = mp[digits[idx]];

        // Try every possible letter for this digit.
        for(char ch : letters) {

            // Choose this letter.
            curr.push_back(ch);

            // Move to the next digit.
            backtrack(digits, idx + 1, curr, ans);

            // Undo our choice so we can try the next letter.
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // If input is empty, there are no combinations.
        if(digits.empty())
            return {};

        // Stores the final answers.
        vector<string> ans;

        // Stores the combination currently being built.
        string curr = "";

        // Start processing from the first digit.
        backtrack(digits, 0, curr, ans);

        return ans;
    }
};