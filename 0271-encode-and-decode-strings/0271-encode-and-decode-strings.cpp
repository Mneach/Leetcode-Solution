class Codec {
public:
    
    
    vector<int> range_index;
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = "";
        
        for(auto data : strs){
            range_index.push_back(data.size());
            encoded_string += data;
        }
        
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
       vector<string> decoded_string;
        
       int start = 0;
       for(auto index : range_index){
           string temp = s.substr(start, index);
           decoded_string.push_back(temp);
           start += index;
       }
        
       return decoded_string;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));