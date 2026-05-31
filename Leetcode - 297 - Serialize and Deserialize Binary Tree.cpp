/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 1**2..3**4..5..
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string answer = "";
        answer = answer + to_string(root->val);

        string answer_left = "";
        string answer_right = "";
        if (root->left != nullptr) {
            answer = answer + "*";
            answer_left = serialize(root->left);
        } else {
            answer = answer + ".";
        }

        if (root->right != nullptr) {
            answer = answer + "*";
            answer_right = serialize(root->right);
        } else {
            answer = answer + ".";
        }

        cout << answer + answer_left + answer_right << endl;
        return answer + answer_left + answer_right;
    }

    int get_amount_child(TreeNode* node) {
        if (node == nullptr) {return 0;}
        int answer = to_string((*node).val).size() + 2; 
        if ((*node).left != nullptr) {answer += (get_amount_child((*node).left));}
        if ((*node).right != nullptr) {answer += (get_amount_child((*node).right));}
        return answer; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int value = 0;
        bool neg = false;
        char left_state = ' ';
        char right_state = ' ';
        for (int index = 0; index < data.size(); index++) {
            if (data[index] == '.' || data[index] == '*') {
                if (left_state == ' ') {
                    left_state = data[index];
                } else {
                    right_state = data[index];
                } 
            } else {
                if (left_state != ' ' && right_state != ' ') {
                    break;
                }
                if (data[index] == '-') {
                    neg = true;
                } else {
                    value = value * 10 + (data[index] - '0');
                }
            }
        }
        TreeNode* newNode = new TreeNode(value * (neg ? -1 : 1));
        if (data == "") {
            return nullptr;
        }
        if (left_state == '*') {
            string data_left = data.substr(to_string(value * (neg ? -1 : 1)).size() + 2, data.size() - 1);
            (*newNode).left = deserialize(data_left);
        }
        int amount_left_node = ((*newNode).left != nullptr ? get_amount_child((*newNode).left) : 0);
        if (right_state == '*') {
            string data_right = data.substr(amount_left_node + to_string(value * (neg ? -1 : 1)).size() + 2, data.size() - 1);
            (*newNode).right = deserialize(data_right);
        }
        return newNode; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
