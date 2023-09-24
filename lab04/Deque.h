#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    struct Node {
        int val;
        Node* nextNode;
        Node* prevNode;

        Node(int ci, Node* n, Node* p);
    };
    Node* topOfDeque;
    Node* backOfDeque;

public:
    Deque();
    ~Deque();

    Node* getTopOfDeque();
    Node* getBackOfDeque();
    void setTopOfDeque(Node* n);
    void setBackOfDeque(Node* p);

    void push_front(int i);
    void push_back(int i);
    int pop_front();
    int pop_back();
    int peak_front();
    int peak_back();
    void removeAll();
};

#endif // DEQUE_H
