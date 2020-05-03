#include <bits/stdc++.h>
using namespace std;


//node structure for triply linkd list
struct node{
    node* next;
    node* prev;
    node* top;
    int data;
};


//TriplyLinkedList Class 
class TriplyLinkedList{
    node* head;
    node* tail;
    int count;
    void destroy_list(node* );
    public:
    TriplyLinkedList();
    ~TriplyLinkedList();
    void insert_key(int key);
    void delete_key(int key);
    node* search_key(int key);
    void traverse_head();
    void traverse_tail();
    void destroy_list(){
        if(this->count == 0)
        return ;
        this->count = 0;
        this->destroy_list(this->head);
        this->head = NULL;
        this->tail = NULL;
    }
};


//TriplyLinkedList Class Constructor 
TriplyLinkedList::TriplyLinkedList(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}


//TriplyLinkedList Class Destructor
TriplyLinkedList::~TriplyLinkedList(){
    this->destroy_list();
}


//TriplyLinkedList Class Insert member function
void TriplyLinkedList::insert_key(int key){
    node* newNode = new node;
    node* curr = NULL;
    node* previous = NULL;
    newNode->data = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->top = NULL;
    if(this->count == 0)
    {
        this->head = newNode;
        this->tail = newNode;

    }
    else
    {
        curr = this->head;
        previous = this->head;
        if(newNode->data< curr->data)
        {
            newNode->next = curr;
            curr->prev = newNode;
            while(curr->next)
            curr=curr->next;
            this->tail = curr;
            this->head = newNode;
        }
        else if (newNode->data >= curr->data)
        {
            while(curr && curr->data <= newNode->data)
            {
                if(curr->data == newNode->data){
                    node* temp = curr;
                    while(temp->top)
                    temp = temp->top;
                    temp->top = newNode;
                    this->count++;
                    return ;
                }
                previous = curr;
                curr = curr->next;
            }
            if(curr){
                newNode->next = curr;
                curr->prev = newNode;
            }
            newNode->prev = previous;
            previous->next = newNode;
            while(previous->next)
            previous = previous->next;
            this->tail = previous;
        }
    }
    this->count++;
    return ;
}


//TriplyLinkedList Class Delete member function
void TriplyLinkedList::delete_key(int key){
    if(this->count==0)
    {
        cout<<"List is empty\n";
    }
    else if(this->count == 1 )
    {
        if(this->head->data == key)
        this->destroy_list();
        else
        {
            cout<<"Key not present in list.\n";
            return ;
        }
        
        return ;
    }

    node* curr = this->head;
    node* previous = this->head;
    while(curr && curr->data != key)
    {
        previous = curr;
        curr = curr->next;
    }
    if(curr==NULL)
    {
        cout<<"Key not present in list.\n";
        return ;
    }
    if(curr == head)
    {
        this->head = head->next;
        this->head->prev = NULL;
        curr->next = NULL;
        this->destroy_list(curr);
    }
    else
    {
        previous->next = curr->next;
        if(curr->next)
        curr->next->prev = previous;

        curr->next = NULL;
        this->destroy_list(curr);
        while(previous->next)
        previous = previous->next;
        this->tail = previous;
    }
    this->count--;
    
}


//TriplyLinkedList Class Search member function returns pointer to node
node* TriplyLinkedList::search_key(int key){
    node* curr = this->head;
    while(curr && curr->data != key)
    curr = curr->next;

    return curr;
}


//TriplyLinkedList Class Traverse from head side member function
void TriplyLinkedList::traverse_head(){
    if(this->count == 0)
    {
        cout <<"Empty List!\n";
        return ;
    }
    cout<<"Result:\n";
    node* curr = this->head;
    while(curr)
    {
        cout<<curr->data<<" ";
        node* temp = curr->top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->top;
        }
        cout<<endl;
        curr = curr->next;
    }
}


//TriplyLinkedList Class Traverse from tail side member function
void TriplyLinkedList::traverse_tail(){
    if(this->count == 0)
    {
        cout <<" Empty List!\n";
        return ;
    }
    cout<<"Result:\n";
    node* curr = this->tail;
    while(curr)
    {
        cout<<curr->data<<" ";
        node* temp = curr->top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->top;
        }
        cout<<endl;
        curr = curr->prev;
    }
}


//TriplyLinkedList Class Destroy List member function
void TriplyLinkedList::destroy_list(node* curr)
{
    if(curr)  
    {
        destroy_list(curr->next);
        destroy_list(curr->top);
        delete curr;
    }
}
int main(){
    TriplyLinkedList triplyLinkedList;
    while(1)
    {
        cout<<"Options: \n1.Insert value \n2.Delete value \n3.Search value\n4.Traverse from head\n5.Traverse from tail\n6.Destroy list\n";
        cout <<"Your Option:\n";
        int option;
        cin>>option;
        switch (option)
        {
            case 1:{
                cout<<"Enter the value to be inserted\n";
                int val;
                cin>>val;
                triplyLinkedList.insert_key(val);
                break;
            }
            case 2:{
                cout<<"Enter the value to be deleted (all instances of that number will be deleted)\n";
                int val;
                cin>>val;
                triplyLinkedList.delete_key(val);
                break;
            }
            case 3:{
                cout<<"Enter the value to be searched\n";
                int val;
                cin>>val;
                node* curr = triplyLinkedList.search_key(val);
                if(curr)
                {
                    cout<<"value found";
                }
                else{
                    cout<<"Value not found";
                }    
                break;
            }
            case 4:{
                triplyLinkedList.traverse_head();
                break;
            }
            case 5:{
                triplyLinkedList.traverse_tail();
                break;
            }
            case 6:{
                triplyLinkedList.destroy_list();
                break;
            }
            default: {
                cout<<"Invalid Option!";
                break;
            }
            
        }
    }
}