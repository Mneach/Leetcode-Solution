class Solution {
public:
    
    int findZero(string temp){
        int result = 0;
        for(int i = temp.length() - 1; i >= 0; i++){
            if(temp[i] != '0') break;
            result++;
        }
        
        return result;
    }
    
    int reverse(int x) {
        
        if(x == 0){
            return x;
        }
        
        string temp = to_string(x);
        int index = findZero(temp);
        if(temp[0] == '-'){   
            string bucket = temp.substr(1, temp.length() - 1 - index) ;
            std::reverse(bucket.begin(), bucket.end());
            
            long long int result = stoll(bucket) * -1;
            if(result > INT_MAX || result < INT_MIN) return 0;
            
            return stoll(bucket) * -1;
        }else{
            string bucket = temp.substr(0, temp.length() - index);
            std::reverse(bucket.begin(), bucket.end());
            long long int result = stoll(bucket);
            if(result > INT_MAX || result < INT_MIN) return 0;
            
            
            return stoll(bucket);
        }
        
        
    }
};