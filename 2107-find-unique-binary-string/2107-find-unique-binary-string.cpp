class Solution {
public:

    string recursive(unordered_map<string, int> ump, string current, int currentIndex){
        if(currentIndex >= current.length()){
            return ump[current] > 0 ? "" : current;
        }

        if(ump[current] == 0){
            return current;
        }

        string temp = current;
        for(int i = currentIndex; i < current.length(); i++){
            if(temp[i] == '1'){
                temp[i] = '0';
            }else{
                temp[i] = '1';
            }

            string res =  recursive(ump, temp, i + 1);
            if(res != "") return res;

            if(temp[i] == '1'){
                temp[i] = '0';
            }else{
                temp[i] = '1';
            }            
        }

        return current;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string current = "";
        unordered_map<string, int> ump;

        int total = nums[0].length();

        for(auto data : nums){
            ump[data]++;
        }

        for(int i = 0; i < total; i++) current += '0';
        
        return recursive(ump, current, 0);
    }
};