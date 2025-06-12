/*
โครงสร้างข้อมูลชนิด Stack หรือ LIFO(Last-In First-Out)
คือ โครงสร้างแบบ "จานวางซ้อนกัน" (วางทีหลังก็เอาออกก่อน)

Function พื้นฐานของ Stack:
- top()      : ดูค่าด้านบนสุดของสแตก (โดยไม่ลบ)
- isEmpty()  : ตรวจสอบว่าสแตกว่างหรือไม่
- push(data) : เพิ่มข้อมูลลงบนสแตก
- pop()      : ลบข้อมูลบนสุดของสแตก
*/

#include <iostream>
using namespace std;

//Create Node
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
    Node* top; //Pointer to the top of the stack
    
  public:
    //Constructor
    Stack(){
      top = nullptr;
    }
    //Destructor
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }   

    //Check if the stack is empty
    bool isEmpty() const{
      return top == nullptr;
    }
    //Push a new values onto the stack
    void push(int value){
      Node* newNode = new Node(value); //Create new node
      newNode->setNext(top); //Link it to previous top
      top = newNode; //Update top
      return;
    }
    //Pop the top value off the stack
    void pop(){
        //Check if the stack is empty
        if(isEmpty()){
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top; //Temporarily store the top node 
        top = top->getNext(); //Move top to the next node
        delete temp; //Delete top
        return;
    }
    //Return the element of stack
    int top() const{
      return isEmpty() ? -1 : top->getData(); //Return -1 if empty
    }
    //Display all element in the stack
    void displayStack(){
      if(isEmpty()){
        cout << "Stack is empty\n";
          return;
    }

    Node* temp = top; //Temporarily store the top node
    cout << "Stack (top -> bottom): ";
    cout << "Top -> ";
    while(temp != nullptr){ //Loop untill temporarily store nullptr
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << "-> Bottom\n";
    return;
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
