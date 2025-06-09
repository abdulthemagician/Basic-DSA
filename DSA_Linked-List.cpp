/*
โครงสร้างข้อมูลชนิด Linked Lists 
คือ โครงสร้างเก็บข้อมูลเป็นชุดของโหนด

  โดยจะมีทั้งหมด 3 ประเภทดังนี้
    Singly, Doubly และ Circular

  ซึ่ง 3 ประเภทนี้มีข้อแตกต่างกันอยู่ดังนี้
    ประเภท Singly จะมีตัวแปร Head เก็บที่อยู่ส่วนหัวอย่างเดียว
    ประเภท Doubly จะมีตัวแปร Head เก็บที่อยู่ส่วนหัว และ Tail จะเก็บที่อยู่ส่วนปลายสุด
    ประเภท Circular จะมีตัวแปร Head และ Tail ประกอบอยู่ทั้งคู่ ***เพียงแค่ที่อยู่ถัดไปของ Tail จะชี้ไปที่ Head เสมอ***

    โดย Functions ของ Linked Lists ทั้งหมดจะประกอบด้วย
 -Singly Linekd List
    InsertAtBegin(Data)
    InsertAtEnd(Data)
    InsertAt(Node, Data)
    DeleteAt(Node)
    Search(Data)
    IsEmpty()
    Display()
 
 -Doubly Linked List
    มีฟังก์ชันของ Singly Linked List ทั้งหมด
    InsertBefore(Node, Data)
    InsertAfter(Node, Data)
 
 -Circular Linked List (สามารถเป็น Singly หรือ Doubly)
    มีฟังก์ชันของสองประเภทข้างบนทั้งหมด
     traverseCircular() – เดินครบลูปโดยไม่เข้าสู่วงไม่รู้จบ
     การ insert/delete ต้องจัดการ pointer ให้ชี้กลับไป node แรก/สุดท้าย
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
    
    void setData(int value){
      data = value;
    }
    
    int getData() const{
      return data;
    }
    
    void setNext(Node* newNode){
      next = newNode;
      return;
    }
    
    Node* getNext() const{
      return next;
    }
    
};

class singlyList{
  private:
    Node* head;
  
  public:
    singlyList(){
      head = nullptr;
    }
    
    bool isEmpty(){
      return head == nullptr;
    }
    
    void swapData(Node* a, Node* b){
      int temp = a->getData();
      a->setData(b->getData());
      b->setData(temp);
    }
    
    void appendToList(int data){
      if(isEmpty()){
        Node* newNode = new Node(data);
        head = newNode;
        return;
      }
        Node* newNode = new Node(data);
        Node* temp = head;
        while(temp->getNext()){
          temp = temp->getNext();
        }
        temp->setNext(newNode);
        return;
    }
    
    void deleteAt(int data){
      if(isEmpty()){
        cout << "Linked List is empty!\n";
        return;
      }else if(head->getData() == data){
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return;
      }
        Node* temp = head;
        Node* prev = nullptr;
        while(temp && temp->getData() != data){
          prev = temp;
          temp = temp->getNext();
        }
        
        if(!temp) return;
        
        prev->setNext(temp->getNext());
        delete temp;
        return;
    }
    
    void displayLinkedList(){
      if(isEmpty()){
        cout << "Linked List is empty!\n";
      }
        Node* temp = head;
        cout << "\nLeft -> ";
        while(temp){
          cout << temp->getData() << " ";
          temp = temp->getNext();
        }
        cout << "-> Right\n";
        return;
    }
    
    void BubbleSort(){
      if(!head || !head->getNext()) return;
      
      bool swapped;
      Node* lastSorted = nullptr;
      
      do{
        swapped = false;
        Node* temp = head;
        while(temp->getNext() != lastSorted){
          if(temp->getData() > temp->getNext()->getData()){
            swapData(temp, temp->getNext());
            swapped = true;
          }
          temp = temp->getNext();
        }
        lastSorted = temp;
      }while(swapped);
      return;
    }
    
    void clearNode(){
      if(isEmpty()){
        cout << "Linked List is empty!\n";
      }
        while(head){
          Node* temp = head;
          head = head->getNext();
          delete temp;
        }
        return;
    }
};

int main(){
    singlyList myLinkedList;
    
    for(int i=10;i<=100;i+=10){
      myLinkedList.appendToList(i);
    }
    myLinkedList.displayLinkedList();
    
    cout << "\n After delete some node \n";

    myLinkedList.deleteAt(10);
    myLinkedList.deleteAt(50);
    myLinkedList.displayLinkedList();

    cout << "\n After bubble sort \n";
    myLinkedList.BubbleSort();
    myLinkedList.displayLinkedList();
    
    myLinkedList.clearNode();
    return 0;
}
