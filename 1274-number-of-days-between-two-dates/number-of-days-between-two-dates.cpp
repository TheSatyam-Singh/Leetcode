class Solution {
public:
    int countDays(int y,int m,int d){
        int days=0;
        for(int i=1971;i<y;i++){
            if(i%400==0 || (i%4==0 && i%100!=0)){
                days+=366;
            }else{
                days+=365;
            }
        }
        vector<int>mday={31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=0;i<m-1;i++){
            days+=mday[i];
        }
        if (m>2&&(y%400==0||(y%4==0&&y%100!=0))){
            days++;
        }
        days+=d;
        return days;
    }
    int daysBetweenDates(string date1, string date2) {
        vector<int>days={31,28,31,30,31,30,31,31,30,31,30,31};
        int y1=stoi(date1.substr(0,4));
        int y2=stoi(date2.substr(0,4));
        int m1=stoi(date1.substr(5,2));
        int m2=stoi(date2.substr(5,2));
        int d1=stoi(date1.substr(8,2));
        int d2=stoi(date2.substr(8,2));
        return abs(countDays(y1,m1,d1) - countDays(y2,m2,d2));
    }
};