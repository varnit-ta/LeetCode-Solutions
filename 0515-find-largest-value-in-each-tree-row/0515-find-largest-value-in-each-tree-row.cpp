class Solution {
public:
    vector<vector<int>> nodes;

    void createVector(TreeNode* root, int level){
        if (root != NULL){
            vector<int> node;
            node.push_back(root->val);
            node.push_back(level);
            nodes.push_back(node);
            createVector(root->left, level + 1);
            createVector(root->right, level + 1);
        }
    }

    static bool sortcol(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        createVector(root, 1);
        sort(nodes.begin(), nodes.end(), sortcol);

        int level;

        if (nodes.size() > 0){
            level = nodes[0][1];
            result.push_back(nodes[0][0]);
        }
        
        for (int i = 0; i < nodes.size(); i++){
            //cout << nodes[i][0] << endl;

            if (nodes[i][1] != level){
                level = nodes[i][1];
                result.push_back(nodes[i][0]);
            }else if (result.back() < nodes[i][0]){
                result.pop_back();
                result.push_back(nodes[i][0]);
            }
        }

        return result;
    }
};