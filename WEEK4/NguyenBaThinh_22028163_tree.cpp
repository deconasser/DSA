#include <iostream>
using namespace std;

// Một Node trong cây
typedef struct Node* node;
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;
    Node* next;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;

public:
    Node() {
        data = 0;
        fatherNode = nullptr;
        next = nullptr;
        firstChild = nullptr;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data, node parent) {
        this->data = data;
        fatherNode = parent;
        firstChild = nullptr;
        next = nullptr;
    }

    int NumOfChild() {
        int cnt = 0;
        node tmp = firstChild;
        while(tmp != nullptr) {
            ++cnt;
            tmp = tmp->next;
        }
        return cnt;
    }
    bool isNodeBST() {
        if(this->NumOfChild() > 2) return false;
        if(this->NumOfChild() == 2) {
            if(this->firstChild->data > this->firstChild->next->data || this->data < this->firstChild->data || this->data > this->firstChild->next->data) return false;
        }
        return true;
    }

    friend class Tree; // Có quyền truy cập đến thành phần private và protected của lớp Node
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
    int cnt = 0;
public:
    Tree() {
        // ...
        root = nullptr;
    }

    node getRoot() {
        return root;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    node Find(node x, int data) {
        if(x) {
            if(x -> data == data) return x;
            node tmp = Find(x->firstChild, data);
            if(tmp) return tmp;
            node tmp2 = Find(x->next, data);
            if(tmp2) return tmp2;
        }
        return nullptr;
    }
    
    void setCNT(int cnt) {
        this->cnt = cnt;
    }

    //Insert 1 Node mới vào Tree
    bool insert(int father, int data) {
        if(root == NULL) {
            root = new Node(father, NULL);
        }
        node tmp = Find(root, father);
        if(tmp == NULL) return false;   
        node p = tmp->firstChild;
        node ins = new Node(data, tmp);
        if(p == NULL) tmp->firstChild = ins;
        else {
            if(p->data == data) return false;
            // Chèn node ins vào list các node child của father
            while(p->next) {
                if(p->data == data) return false;
                p = p->next;
            }
            p->next = ins;  
        }
        return true;
    }
    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int CntChild(node x) {
        if(x) {
            ++cnt;
            CntChild(x->firstChild);
            CntChild(x->next);
        }
        return cnt;
    }
    int remove(int data) {
        int ans = 0;
        node tmp = Find(root, data);
        if(!tmp) return 0;
        else {
            node leaf = tmp->firstChild;
            node faNode = tmp->fatherNode;
            if(!leaf) {
                ++ans;
                node p = new Node();
                p->next = faNode->firstChild;
                while(p->next->data != data) {
                    p = p->next;
                }
                p->next = p->next->next;
            } else {
                ans = ans + CntChild(tmp);
                tmp = NULL;
            }
        }
        return ans;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(node x) {
        if (!x) return;
        cout << x -> data << " ";
        preorder(x -> firstChild);
        preorder(x -> next);
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(node x) {
        if (!x) return;
        postorder(x -> firstChild);
        postorder(x -> next);
        cout << x -> data << " ";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if(!root) return false;
        node tmp = root;
        while(tmp) {
            if(tmp->NumOfChild() > 2) return false;
            while(tmp->firstChild) {
                tmp = tmp->firstChild;
                if(tmp ->NumOfChild() > 2) return false;
            }
            if(tmp->next) {
                tmp = tmp->next;
                if(tmp ->NumOfChild() > 2) return false;
            }
            if(!(tmp->firstChild)) {
                while(!(tmp->next) && tmp != root) {
                    tmp = tmp->fatherNode;
                }
                tmp = tmp->next;
            }

        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        if(!this->isBinaryTree()) return false;
        else {
            node tmp = root;
            while(tmp) {
                if(!tmp->isNodeBST()) return false;
                while(tmp->firstChild) {
                    tmp = tmp ->firstChild;
                    if(!tmp->isNodeBST()) return false;
                }
                if(tmp->next) {
                tmp = tmp ->next;
                if(!tmp->isNodeBST()) return false;
                }
                if(!(tmp->firstChild)) {
                    while(!(tmp->next) && tmp != root) {
                        tmp = tmp->fatherNode; 
                    }
                    tmp = tmp->next;
                }
            }   
        }
        return true;
    }

    // Hàm kiểm tra cây max-heap
    bool isNodeHeap(node x) {
        if(x->NumOfChild() > 2) return false;

        if(x->NumOfChild() == 2) {
            if(x->data > x->firstChild->data || x->data > x->firstChild->next->data) return true;
        }
        if(x->NumOfChild() == 1 && depth(x->data) == height() - 1 && x->firstChild->next == NULL) {

            return true;
        }
        if(x->firstChild == NULL && depth(x->data) == height()) {
            return true;
        }
        return false;
    }

    bool isMaxHeapTree() {

        if(!root) return false;
        node tmp = root;
        while(tmp) {
            while(tmp->firstChild) {
                tmp = tmp->firstChild;
                if(!(isNodeHeap(tmp))) return false;
            }
            if(tmp->next) {
                tmp = tmp->next;
                if(!(isNodeHeap(tmp))) return false;
            }
            if(!(tmp->firstChild)) {
                while(!(tmp->next) && tmp != root) {
                    tmp = tmp->next;
                }
                tmp = tmp->next;
            }
        }
        return true;
    }

    void inorder(node x) {
        if (isBinaryTree() == false) {
            cout << "Not a binary tree" << endl;
            return;
        }
        if (!x) return;
        inorder(x -> firstChild);
        cout << x -> data << " ";
        if (x->firstChild) inorder(x -> firstChild -> next);
    }

    // Hàm trả về độ cao của cây
    int height() {
        if (!root) return -1;
        int d,h = 0;
        node tmp = root;
        while (tmp) {
            while (tmp -> firstChild) {
                tmp = tmp -> firstChild;
            }
            d = depth(tmp->data);
            if (d >h) h = d;
            if (tmp -> next) {
                tmp = tmp -> next;
            }
            // if no child -> leaf node -> traverse up -> go to next (traverse right)
            if (!(tmp -> firstChild)){
                while (!(tmp -> next) && tmp != root) {
                    tmp = tmp -> fatherNode;
                }
                tmp = tmp -> next;
            }
        }

        return h;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        node x = Find(root, data);
        if (!x) return -1;
        int d = 0;
        while (x -> fatherNode) {
            x = x -> fatherNode;
            d++;
        }
        return d;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        if (!root) return 0;
        int leaves = 0;
        node tmp = root;
        while (tmp) {
            while (tmp -> firstChild) {
                tmp = tmp -> firstChild;
            }
            leaves ++;
            // move to next sibling and continue traverse down
            if (tmp -> next) {
                tmp = tmp -> next;
            }
            // if no child -> leaf node -> traverse up -> go to next (traverse right)
            if (!(tmp -> firstChild)){
                while (!(tmp -> next) && tmp != root) {
                    tmp = tmp -> fatherNode;
                }
                tmp = tmp -> next;
            }
        }

        return leaves;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        node tmp = root;
        int mx = tmp->data;
        while (tmp) {
            if (tmp->data > mx) mx = tmp->data;
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
                if (tmp->data > mx) mx = tmp->data;
            }
            if (tmp->next) {
                tmp = tmp->next;
                if (tmp->data > mx) mx = tmp->data;
            }
            if (!(tmp->firstChild)) {
                while (!(tmp->next) && tmp != root) {
                    tmp = tmp->fatherNode;
                }
                tmp = tmp->next;
            }
        }
        return mx;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        Node* tmp = root;
        int mx = 0;
        while (tmp) {
            if (tmp->NumOfChild() > mx) mx = tmp->NumOfChild();
            while (tmp -> firstChild) {
                tmp = tmp -> firstChild;
                if (tmp->NumOfChild() > mx) mx = tmp->NumOfChild();
            }
            if (tmp -> next) {
                tmp = tmp -> next;
                if (tmp->NumOfChild() > mx) mx = tmp->NumOfChild();
            }
            if (!(tmp -> firstChild)) {
                while (!(tmp ->next) && tmp != root) {
                    tmp = tmp -> fatherNode;
                }
                tmp = tmp -> next;
            }
        }

        return mx;
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree* tree = new Tree();
    for (int i = 1; i <= 30; i++) {
        tree -> insert(1, i+1);

    }

    // cout << tree->remove(29) << endl;
    // tree->postorder(tree->getRoot());
    

    return 0;
}