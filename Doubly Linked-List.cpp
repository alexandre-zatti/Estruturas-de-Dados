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
    Node * next;
    Node * prev;
};

class DBL{
    public:
        Node * front;
        Node * back;

        DBL(){
            front = NULL;
            back = NULL;
        }

        ~DBL(){
           while(!isEmpty()){
               popFront();
           }
        }

        void pushFront(int value){
            Node * node = new Node;
            if(isEmpty()){
                node->value = value;
                node->next = NULL;
                node->prev = NULL;
                front = node;
                back = node;
            }else{
                node->value = value;
                node->prev = front;
                node->next = NULL;
                front->next = node;
                front = node;
            }
        }

        void pushBack(int value){
            Node * node = new Node;
            if(isEmpty()){
                node->value = value;
                node->next = NULL;
                node->prev = NULL;
                front = node;
                back = node;
            }else{
                node->value = value;
                node->prev = NULL;
                node->next = back;
                back->prev = node;
                back = node;
            }
        }

        void popFront(){
            Node * aux = new Node;
            aux = front;
            front = front->prev;
            front->next = NULL;
            delete aux;
        }

        void popBack(){
            Node * aux = new Node;
            aux = back;
            back = back->next;
            back->prev = NULL;
            delete aux;
        }

        void searchDelete(int value){
            Node * current = new Node;
            current = front;
            while(current != NULL){
                if(current->value == value) {
                    if (current == front) {
                        current->prev->next = NULL;
                        front = current->prev;
                    }
                    else if (current == back) {
                        current->next->prev = NULL;
                        back = current->next;
                    }
                    else{
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                    }
                    break;
                }else{
                    current = current->prev;
                }
            }
            delete current;
        }

        void printBackToFront(){
            Node * current = new Node;
            current = back;
            while(current != NULL){
                LOG(current->value);
                current = current->next;
            }
            delete current;
        }

        void printFrontToBack(){
            Node * current = new Node;
            current = front;
            while(current != NULL){
            LOG(current->value);
            current = current->prev;
            }
            delete current;
        }

        bool isEmpty(){
            return(front == NULL && back == NULL);
        }
};

int main(){
    ios::sync_with_stdio(false);

    DBL* lista = new DBL;
    lista->pushFront(5);
    lista->pushFront(10);
    lista->pushFront(20);
    lista->pushFront(30);

    lista->searchDelete(20);


    lista->printFrontToBack();
    cout<<"========="<<endl;
    lista->printBackToFront();

    return 0;
}
