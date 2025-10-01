
/*

How to solve the problem : 

# Using Two Pointer Technique
1. To make is easier, we can swap s1 with s2, if s2.length() > s1.length()
2. get all words from s1 and s2
   - the reason is because, there is an edge cases where s1 and s2 only have 1 word
   - if s1 and s2 only have 1 word, its really hard to determine if the answer is valid or not
3. initialize left and right pointer for those sentence
4. there are 3 posibillities
   - append the word in the front
   - append the word in the back
   - append the word in the middle
   - all of those possibilities have same pattern, where l2 > r2

Time Complexity : O(N + M)
N -> length of sentence1
M -> length of s2

Memory Complexity : O(K + P)
K -> total words in sentence 1
P -> total words in sentence 2


*/

class Solution
{
    private:
        vector<string> getWords(string s)
        {
            vector<string> result;
            string temp = "";

            for (auto c: s)
            {
                if (c == ' ')
                {
                    result.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += c;
                }
            }

            result.push_back(temp);

            return result;
        }
    public:
        bool areSentencesSimilar(string sentence1, string sentence2)
        {
            if (sentence1.length() < sentence2.length())
            {
                swap(sentence2, sentence1);
            }

            vector<string> s1 = getWords(sentence1);
            vector<string> s2 = getWords(sentence2);

            int l1 = 0;
            int r1 = s1.size() - 1;
            int l2 = 0;
            int r2 = s2.size() - 1;

           	// move the left poinetr
            while (l1 < s1.size() && l2 < s2.size() && s1[l1] == s2[l2])
            {
                l1++;
                l2++;
            }

           	// move the right pointer
            while (r1 >= 0 && r2 >= 0 && s1[r1] == s2[r2])
            {
                r1--;
                r2--;
            }

            return l2 > r2;
        }
};