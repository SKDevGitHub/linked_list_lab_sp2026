#include "ll.h"

int main() {
    LinkedList list;

    // Initial messages
    list.insertBack("MSG#1: xxx0002xxx");
    list.insertBack("MSG#2: xxx0003xxx");
    list.insertBack("MSG#3: xxx00z3xxx");

    // Insert urgent message at the front
    list.insertFront("URGENT: xxx!!!!xxx");

    list.print();
    return 0;
}
