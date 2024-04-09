class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_map<int,int> ump;
        
        vector<int> answer;
        
        int temp = 0;
        for(int i = 0; i < A.size(); i++){
            
            int incrementA = 0;
            int incrementB = 0;
            
            ump[A[i]]++;
            ump[B[i]]++;
            
            if(A[i] == B[i]){
                if(ump[A[i]] > 1) incrementA++;
            }else{
                if(ump[A[i]] > 1) incrementA++;
                if(ump[B[i]] > 1) incrementB++;
            }
            
            temp += incrementA + incrementB;
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};