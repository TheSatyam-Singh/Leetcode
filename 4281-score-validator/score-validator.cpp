class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int wicket=0;
        int runs=0;
        for(int i=0;i<events.size();i++){
            if(wicket==10){
                break;
            }
            if(events[i]=="W"){
                wicket++;
            }
            if(events[i]=="WD" || events[i]=="NB"){
                runs++;
            }
            if(events[i]!="W" && events[i]!="WD" && events[i]!="NB"){
                int x=stoi(events[i]);
                runs+=x;
            }
        }
        return {runs,wicket};
    }
};