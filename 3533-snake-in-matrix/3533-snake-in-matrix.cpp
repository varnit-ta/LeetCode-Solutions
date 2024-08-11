class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;

        for (int i = 0; i < commands.size(); i++){
            if (commands[i] == "UP"){
                x -= 1;
            }else if (commands[i] == "DOWN"){
                x += 1;
            }else if (commands[i] == "RIGHT"){
                y += 1;
            }else if (commands[i] == "LEFT"){
                y -= 1;
            }
        }
        return (x*n + y);
    }
};