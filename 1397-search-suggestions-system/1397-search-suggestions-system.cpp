class Solution {
private:
    bool isValid(string &prefix, string &current) {
        int prefixIndex = 0;
        int currentIndex = 0;

        while (prefixIndex < prefix.length() && currentIndex < current.length()) {
            if (prefix[prefixIndex] != current[currentIndex]) {
                return false;
            }

            prefixIndex++;
            currentIndex++;
        }

        return true;
    }

    int findMostLeftIndex(vector<string>& products, string &prefix) {
        int result = -1;
        int left = 0;
        int right = products.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            string current = products[mid];

            bool valid = false;
            bool moveLeft = false;

            int prefixIndex = 0;
            int currentIndex = 0;

            while (prefixIndex < prefix.size() && currentIndex < current.size()) {
                if (prefix[prefixIndex] != current[currentIndex]) {
                    if (prefix[prefixIndex] < current[currentIndex]) {
                        moveLeft = true;
                    } else {
                        moveLeft = false;
                    }
                    break;
                }

                prefixIndex++;
                currentIndex++;
            }

            if (prefixIndex == prefix.size()) {
                valid = true;
            }

            if (valid) {
                result = mid;
                right = mid - 1;
            } else {
                if (moveLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return result;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> results;

        sort(products.begin(), products.end());

        string prefix = "";
        for (auto c : searchWord) {
            prefix += c;

            int mostLeftIndex = findMostLeftIndex(products, prefix);

            int count = 0;
            vector<string> result;
            
            while (mostLeftIndex < products.size() && count < 3) {
               if (isValid(products[mostLeftIndex], prefix)) {
                    result.push_back(products[mostLeftIndex]);
                    count++;
                    mostLeftIndex++;
               } else {
                    break;
               } 
            } 

            results.push_back(result);
            
        }

        return results;
    }
};