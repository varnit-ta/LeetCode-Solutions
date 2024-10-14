class Solution 
{
public:
    vector<int> constructRectangle(int area) 
    {
        int s = int(sqrt(area));
        while(area % s != 0) s--;
        return {area/s, s};
    }
};