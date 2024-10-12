#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this->data = 0;
        this-> next =0;
    }
    Node(int data)
    {
        this->data = data;
        this->next = 0;
    }
};
Node* SortList(Node*&head)
{
     if(head == NULL) {
                cout << "LL is empty " << endl;
                return NULL;
        }
        if(head -> next == NULL) {
                //sngle node in LL
                return head;
        }
    //making dummy nodes
    Node*zerohead = new Node(-101);
    Node*zerotail =zerohead;
    
    Node*onehead = new Node(-101);
    Node*onetail =onehead;
    
    Node*twohead = new Node(-101);
    Node*twotail =twohead;

    Node*curr = head;
    while(curr!=NULL)
    {
        if(curr->data == 0)
        {
            Node*temp = curr;
            curr = curr->next;
            temp->next=NULL;

            //adding temp node in zero dummy node
            zerotail->next = temp;
            zerotail = temp;
        }
        else if(curr->data == 1)
        {
            Node*temp = curr;
            curr = curr->next;
            temp->next=NULL;

            //adding temp node in one dummy node
            onetail->next = temp;
            onetail = temp;
        }
        else if(curr->data ==2)
        {
            Node*temp = curr;
            curr = curr->next;
            temp->next=NULL;

            //adding temp node in two dummy node
            twotail->next = temp;
            twotail = temp;
        }
    }
    //modify one wali list;
    Node*temp = onehead;
    onehead = onehead->next;
    temp->next = NULL;
    delete temp;

    //modify two wali List;
    temp = twohead;
    twohead = twohead->next;
    temp->next = NULL;
    delete temp;

    //join list

    if(onehead!=NULL)
    {
        zerotail->next = onehead;
        if(twohead!=NULL)
        {
            onetail->next=twohead;
        }
    }
    else
    {
        if(twohead!=NULL)
        zerotail->next = twohead;
    }
    //remove zero head dummy node
    temp = zerohead;
    zerohead = zerohead->next;
    temp->next = NULL;
    delete temp;

   // return head of modified linked list
    return zerohead;
}
void print(Node* &head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = new Node(2);
  Node* second = new Node(2);
  Node* third = new Node(1);
  Node* fourth = new Node(1);
  Node* fifth = new Node(0);
  Node* sixth = new Node(0);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  cout << "input LL: ";
  print(head);

//   sortZeroOneTwo(head);
//   print(head);
  
  cout << "printing the sorted list " << endl;
  Node* temp = NULL;
  head = SortList(head);
  //cout << "Came out of sort function" << endl;
  print(head);
  return 0;
}
