#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>

class LinkedList {
private:
    struct Node {
        std::string message;
        Node* next;

        Node(const std::string& msg) : message(msg), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor / Destructor
    LinkedList();
    ~LinkedList();

    // Core operations
    void insertFront(const std::string& message);
    void insertBack(const std::string& message);
    bool insertAfter(const std::string& target,
                     const std::string& newMessage);

    bool deleteMessage(const std::string& message);
    bool search(const std::string& message) const;

    // Utility
    void print() const;
    int getSize() const;
    bool isEmpty() const;
};

#endif