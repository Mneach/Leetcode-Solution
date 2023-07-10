/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inOrder(TreeNode* root, vector<int>& arr){
        if(root){
            inOrder(root->left, arr);
            arr.push_back(root->val);
            inOrder(root->right, arr);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> arr1, arr2;
        
        inOrder(root1, arr1);
        inOrder(root2, arr2);
        
        int indexArr1, indexArr2;
        indexArr1 = indexArr2 = 0;
        int indexResult = 0;
        
        vector<int> result(arr1.size() + arr2.size());
        while(indexArr1 < arr1.size() && indexArr2 < arr2.size()){
           int temp;
            
            if(arr1[indexArr1] <= arr2[indexArr2]){
                temp = arr1[indexArr1];
                indexArr1++;
            }else if(arr2[indexArr2] < arr1[indexArr1]){
                temp = arr2[indexArr2];
                indexArr2++;
            }
            
            result[indexResult] = temp;
            indexResult++;
            cout << indexResult << " " << indexArr1 << " " << indexArr2 << endl;
        }
       
        while(indexArr1 < arr1.size()){
            result[indexResult] = arr1[indexArr1];
            indexResult++;
            indexArr1++;
        }
        
        while(indexArr2 < arr2.size()){
            result[indexResult] = arr2[indexArr2];
            indexResult++;
            indexArr2++;
        }
        
        return result;
    }
};