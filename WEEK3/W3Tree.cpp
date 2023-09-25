#include<bits/stdc++.h>
using namespace std;

typedef class TreeNode* Trnode;
class TreeNode {
public:
	int value;
	TreeNode* left;
	TreeNode* right; 
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int N, vector<pair<int, int>>& edges) {
    vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; ++i) {
        nodes[i] = new TreeNode(i + 1);
    }

    TreeNode* root = nodes[0];
    for (const auto& edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;
        if (nodes[u]->left == nullptr) {
            nodes[u]->left = nodes[v];
        } else {
            nodes[u]->right = nodes[v];
        }
    }
    return root;
}
int calculateHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}
void preorderTraversal(TreeNode* node, vector<int>& result) {
    if (node) {
        result.push_back(node->value);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }
}
void postorderTraversal(TreeNode* node, vector<int>& result) {
    if (node) {
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->value);
    }
}
// DUYET TRUNG TU
  //     1
  //    / \
  //   2   3
  //  / \
  // 4   5
  // -> 4 2 5 1 3
vector<Trnode> ans_child;
vector<Trnode> ans_parent;
int tmp = 0;
void inorder(TreeNode* node, vector<Trnode>& ans_child, vector<Trnode>& ans_parent) {
	if(node) {
		inorder(node->left, ans_child, ans_parent);
		
		++tmp;
		if(tmp % 2 == 0) {
			ans_parent.push_back(node);
		} else {
			ans_child.push_back(node);
		}
		inorder(node->right, ans_child, ans_parent);
	}
}
int cnt = 0;
int isBinaryTree(TreeNode* node) {
    // if (node == nullptr) {
    //     return true;
    // }

    // if (node->value > min_val && node->value < max_val) {
    //     return (isBinaryTree(node->left, min_val, node->value) &&
    //     	isBinaryTree(node->right, node->value, max_val));
    // } else {
    //     return false;
    // }
    ++cnt;
	if(node->left) {
		isBinaryTree(node->left);
	}
	if(node->right) {
		isBinaryTree(node->right);
	}
	return cnt;
}
int main()
{  
	int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);

    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    TreeNode* root = buildTree(N, edges);
    int height = calculateHeight(root);

    vector<int> preorderResult;
    preorderTraversal(root, preorderResult);

    vector<int> postorderResult;
    postorderTraversal(root, postorderResult);


    cout << height - 1 << endl;
    for (int val : preorderResult) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : postorderResult) {
        cout << val << " ";
    }
    cout << endl;

    if (isBinaryTree(root) == N) {

        cout << "IS BINARY TREE" << endl;

    } else {

        cout << "NOT BINARY TREE" << endl;
    }

    int i_1 = 0;
    int i_2 = 0;
    inorder(root, ans_child, ans_parent);
    vector<Trnode> ans_inorder;
    for(int i = 1; i <= N; i++) {
    	if(i % 2 == 0) {
    		ans_inorder.push_back(ans_parent[i_1]);
    		++i_1;
    	} else {
    		ans_inorder.push_back(ans_child[i_2]);
    		++i_2;
    	}
    }

    for(auto it : ans_inorder) {
    	cout << it->value << " ";
    } 
	return 0;
}
//Câu 2 :
    //Draw the binary tree
    //     2
    //    / \
    //   1   10
    //      /  \
    //     6   13
    //    / \    \
    //   3   8    20
    //      /
    //     7
	// Draw the binary search tree after inserting values : 14, 0 , 35.
    //     2
    //    / \
    //   1   10
    //  /   /  \
    // 0   6    13
    //    / \     \
    //   3   8     20
    //      /     /  \
    //     7     14   35
    //              
    //              

	//Draw the binary tree after deleting 6, 13, 35
    //     2
    //    / \
    //   1   10
    //  /   /  \
    // 0   7    20
    //    / \    /
    //   3   8	14
    //      
    //     
// Câu 3: 2 1 10 6 3 8 7 13 20
// -Draw the heap tree
// 				20
// 			  /   \ 
// 			 13    10
// 			/ \   / \
// 		   6   3  8  7
// 		  / \
// 		  1  2
// -Draw the heap tree after inserting values : 14
// 				20
// 			  /   \ 
// 			 14    10
// 			/ \   / \
// 		   6   13  8  7
// 		  / \  /
// 		  1  2 3 
// -Draw the heap tree after inserting values : 0
// 				20
// 			  /   \ 
// 			 14    10
// 			/ \   / \
// 		   6   13  8  7
// 		  / \  / \
// 		  1  2 3  0
// -Draw the heap tree after inserting values : 35
// 				35
// 			  /    \ 
// 			 14     20
// 			/ \     /  \
// 		   6   13   10   7
// 		  / \  / \  /
// 		  1  2 3  0 8

// -Draw the heap tree after deleting : 6 
// 				35
// 			  /    \ 
// 			 14     20
// 			/ \     /  \
// 		   8   13   10   7
// 		  / \  / \  
// 		  1  2 3  0 
// -Draw the heap tree after deleting : 13
// 				35
// 			  /    \ 
// 			 14     20
// 			/ \     /  \
// 		   8   3   10   7
// 		  / \  /   
// 		  1  2 0   
// -Draw the heap tree after deleting : 35
// 				 20
// 			  /    \ 
// 			 14      10
// 			/ \     /  \
// 		   8   3   0   7
// 		  / \     
// 		  1  2    
// Câu 4:
// Sau khi sử dụng web random.org thu được S1: 13 7 14 17 3 2 18 6 10 15
// Insert elements from S1 to a binary search tree one by one and draw the binary search
// tree after each step.

// 					13
// 				  /    \
// 				7       14
// 			  /  \         \
//              3    10       17
//             / \			/    \
//            2   6		   15     18

// Write out the procedure to find and remove the maximum element from binary search
// tree in detail.

// Để tìm ra phần tử có giá trị lớn nhất : 
// -> Nếu ở nốt con bên phải so với nốt gốc thì sẽ đi lên nốt cha gần nhất rồi đi xâu xuống nhánh bên phải cùng
// -> Nếu ở nốt con bên trái so với nốt gốc thì sẽ đi lên nốt gốc rồi đi sâu xuống nhánh bên phải cùng
// Để xóa bỏ phần tử có giá trị lớn nhất :
// Cho nốt cha của nó Node->right = nullptr;

// Write out the procedure to find and remove the minimum element from binary search tree
// in detail.

// Để tìm ra phần tử có giá trị nhỏ nhất : 
// -> Nếu ở nốt con bên phải so với nốt gốc thì sẽ đi lên nốt gốc rồi đi xâu xuống nhánh bên trái cùng
// -> Nếu ở nốt con bên trái so với nốt gốc thì sẽ đi lên nốt cha gần nhất rồi đi sâu xuống nhánh bên trái cùng
// Để xóa bỏ phần tử có giá trị lớn nhất :
// Cho nốt cha của nó Node->left = nullptr;

// Câu 5:
// Use random.org to generate another set of 10 integers from 1-20 (S2).
// - Draw the heap (tree) from S2

// S2: 18 5 15 2 12 7 9 16 4 11
// S1: 13 7 14 17 3 2 18 6 10 15 (Câu 4)
//            18
//          /    \
//         16     15
//        / \     / \
//       12   11 7   9
//      /  \  /
//     2    4 5

// - Insert elements from S1 to this heap one by one and draw the heap after each step.
//              18
//          /        \
//         18         17
//        /   \        / \
//       16     13     14   15
//      /  \    / \   / \   / \
//     12   15  5  11 7  7  9  3
//    / \   / \
//   2   6  4  10


// - Write out the procedure to find and remove the maximum element from binary search
// tree in detail.
// Vì ta đã tạo một Max heap nên phần tử Root sẽ là phần tử lớn nhất.
// Từ tail -> lên nốt cha cho đến khi gặp Root
// Xóa bỏ maximum -> ta sẽ đưa 10 lên thay cho Root
// Và sử dụng thuật toán chìm 10 xuống và đưa phần tử max nổi lên để trở thành 1 cây heap mới.