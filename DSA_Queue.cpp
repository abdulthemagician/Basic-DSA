/*
โครงสร้างข้อมูลชนิด Queue หรือ FIFO(First-In First-Out)
ี  คือโครงสร้างข้อมูลที่เข้ามาก่อนและออกก่อน
    โดยจะมีทั้งหมด 2 ประเภทตามนี้
        Linear, Circular
    ซึ่ง 2 ประเภทนี้จะมีข้อแตกต่างอยู่ที่
        Linear จะมีตัวแปร front เก็บที่อยู่ของโหนดหน้าสุดและ rear จะเก็บที่อยู่ของโหนดหลังสุด
        Circular จะมีตัวแปร front, rear เหมือนกับ Linear ***เพียงแต่ที่อยู่ถัดไปของ rear จะชี้ไปที่ front***
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
    
    int getData(){
      return data;
    }
    
    Node* getNext(){
      return next;
    }
    
    void setNext(Node* nextNode){
      next = nextNode;
      return;
    }
};

class Linear_Queue{
  private:
    Node* front, *rear;
    
  public:
    Linear_Queue(){
      front = nullptr;
      rear = nullptr;
    }
    
    bool isEmpty(){
      return front == nullptr;
    }
    
    void enqueue(int data){
      Node* newNode = new Node(data);
      
      if(isEmpty()){
        front = rear = newNode;
        return;
      }
      
      rear->setNext(newNode);
      rear = newNode;
      
      return;
    }
    
    void dequeue(){
      if(isEmpty()){
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
      }
      
      Node* temp = front;
      front = front->getNext();
      
      if(front == nullptr){
        rear = nullptr;
      }
      
      delete temp;
    }
    
    void display_queue(){
      if(isEmpty()){
        cout << "Queue is empty.\n";
      }
      
      Node* temp = front;
      cout << "Queue : ";
      while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
      }
      cout << endl;
    }
};

int main(){
  int n = 100;
  Linear_Queue myQueue;
  
  cout << "Before dequeue : \n";
  for(int i = 10; i <= n; i+=10){
    myQueue.enqueue(i);
  }
  myQueue.display_queue();
  
  cout << "After dequeue : \n";
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.display_queue();
  return 0;
}