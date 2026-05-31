class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long curr = mass;
        for(int i = 0; i < asteroids.size(); i++){
            if(curr >= asteroids[i]){
                curr += asteroids[i];
            }else{
                return false;
            }
        }

        return true;
    }
};