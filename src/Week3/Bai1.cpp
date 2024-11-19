// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - BST - Insertion and PreOrder Traversal
// BST_INSERTION_MANIPULATION	Accept		100	CPP17	5 / 5	

#include<iostream>
#include<string>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
} Node;

Node* makeNode(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

Node* insert(Node* root, int x){
    //Nếu rỗng trả về node đầu tiên
    if (root == nullptr) {
        return makeNode(x);
    }

    if (x < root->data){
        root->left = insert(root->left, x);
    }
    else if (x > root->data){
        root->right = insert(root->right, x);
    }
    // Nếu giá trị bằng, không thêm gì và trả về root
    return root;
}

void duyet_PreOder(Node* root){
    if (root != nullptr) {
        cout << root->data << " ";
        duyet_PreOder(root->left);       // Gọi lại hàm duyet_PreOder
        duyet_PreOder(root->right);      // Gọi lại hàm duyet_PreOder
    }
}

int main (){
    Node* root = NULL;
    
    string s;
    while(cin>>s){
        if(s == "insert"){
            int n;
            cin >>n;
            root = insert(root ,n);
            
        }
        if(s=="#"){
            break;
        }
    }
    duyet_PreOder(root);
    
}
