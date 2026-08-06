class Node {
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int value) : value(value), prev(nullptr), next(nullptr) {}
        Node(int value, Node* prev, Node* next) : value(value), prev(prev), next(next) {}
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        Node* newnode = new Node(value, tail->prev, tail);
        tail->prev->next = newnode;
        tail->prev = newnode;
    }

    void appendleft(int value) {
        Node* newnode = new Node(value, head, head->next);
        head->next->prev = newnode;
        head->next = newnode;
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        Node* lastnode = tail->prev;
        int value = lastnode->value;
        Node* secondlastnode = lastnode->prev;
        secondlastnode->next = tail;
        tail->prev = secondlastnode;
        delete lastnode;
        return value;
    }

    int popleft() {
        if(isEmpty()) {
            return -1;
        }
        Node* firstnode = head->next;
        int value = firstnode->value;
        Node* secondnode = firstnode->next;
        secondnode->prev = head;
        head->next = secondnode;
        delete firstnode;
        return value;
    }
};
