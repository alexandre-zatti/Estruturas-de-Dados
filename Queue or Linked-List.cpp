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
    Node* next;
};

class Queue{
    public:
        Node* front;
        Node* back;

        Queue(){
            front = NULL;
            back = NULL;
        }

        ~Queue(){
            while(!isEmpty()){
                pop();
            }
        }

        void push(int value){
            Node* node = new Node;
            if(isEmpty()){
                node->value = value;
                node->next = NULL;
                back = node;
                front = node;
            }else{
                node->value = value;
                node->next = NULL;
                back->next = node;
                back = node;
            }
        }

        void pop(){
            if(!isEmpty()){
                Node* aux = new Node;
                aux = front;
                front = front->next;
                delete aux;
            }else{
                LOG("Nao ha ninguem na fila");
            }
        }

        void print(){
            Node* current = new Node;
            current = front;
            while(current != NULL){
                LOG(current->value);
                current = current->next;
            }
        }

        void peek(){
            LOG(front->value);
        }

        bool isEmpty(){
            return (front == NULL && back == NULL);
        }

};



int main(){
    ios::sync_with_stdio(false);

    Queue* fila = new Queue();

    fila->push(10);
    fila->push(20);
    fila->push(30);

    fila->searchDelete(fila,20);

    fila->print();


    return 0;
}
