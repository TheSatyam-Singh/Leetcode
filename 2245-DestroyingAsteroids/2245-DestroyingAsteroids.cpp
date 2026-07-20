// Last updated: 20/07/2026, 11:26:19
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long currentMass=mass;
        for (int i : asteroids) {
            if (currentMass<i) {
                return false;
            }
            currentMass+=i;
        }
        return true;
    }
};