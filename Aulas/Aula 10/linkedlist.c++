#include <iostream>
using namespace std;
//CRIANDO LINKED LIST

typedef struct link { 
    int element;  
    link* next;    
}Link;
typedef struct { 
    Link* head;   
    Link* tail;
    Link* curr;   
    int cnt;    
}List;

Link* create_link(int it, Link* nextval) { 
    Link* n = new Link;
    n -> element = it;
    n -> next = nextval;
    return n; 
}
Link* create_next_link(Link* nextval) {
    Link* n = new Link;
    n -> next = nextval;
    return n;
}

List* create_list() { 
    List* l = new List;
    l -> curr = l -> tail = l -> head = create_next_link(nullptr);
    l -> cnt = 0;
    return l;
}

//OPERÇÕES
void insert(List* l, int it) {
    l -> curr -> next = create_link(it, l -> curr -> next);
    if (l -> tail == l -> curr){
        l -> tail = l -> curr -> next;
    }
    l -> cnt++;
}
void moveToStart(List* l) {
    l -> curr = l -> head;
}
void prev(List* l) {
    if (l -> curr == l -> head) {return;}
    Link* temp = l -> head;
    while (temp -> next != l -> curr)
    {
        temp = temp -> next;
    }
    l -> curr = temp;
}
void next(List* l) {
    if(l -> curr != l -> tail) {
        l -> curr = l -> curr -> next;
    }
}
int remove(List* l) {//todas as vezes que eu chamar a função verificar se não está vazia
    if (l -> tail == l -> curr) {
        return -1;
        
    }
    int it = l -> curr -> next -> element;
    l -> curr -> next = l -> curr -> next -> next;
    l -> cnt--;
    return it;
}

int getValue(List* l){
    
    if (l -> cnt != 0){
        return l -> curr -> next -> element;
    }
    else{
        return -1;
    }
     
}

int main () {
    List* mylist = create_list();
    int qnt_elemento;
    cin >> qnt_elemento;
    int valor;
    for (int i=0; i < qnt_elemento; i++) {
        cin >> valor;
        insert(mylist, valor);
    }
    while(mylist -> curr -> next !=nullptr) {
        cout << getValue(mylist) << " ";
        next(mylist);
    }
    return 0;
}