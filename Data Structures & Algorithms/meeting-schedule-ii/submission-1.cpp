/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()){return 0;}
        int n = intervals.size();
        vector<int> start, end;
        for(const auto& i:intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int end_ptr = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(start[i] < end[end_ptr]){
                count++;
            }else{
                end_ptr++;
            }
        }
        return count;
    }
};
