Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    Node *prev = curr->back;