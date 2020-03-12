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
    Node *next;
};

class Stack{
    public:
        Node *top;

        //Constructor
        Stack(){
            top = NULL;

        }
        //Destructor
        ~Stack(){
            while(!isEmpty()){
                pop();
            }
        }

        void push(int value){
            Node* node = new Node;
            node->value = value;
            node->next = top;
            top = node;
        }
        void pop(){
            if(!isEmpty()){
                Node* oldTop = top;
                top = top->next;
                delete oldTop;
            }else{
                LOG("A pilha esta vazia");
            }
        }

        void print(){
            if(isEmpty()){
                LOG("A pilha esta vazia");
            }else{
                Node *current = new Node;
                current = top;
                while(current != NULL){
                    LOG(current->value);
                    current = current->next;
                }
            }
        }
        void searchDelete(Stack * stack, int value){
            Stack* aux = new Stack();
            while(stack->top->value != value){
                aux->push(stack->top->value);
                stack->pop();
            }
            stack->pop();
            while(!aux->isEmpty()){
                stack->push(aux->top->value);
                aux->pop();
            }
        }
        int peek(){
            return top->value;
        }
        bool isEmpty(){
           return (top == NULL);
        }
};



int main(){
    ios::sync_with_stdio(false);

    Stack* stack = new Stack();

    stack->push(10);
    stack->push(20);
    stack->push(30);


    stack->print();

    return 0;
}
