#include <iostream>

class Deque{
    private:
    struct Node{
        int val;
        Node* nextNode;
        Node* prevNode;

        Node(int ci, Node* n, Node*p){
         val = ci;
         nextNode = n;
         prevNode = p;
        }
    };
    Node* topOfDeque;
    Node* backOfDeque;

 public:
 Deque(){
    topOfDeque = nullptr;
    backOfDeque = nullptr;

 }

 Node* getTopOfDeque(){
    return topOfDeque;
 }

 Node* getBackOfDeque() {
        return backOfDeque;
    }

 void setTopOfDeque(Node* n){
    topOfDeque = n;
 }

 void setBackOfDeque(Node* p){
   backOfDeque = p;
 }

 void push_front(int i){
    Node* newNode = new Node(i, topOfDeque);
    setTopOfDeque(newNode);
 }

 void push_back(int i) {
        Node* newNode = new Node(i, backOfDeque);
        setBackOfDeque(newNode);
 }

 int pop_front(){
    if (topOfDeque != nullptr){
        int val = topOfDeque -> val;
        Node* ptrNewTop = topOfDeque -> nextNode;

        delete topOfDeque;
        setTopOfDeque(ptrNewTop);
        return val;
    }
    std::cout << "Error: Tried popping an empty stack\n";
    return 0;
 }

 int pop_back() {
        if (!backOfDeque) {
            std::cout << "Error: Tried popping an empty deque from back\n";
            return 0;
        }
        int val = backOfDeque->val;
        Node* temp = backOfDeque;
        backOfDeque = backOfDeque->prevNode;
        if (backOfDeque) {
            backOfDeque->nextNode = nullptr;
        } else {
            topOfDeque = nullptr;
        }
        delete temp;
        return val;
    }

   

 int peak_front(){
    if (topOfDeque != nullptr){
        return topOfDeque ->val;
    }
    std::cout << "Error: tried peaking an empty stack\n";
    return 0;
 }

 int peak_back() {
        if (backOfDeque) {
            return backOfDeque->val;
        }
        std::cout << "Error: Tried peaking an empty deque from back\n";
        return 0;
    }

 void removeAll(){
    while(getTopOfDeque() != nullptr){
        int temp = pop_front();
    }
 }
 ~Deque() {
        removeAll();
 }
};