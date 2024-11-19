// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - Tree manipulation & Traversal
// TREE_MANIPULATION_TRAVERSAL	Accept		40	CPP17	2 / 2	

#include <iostream>

using namespace std;

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    Node* leftSon; // Con trái
    Node* rightBro; // Anh phải
    Node* father; // Node cha
} Node;

// Hàm tạo Node
Node* makeNode(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->leftSon = NULL;
    temp->rightBro = NULL; 
    temp->father = NULL; 
    return temp;
}

// Hàm tìm Node
Node* find(Node* p, int x) {
    if (p == NULL) {
        return NULL;
    }
    if (p->data == x) {  // Chỉnh sửa '=' thành '=='
        return p;
    }
    
    // Đệ quy con trái
    Node* son = find(p->leftSon, x);
    if (son != NULL) {
        return son;
    }
    
    // Đệ quy anh em liền kề
    Node* bro = find(p->rightBro, x);
    if (bro != NULL) {
        return bro;
    }
    
    // Trả về NULL khi không tìm thấy
    return NULL;
}

// Hàm chèn Node
void insert(Node* p, int u, int v) {
    Node* findU = find(p, u);
    Node* findV = find(p, v);
    
    if (findU == NULL && findV != NULL) { // Không tìm thấy U và tìm thấy V
        Node* temp = makeNode(u);
        temp->father = findV; // temp luôn chèn sau findV
        
        if (findV->leftSon == NULL) {
            findV->leftSon = temp;
        } else {
            Node* sonFindV = findV->leftSon;
            while (sonFindV->rightBro != NULL) {
                sonFindV = sonFindV->rightBro;
            }
            sonFindV->rightBro = temp;
        }
    }
}

// Hàm duyệt PreOrder
void preOrder(Node* node) {
    if (node) {
        cout << node->data << " "; // Thăm nút hiện tại
        preOrder(node->leftSon);    // Duyệt cây con bên trái
        preOrder(node->rightBro);    // Duyệt cây con bên phải
    }
}

// Hàm duyệt PostOrder
void postOrder(Node* node) {
    if (node) {
        postOrder(node->leftSon);    // Duyệt cây con bên trái
        cout << node->data << " "; // Thăm nút hiện tại
        postOrder(node->rightBro);    // Duyệt cây con bên phải
    }
}

// Hàm duyệt InOrder
void inOrder(Node* node) {
    if (node) {
        inOrder(node->leftSon); // Bắt đầu từ con trái
        cout << node->data << " ";
        
        if (node->leftSon != NULL){
            Node* tmp = node->leftSon;
            while(tmp->rightBro != NULL){ // inOrder lại các anh em phải
                inOrder(tmp-> rightBro);
                tmp = tmp -> rightBro;
            }
        }
    }
}
int main(){
    string s;
    Node* root;
    while(cin>>s){
        if(s=="*"){
            break;
        }
        if(s=="MakeRoot"){ // Tạo gốc 
            int num;
            cin>>num;
            root = makeNode(num);
        }
        if(s=="Insert"){ // Chèn
            int u,v; 
            cin>>u>>v;
            insert(root,u,v);
        }
        if(s=="PreOrder"){
            preOrder(root);
            cout<<endl;
        }
        if(s=="InOrder"){
            inOrder(root);
            cout<<endl;
        }
        if(s=="PostOrder"){
            postOrder(root);
            cout<<endl;
        }
    }
}



















