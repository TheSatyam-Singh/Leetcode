class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free; 
        //smallest room first
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for(int i=0;i<n;i++){
            free.push(i);
        }
        vector<int> visited(n, 0);
        for(auto &it : meetings){
            long long start = it[0];
            long long end  = it[1];
            while(!busy.empty() && busy.top().first <= start){
                // free all room whose meet has ended
                free.push(busy.top().second);
                busy.pop();
            }
            if(!free.empty()){
                //some room is aval
                int room = free.top();
                free.pop();
                visited[room]++;
                busy.push({end, room});
            }
            else{
                //all rooms are busy
                auto [freetime, room] = busy.top();
                busy.pop();
                long long dur = end - start;
                long long newEnd  = freetime + dur;
                visited[room]++;
                busy.push({newEnd, room});
            }
        }
        // find room with max meets
        int ans = 0;
        for(int i=0;i<n;i++){
            if(visited[i] > visited[ans]){
                ans = i;
            }
        }
        return ans;
    }
};