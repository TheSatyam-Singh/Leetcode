class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startTotal = stoi(startTime.substr(6, 2)) +
                         stoi(startTime.substr(3, 2)) * 60 +
                         stoi(startTime.substr(0, 2)) * 3600;
        int endTotal = stoi(endTime.substr(6, 2)) +
                       stoi(endTime.substr(3, 2)) * 60 +
                       stoi(endTime.substr(0, 2)) * 3600;
        return abs(startTotal - endTotal);
    }
};