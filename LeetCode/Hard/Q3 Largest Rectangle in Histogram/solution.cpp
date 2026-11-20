class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); //future cleanup
        std::stack<int> mono;
        int largest = 0;

        for(int i = 0; i<heights.size(); i++){ //going through each bar
            int height = heights[i];
            int width;
            if(!mono.empty())
                width = mono.top()-1;
            while(!mono.empty()){ //comparing againsts the stack elements

                if(heights[i]<heights[mono.top()]){ //the only condition we need to check
                    
                    height = heights[mono.top()];
                    
                    mono.pop();

                    width = mono.empty()?i: i - mono.top()-1;
                    largest = max(largest, height*width);
                    
                }
                else{ //just push the current bar and move on
                    break;
                }
            }
            mono.push(i);
        }


        return largest;
    }
};