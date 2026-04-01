class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& path, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            // i+1 because reuse not allowed
            solve(i + 1, candidates, target - candidates[i], path, result);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, path, result);

        return result;
    }
};
