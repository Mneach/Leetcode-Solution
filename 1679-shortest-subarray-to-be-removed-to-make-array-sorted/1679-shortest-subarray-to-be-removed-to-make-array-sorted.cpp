class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int postfix = 0;
        int prefix = 0;
        int middle = arr.size();
        int index = 0;

        // find prefix 
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] <= arr[i + 1]) index++;
            else break;
        }

        prefix = (arr.size() - index) - 1;

        // find postfix
        index = 0;
        for(int i = arr.size() - 1; i >= 1; i--){
            if(arr[i] >= arr[i - 1]){
                index++;
            }else{
                break;
            }
        }

        // cout << "postfix index = " << postfix << endl;

        postfix = (arr.size() - index) - 1;

        // find middle
        int rightIndex = 0;
        for(int i = arr.size() - 1; i >= 1; i--){
            if(arr[i] < arr[i - 1]){
                rightIndex = i;
                break;
            }
        }

        int leftIndex = 0;
        while(leftIndex < rightIndex && leftIndex < arr.size() && rightIndex < arr.size()){
            if(arr[leftIndex] <= arr[rightIndex]){
                int formula = (rightIndex - leftIndex) - 1;

                // cout << leftIndex << " " << rightIndex << " " << formula << endl;
                middle = min(middle, formula);
                leftIndex++;
                if(leftIndex < arr.size() && arr[leftIndex] < arr[leftIndex - 1]) break;
            }else{
                while(leftIndex < arr.size() && rightIndex < arr.size() && arr[leftIndex] > arr[rightIndex]){
                    rightIndex++;
                }
            }
        }

        // cout << prefix << " " << postfix << " " << middle << endl;

        return min(prefix, min(postfix, middle));
    }
};