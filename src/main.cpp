#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;

    std::cout << "Initializing linked list with intercepted messages...\n";

    list.insertBack("MSG#1: xxx0002xxx");
    list.insertBack("MSG#2: xxx0003xxx");
    list.insertBack("MSG#3: xxx00z3xxx");
    list.insertBack("MSG#4: xxx0024xxx");
    list.insertBack("MSG#5: xxx4521xxx");

    std::cout << "Initial list:\n";
    list.print();
    std::cout << std::endl;

    // Insert urgent message at the top
    std::cout << "Inserting urgent message at the top...\n";
    list.insertFront("URGENT: xxx!!!!xxx");
    list.print();
    std::cout << std::endl;

    // Insert low priority message at the bottom
    std::cout << "Inserting low priority message at the bottom...\n";
    list.insertBack("LOW_PRIORITY");
    list.print();
    std::cout << std::endl;

    // Delete MSG#3
    std::cout << "Deleting MSG#3: xxx00z3xxx...\n";
    if (list.deleteMessage("MSG#3: xxx00z3xxx")) {
        std::cout << "MSG#3 deleted successfully.\n";
    } else {
        std::cout << "MSG#3 not found.\n";
    }
    list.print();
    std::cout << std::endl;

    // Insert new MSG#3 between message 2 and 4
    std::cout << "Inserting new MSG#3 between MSG#2 and MSG#4...\n";
    if (list.insertAfter("MSG#2: xxx0003xxx",
                          "MSG#3: xxxNEWxxx")) {
        std::cout << "New MSG#3 inserted successfully.\n";
    } else {
        std::cout << "Target MSG#2 not found.\n";
    }
    list.print();
    std::cout << std::endl;

    // Search for MSG#2
    std::cout << "Searching for MSG#2...\n";
    if (list.search("MSG#2: xxx0003xxx")) {
        std::cout << "MSG#2 found.\n";
    } else {
        std::cout << "MSG#2 not found.\n";
    }

    // Search for MSG#7 (should fail)
    std::cout << "Searching for MSG#7...\n";
    if (list.search("MSG#7")) {
        std::cout << "MSG#7 found.\n";
    } else {
        std::cout << "MSG#7 not found.\n";
    }

    std::cout << "\nFinal linked list state:\n";
    list.print();

    return 0;
}
