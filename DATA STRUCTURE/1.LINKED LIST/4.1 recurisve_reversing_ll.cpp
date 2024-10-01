Node* reverse(Node* head) {
    // Step 1: Base case - stop if the list is empty or has one node.
    if (head == NULL || head->next == NULL) {
        return head;  // The last node is the new head after reversal
    }

    // Step 2: Recursive step - reverse the rest of the list.
    Node* rest = reverse(head->next);

    // Step 3: Reverse the current node's connection
    Node* nextNode = head->next;  // Store the next node
    nextNode->next = head;        // Reverse the link (nextNode's next points to head)

    // Step 4: Disconnect the current node's forward link
    head->next = NULL;

    // Step 5: Return the new head of the reversed list
    return rest;
}
