#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define LOG(x) cout<<x<<endl;


using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<i64, i64> pi64;

struct Node{
    int value;
    Node * left;
    Node * right;
};

class BST{
    public:
        Node * root;

        BST(){
            root = NULL;
        }

        void insert(int value, Node * current){
            Node * node = new Node;
            if(isEmpty()){
                node->value = value;
                node->left = NULL;
                node->right = NULL;
                root = node;
            }else{
                node->value = value;
                node->left = NULL;
                node->right = NULL;
                if(node->value > current->value){
                    if(current->right != NULL){
                        current = current->right;
                        insert(value,current);
                    }else{
                        current->right = node;
                        return;
                    }
                }else{
                    if(current->left != NULL){
                        current = current->left;
                        insert(value,current);
                    }else{
                        current->left = node;
                        return;
                    }
                }
            }
        }

        void print(Node * current){

        }

        bool isEmpty(){
            return (root == NULL);
        }
};



int main(){
    ios::sync_with_stdio(false);

    BST * tree = new BST();

    tree->insert(10, tree->root);
    tree->insert(20, tree->root);
    tree->insert(25, tree->root);

    tree->print(tree->root);


    return 0;
}
