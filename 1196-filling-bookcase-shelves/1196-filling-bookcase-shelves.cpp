class Solution {
public:

    int recursive(vector<vector<int>>& books, int shelfWidth, int index, unordered_map<int,int> &ump){

        if(index == books.size()){
            return 0;
        }

        if(ump[index] > 0){
            return ump[index];
        }

        int res = INT_MAX;
        int maxHeight = 0;
        int currentWidth = shelfWidth;

        for(int i = index; i < books.size(); i++){
            int width = books[i][0];
            int height = books[i][1];

            if(currentWidth < width){
                break;
            }

            currentWidth -= width;
            maxHeight = max(maxHeight, height);
            res = min(res, recursive(books,shelfWidth, i + 1, ump) + maxHeight);
        }

        ump[index] = res;
        return ump[index];
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        unordered_map<int,int> ump;

        return recursive(books, shelfWidth, 0, ump);
    }
};