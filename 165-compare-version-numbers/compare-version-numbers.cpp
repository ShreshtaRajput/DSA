class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();

        int i = 0; int j = 0;

        int str1Start = 0;
        int str1End = 0;

        while(i < m || j < n){
            int i1 = i;
            while(i1 < m && version1[i1] != '.') i1++;
            int j1 = j;
            while(j1 < n && version2[j1] != '.') j1++;

            int num1 = 0, num2 = 0;
            if(i < m) num1 = stoi(version1.substr(i, i1 - i));
            if(j < n) num2 = stoi(version2.substr(j, j1 - j));

            if(num1 > num2) return 1;
            if(num1 < num2) return -1;

            i = i1 + 1;
            j = j1 + 1;
        }

        return 0;
    }
};