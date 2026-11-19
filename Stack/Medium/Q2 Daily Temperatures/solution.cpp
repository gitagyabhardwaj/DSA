class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size());
        std::stack<int> mono;

        for(int i = 0; i<temperatures.size(); i++){
            while(!mono.empty()){
                if(temperatures[mono.top()]<temperatures[i]){
                    answer[mono.top()] = i - mono.top();
                    mono.pop();
                }
                else{
                    break;
                }
            }
            mono.push(i);
        }

        return answer;
    }
};