class Solution {
private: 
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {

        // Character count array
        int count1[26] = {0};

        for(int i = 0; i < s1.length(); i++){
            char index = s1[i] - 'a';
            count1[index]++;
        }

        // traverse s2 for window size of length of s1
        int count2[26] = {0};
        int windowSize = s1.length();
        int i = 0;

        while(i < windowSize && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if( checkEqual(count1,count2) ){
            return 1;
        }

        // Update arrray for previous value
        while( i < s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            int index2 = oldChar - 'a';
            count2[index2]--;

            i++;

            if(checkEqual(count1, count2)){
                return 1;
            }
        }
        return 0;
    }
};