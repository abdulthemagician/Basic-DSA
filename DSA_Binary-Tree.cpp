/*
โครงสร้างข้อมูลชนิด Tree 
  คือ โครงสร้างข้อมูลที่เก็บโหนดอยู่ในรูปแบบต้นไม้กลับด้าน
  
  โดย Functions พื้นฐานของ Tree ทั้งหมดจะประกอบด้วย
  Insert
  Traversal
    Depth-First Search (DFS)
      Pre-Order, In-Order, Post-Order
    Breadth-First Search (BFS)
      จะท่องโหนดให้ครบทุกระดับแล้วค่อยขยันระดับลงจนกว่าไม่มี


*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree{
private:
    Node* root;

    Node* insertRecursive(Node* node, int value){
        if(node == nullptr){
            return new Node(value);
        }
        
        if(value < node->data){
            node->left = insertRecursive(node->left, value);
        }else if(value > node->data){
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    void preOrder(Node* node){
        if(node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
        return;
    }

    void inOrder(Node* node){
        if(node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
        return;
    }

    void postOrder(Node* node){
        if(node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
        return;
    }

    void destroyTreeRecursive(Node* node){
        if(node == nullptr){
            return;
        }
        destroyTreeRecursive(node->left);
        destroyTreeRecursive(node->right);
        delete node;
    }

public:
    BinaryTree(){
        root = nullptr;
    }
    ~BinaryTree() {
        destroyTreeRecursive(root);
    }

    void insert(int value){
        root = insertRecursive(root, value);
    }
    
    void printPreOrder(){
        cout << "Pre-Order: ";
        preOrder(root);
        cout << endl;
        return;
    }

    void printInOrder(){
        cout << "In-Order: ";
        inOrder(root);
        cout << endl;
        return;
    }

    void printPostOrder(){
        cout << "Post-Order: ";
        postOrder(root);
        cout << endl;
        return;
    }


};

int main(){
    BinaryTree tree;

    tree.insert(24);
    tree.insert(20);
    tree.insert(30);
    tree.insert(45);
    tree.insert(25);
    tree.insert(16);
    tree.insert(22);
    tree.insert(11);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);

    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();
    return 0;
}