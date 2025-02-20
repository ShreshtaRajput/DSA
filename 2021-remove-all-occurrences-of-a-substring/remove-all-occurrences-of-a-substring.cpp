class Solution {
public:
    string removeOccurrences(string s, string part) {
        // MY APPROACH
        // int string_size = s.size();
        // int part_size = part.size();
        // while(string_size >= part_size){
        //     bool found = false;
        //     for(int i = 0; i <= string_size - part_size; i++){
        //         string temp_str = s.substr(i, part_size);
        //         if(part.compare(temp_str) == 0){
        //             s.erase(i, part_size);
        //             string_size = s.size();
        //             found = true;
        //             i = -1;
        //         }
        //     }
        //     if(!found) break;
        // }
        // return s;

        // OPTIMAL SOLUTION
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};