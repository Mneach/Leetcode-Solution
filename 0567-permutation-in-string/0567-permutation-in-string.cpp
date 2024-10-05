class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> ump;
        unordered_map<char,int> temp;
    
        for(auto data : s1){
            ump[data]++;
        }

        int count = 0;
        int left = 0;
        for(int right = 0; right < s2.length(); right++){
            if(ump[s2[right]] == 0){
                while(left <= right){
                    if(temp[s2[left]] > 0) temp[s2[left]]--;
                    left++;
                }

                if(count >= s1.length()){
                    cout << right << " " << count << endl;
                    return true;
                }
                count = 0;
            }else{
                temp[s2[right]]++;
                if(temp[s2[right]] > ump[s2[right]]){
                    while(temp[s2[right]] > ump[s2[right]]){
                        temp[s2[left]]--;
                        left++;
                    }

                    count = (right - left) + 1;
                }else{
                    count++;
                }

                if(count >= s1.length()){
                    return true;
                }                
            }
        }

        if(count >= s1.length()) return true;

        return false;
    }
};