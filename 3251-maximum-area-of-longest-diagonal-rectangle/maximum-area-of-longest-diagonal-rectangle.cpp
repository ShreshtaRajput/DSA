class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int currLen = 0;
        int currWid = 0;
        int currDia = 0;
        int currArea = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int len = dimensions[i][0];
            int wid = dimensions[i][1];

            int dia = pow(len, 2) + pow(wid, 2);

            if (dia > currDia) {
                currDia = dia;
                currLen = len;
                currWid = wid;
                currArea = currLen * currWid;
            }else if(dia == currDia){
                currArea = max(currArea, len * wid);
            }
        }

        return currArea;
    }
};