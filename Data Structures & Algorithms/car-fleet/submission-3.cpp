class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        double max_time = 0;
        int fleet = 0;
        for(const auto& car : cars){
            double time = (double)(target - car.first)/car.second;
            if(time > max_time){
                fleet++;
                max_time = time;
            }
        }
        return fleet;

    }
};
