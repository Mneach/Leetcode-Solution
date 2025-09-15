/*

How to solve the problem : 

# Using Hash map
1. Put the long url into the hashmap whenever the encode function called
   - hashmap will have key = short url and value is long url
2. everytime the function decode called by the user, we just need to get the long url from the hashmap by using hashmap[key] where key = short url

Time complexity : O(1)

Memory complexity : O(N + M)
N -> the total of function encode called
M -> the total of function decode called

*/

class Solution {
public:

    unordered_map<string,string> hashMap;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hashMap[longUrl] = longUrl; 
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hashMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));