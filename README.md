# linked_list_lab_sp2026

You are a new recruit in a secret Missouri S&T research lab called Mo Dehghani’s Code Initiative. The lab is hidden underneath the Puck, the campus landmark that only looks like an oversized granite hockey puck. In reality, it’s the disguised entrance to one of the most advanced computing facilities in the Midwest. Your job: design the next-generation AI to defend the world against a mysterious cyber-threat.

A rogue AI system known only as TJ was accidentally unleashed during an undergraduate project gone wrong in the Computer Science building. TJ now infects digital systems across Rolla including MinerLink servers and the traffic lights on Bishop Ave. — and only your code can stop its rampage.

You’ve just been cleared for your first mission in the Mo Dehghani’s Code Initiative. From the underground lab beneath the Puck, you’re tasked with building a system that can handle streams of encrypted messages intercepted from TJ.

The messages arrive in a chain, one after another, but their order and relevance change constantly. You need a flexible data structure to manage insertions, deletions, and traversal efficiently.


Input:
MSG#1: xxx0002xxx
MSG#2: xxx0003xxx
MSG#3: xxx00z3xxx
MSG#4: xxx0024xxx
MSG#5: xxx4521xxx

Parts of the assignment:
Initialize the Linked List with the 5 messages
Print the initial list
Insert a new Message {URGENT: xxx!!!!xxx} to the top of the list
Insert a new Message {LOW_PRIORITY} to the bottom of the list
Delete MSG#3 from the list
Insert a new Message {MSG#3: xxxNEWxxx} in between message 2 and 4
Search for MSG#2 in the list
Search for MSG#7 in the list — should fail

Print statements throughout the code showing the changes in each part as well as print the linked list at the end.
