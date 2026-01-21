#include "LinkedList.h"

/* Constructor */
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

/* Destructor */
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

/* Insert at front */
void LinkedList::insertFront(const std::string& message) {
    Node* newNode = new Node(message);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }

    size++;
}

/* Insert at back */
void LinkedList::insertBack(const std::string& message) {
    Node* newNode = new Node(message);

    if (tail) {
        tail->next = newNode;
        tail = newNode;
    } else {
        head = tail = newNode;
    }

    size++;
}

/* Insert AFTER a target message */
bool LinkedList::insertAfter(const std::string& target,
                             const std::string& newMessage) {
    Node* current = head;

    while (current) {
        if (current->message == target) {
            Node* newNode = new Node(newMessage);
            newNode->next = current->next;
            current->next = newNode;

            if (current == tail) {
                tail = newNode;
            }

            size++;
            return true;
        }
        current = current->next;
    }

    return false;
}

/* Delete a message */
bool LinkedList::deleteMessage(const std::string& message) {
    if (!head) return false;

    if (head->message == message) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (!head) {
            tail = nullptr;
        }
        return true;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->message == message) {
            Node* temp = current->next;
            current->next = temp->next;

            if (temp == tail) {
                tail = current;
            }

            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }

    return false;
}

/* Search for a message */
bool LinkedList::search(const std::string& message) const {
    Node* current = head;
    while (current) {
        if (current->message == message) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/* Print the list */
void LinkedList::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->message;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

/* Utilities */
int LinkedList::getSize() const {
    return size;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}
