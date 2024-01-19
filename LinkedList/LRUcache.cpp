#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int data;

    Node *next;
    Node *prev;

    Node(int val)
    {
        this->data = val;
        this->key = -1;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int val, Node *next1)
    {
        this->key = -1;
        this->data = val;
        this->next = next1;
        this->prev = NULL;
    }
    Node(int val, Node *next1, Node *prev1)
    {
        this->key = -1;
        this->data = val;
        this->next = next1;
        this->prev = prev1;
    }
    Node(int key1, int val)
    {
        this->key = key1;
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int key1, int val, Node *next1)
    {
        this->key = key1;
        this->data = val;
        this->next = next1;
        this->prev = NULL;
    }
    Node(int key1, int val, Node *next1, Node *prev1)
    {
        this->key = key1;
        this->data = val;
        this->next = next1;
        this->prev = prev1;
    }
};

Node *insertNode(Node *head, int key, int val)
{
    cout << "InsertNode" << endl;
    if (head == NULL)
    {
        head = new Node(key, val);
        return head;
    }
    Node *temp = head->next;
    Node *added = new Node(key, val, temp, head);
    head->next = added;
    if (temp)
        temp->prev = added;
    return head;
}
void deleteNode(Node *delNode)
{
    cout << endl;
    cout << "deleteNode" << endl;
    if (delNode == NULL)
        return;

    Node *temp = delNode;
    Node *previ = temp->prev;
    Node *front = temp->next;

    if (front == NULL && previ == NULL)
    {
        cout << "d0 both NULL" << endl;
        delete delNode;
        return;
    }
    if (front == NULL)
    {
        cout << "d1  front NULL" << endl;
        previ->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    if (previ == NULL)
    {
        cout << "d2 prev NULL" << endl;
        temp->data = front->data;
        // previ = temp;
        // temp = temp->next;
        front = front->next;

        temp->next = front;
        previ = front->prev;
        front->prev = temp;

        previ->next = NULL;
        previ->prev = NULL;
        delete previ;
        return;
    }
    cout << "d3 default path " << endl;
    previ->next = front;
    front->prev = previ;

    temp->next = NULL;
    temp->prev = nullptr;
    delete temp;
    cout << "dN END" << endl;
    // cout << endl;

    return;
}
class LRUCache
{

public:
    int cap, cnt = 0;
    unordered_map<int, Node *> hashmap;
    Node *head;
    Node *tail;

    LRUCache(int capacity)
    {
        this->cap = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1, NULL, head);
        this->head->next = tail;
        cout << "LRUCache" << endl;
    }

    int get(int key)
    {
        cout << "get "
             << "cnt " << cnt << endl;
        if (hashmap.find(key) != hashmap.end())
        {
            int k = hashmap[key]->data;
            head = insertNode(head, key, k);
            deleteNode(hashmap[key]);
            hashmap[key] = head->next;
            return k;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (cnt == cap)
        {
            cout << "put eq STARTSS "
                 << "cnt " << cnt << endl;
            deleteNode(tail->prev);
            cout << "tail prev data ->" << tail->prev->data << endl;
            hashmap.erase(tail->prev->key);
            head = insertNode(head, key, value);
            hashmap[key] = head->next;
            cout << "put eq ENDSS" << endl
                 << endl;
        }
        if (cnt < cap)
        {
            cout << "put less "
                 << "cnt " << cnt << endl;
            head = insertNode(head, key, value);
            hashmap[key] = head->next;
            cnt++;
        }
    }
};

int main()
{
    // START  input.txt and output.txt syntax
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // END  input.txt and output.txt syntax

    // LRUCache l1(5);
    // l1.put(1, 5);
    // l1.put(2, 3);
    // l1.put(3, 2);
    // l1.put(4, 7);
    // l1.put(5, 6);
    // l1.put(9, 11);
    // cout
    //     // << l1.cap<< " __ "
    //     // << l1.get(1) << " "
    //     << l1.get(3) << " " << l1.get(2) << " " << l1.get(4) << " " << l1.get(5) << " " << l1.get(9)
    //     //  << " __ " << l1.cnt
    //     ;
    LRUCache l1(2);
    l1.put(1, 1);
    l1.put(2, 2);
    cout <<"-----------------------"<< l1.get(1) << endl;
    l1.put(3, 3);
    cout <<"-----------------------"<< l1.get(2) << endl;
    l1.put(4, 4);
    cout <<"-----------------------"<< l1.get(1) << endl;
    cout << l1.get(3) << endl;
    cout << l1.get(4) << endl;
    // l1.put(5, 6);
    // l1.put(9, 11);
    // cout
    //     // << l1.cap<< " __ "
    //     // << l1.get(1) << " "
    //     << l1.get(3) << " " << l1.get(2) << " " << l1.get(4) << " " << l1.get(5) << " " << l1.get(9)
    //     //  << " __ " << l1.cnt
    //     ;
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */