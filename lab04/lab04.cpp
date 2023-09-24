#include <iostream>

class Stack{
    private:
    Struct Node{
        int val;
        Node* nextNode = n;
    }
};

 Node* topOfStack;

 public:
 Stack(){
    topOfStack = nullptr;

 }

 Node* getTopOfStack(){
    return topOfStack;
 }

 void setTopOfStack(Node* n){
    topOfStack = n;
 }

 void push(int i){
    Node* newNode = new Node(i, topOfStack);
    setTopOfStack(newNode);
 }

 int pop(){
    if (topOfStack != nullptr){
        int val = topPfStack -> val;
        Node* ptrNewTop = topOfStack -> nextNode;

        delete topOfStack;
        setTopOfStack(ptrNewTop);
        return val;
    }
    std::cout << "Error: Tried popping an empty stack\n";
    return 0;
 }

 int peak(){
    if (topOfStack != nullptr){
        return topOfStack ->val;
    }
    std::cout << "Error: tried peaking an empty stack\n";
    return 0;
 }

 void removeAll(){
    while(getTopOfStack() != nullptr){
        int temp = pop();
    }
 }

 -Stack(){
    removeAll();
 };
 