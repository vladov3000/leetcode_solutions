/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

#define MAX_NODES  100000
#define NO_PATH_TO SIZE_MAX
#define len(array) (sizeof(array) / sizeof(*(array)))

size_t get_path_to(TreeNode* root, int val, char* out) {
    if (root == NULL)
        return NO_PATH_TO;
    if (root->val == val)
        return MAX_NODES;
    
    size_t left = get_path_to(root->left, val, out);
    if (left != NO_PATH_TO) {
        out[left - 1] = 'L';
        return left - 1;
    }
    
    size_t right = get_path_to(root->right, val, out);
    if (right != NO_PATH_TO) {
        out[right - 1] = 'R';
        return right - 1;
    }
    
    return NO_PATH_TO;
}

char* getDirections(TreeNode* root, int start, int end){
    static char start_to_root[MAX_NODES];
    static char root_to_end[MAX_NODES];
    static char result[MAX_NODES + 1];
    
    size_t sr_start = get_path_to(root, start, &start_to_root);
    size_t re_start = get_path_to(root, end, &root_to_end);
    
    size_t sr_len = MAX_NODES - sr_start;
    size_t re_len = MAX_NODES - re_start;
    
    size_t prefix = 0;
    while (prefix < sr_len && prefix < re_len) {
        if (start_to_root[sr_start + prefix] != root_to_end[re_start + prefix])
            break;
        prefix++;
    }
    
    size_t result_len = 0;
    memset(result, 'U', sr_len - prefix);
    result_len += sr_len - prefix;
    
    memcpy(result + result_len, root_to_end + re_start + prefix, re_len - prefix);
    result_len += re_len - prefix;
        
    result[result_len] = '\0';
    return result;
}
