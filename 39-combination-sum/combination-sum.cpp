class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& path, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(path);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Pick element
        path.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], path, result);
        path.pop_back();

        // Not pick element
        solve(index + 1, candidates, target, path, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        solve(0, candidates, target, path, result);
        return result;
    }
};
