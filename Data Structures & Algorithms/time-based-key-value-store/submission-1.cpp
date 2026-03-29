class TimeMap {
    unordered_map<string,vector<pair<string,int>>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()){
            return "";
        }
        auto& data = timeMap[key];
        string res = "";
        int l = 0, r = data.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(data[mid].second <= timestamp){
                res = data[mid].first;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return res;
    }
};
