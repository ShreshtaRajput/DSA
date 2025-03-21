class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> available(
            supplies.begin(),
            supplies.end());
        vector<string> result;
        bool progress = true;

        while (progress) {
            progress =
                false;
            for (size_t i = 0; i < recipes.size(); i++) {
                if (available.count(recipes[i]))
                    continue;

                bool canMake = true;
                for (const string& ing : ingredients[i]) {
                    if (available.find(ing) ==
                        available.end()) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    available.insert(
                        recipes[i]);
                    result.push_back(recipes[i]);
                    progress = true;
                }
            }
        }

        return result;
    }
};