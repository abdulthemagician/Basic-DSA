/*
โครงสร้างข้อมูลชนิด Stack หรือ LIFO(Last-In First-Out)
  คือ โครงสร้างแบบจานวางซ้อนกัน(วางทีหลัง)

      Functions ของ Stack จะประกอบด้วย
  -Top() or Peek()
  -isEmpty()
  -Push(Data)
  -Pop()
 */

#include <iostream>
using namespace std;

class Node{
  private:
    int data;
    Node* next;
  
  public:
    Node(int val){
      data = val;
      next = nullptr;
    }
    int getData() const{
      return data;
    }
    
    Node* getNext() const{
      return next;
    }
    
    void setNext(Node* nextNode){
      next = nextNode;
      return;
    }
};

class Stack{
  private:
    Node* top;
    
  public:
    Stack(){
      top = nullptr;
    }
    
    bool isEmpty() const{
      return top == nullptr;
    }
    
    void push(int value){
      Node* newNode = new Node(value);
      newNode->setNext(top);
      top = newNode;
      return;
    }
    
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->getNext();
        delete temp;
        return;
    }
    
    int peek() const{
      return isEmpty() ? -1 : top->getData();
    }
    
    void displayStack(){
      if(isEmpty()){
        cout << "Stack is empty\n";
          return;
    }
        Node* temp = top;
        cout << "Stack (top -> bottom): ";
        cout << "Top -> ";
        while(temp){
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << "-> Bottom\n";
        return;
    }
    
    ~Stack(){
      while(!isEmpty()){
        pop();
      }
    }
};

int main(){
  Stack myItem;

  for(int i=10;i<=100;i+=10){
    myItem.push(i);
  }
  myItem.displayStack();
  
  int n = 4;
  for(int i=1;i<=n;i++){
    myItem.pop();
    
  }
  
  cout << "\n After " <<  n <<" times pop Item \n\n";
  myItem.displayStack();
  
  return 0;
}
