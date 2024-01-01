#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

struct node{
    string name;
    node *next;
};
node *root = NULL;

void add_to_list(string name){

    if(root==NULL){
        root = new node();
        root -> name = name;
        root -> next = NULL;
        return;
    }

    node *curr_node = root;
    while(curr_node -> next != NULL){
        curr_node = curr_node -> next;
    }

    node *newnode = new node();
    newnode -> name = name;
    newnode -> next = NULL;
    curr_node -> next = newnode;
}

void print_list(){
    node *curr_node = root;

    while(curr_node!=NULL){
        cout<<(curr_node -> name)<<nn;
        curr_node = curr_node -> next;
    }
}

void delete_from_list(string name){
    node *prev_node = NULL;
    node *curr_node = root;

    while(curr_node!=NULL){
        if(curr_node -> name == name){
            if(prev_node==NULL){
                // root e ase
                node *temp = root;
                root = curr_node -> next;
                delete(temp);
            }
            else{
                prev_node -> next = curr_node -> next;
                delete(curr_node);
            }
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node -> next;
    }
}

void solve(){
    add_to_list("dada");
    add_to_list("abba");
    add_to_list("ami");

    //print_list();

    delete_from_list("ami");
    print_list();
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}