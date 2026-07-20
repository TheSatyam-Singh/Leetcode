// Last updated: 20/07/2026, 10:38:59
class EventManager {
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> eventMap;

public:
    EventManager(vector<vector<int>>& events) {
        for (auto& event : events) {
            int eventId = event[0];
            int priority = event[1];
            eventMap[eventId] = priority;
            pq.push({priority, -eventId});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        eventMap[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [priority, negEventId] = pq.top();
            int eventId = -negEventId;
            pq.pop();
            
            if (eventMap.count(eventId) && eventMap[eventId] == priority) {
                eventMap.erase(eventId);
                return eventId;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */