#include <iostream>
using namespace std;
class node{
      public:
      node * next;
      int val;

      // constructor
      node(int newvalue)
      {val = newvalue;
       next = NULL;
      }
};
// class linkedlist
class linkedlist{
      public:
      node * head;

      // constructor
      linkedlist(){
                head = NULL;
      }
//insert function
void insert(int newvalue){
        node * temp = new node(newvalue);
        temp->next = head;
        head = temp;
      }

//display
void display(){
    node * current = head;
    while(current !=NULL){
        cout << current->val<< "->";
        current = current-> next;
   }
   cout<< " NULL" << endl;
}
//count
int numberofItems(){
    //start at head
    node * current = head;
    int count= 0;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}
node * getPos(int pos){

      node * current = head;
     int cnt = 0;
     while(cnt < (pos-1)){
         current = current ->next;
         cnt++;
     }
     return current;
}

//insert at any given position
void insertAt(int val, int pos){
    // Check validity of pos.

    if(pos < 1 || (pos > (numberofItems()+1))){
        cout << "Not a valid position" << endl;
        return;
    }

    // Reach to pos-1
    node * current = getPos(pos-1);

    //Links update
    if(pos==1)
    insert(val);

    else{
        //create a new node
       node * temp = new node(val);
       temp-> next = current->next;
       current -> next = temp;
}
}
//delete function
void delet(){
   if (head == NULL){}
   else {
   node * current = head;
   head = current->next;
   delete current;
   }
}
//delete at any given positions
void deleteat(int pos){
   if (pos == 1){
   delet();
   }
   else{
   node * current = head;
   int i(1);
   while( i !=pos-1){
          current = current->next;
          i++;
          }
   node * t;
   t = current-> next;
   current->next = current->next->next;
   delete t;
   }
}


 };
int main(){
    linkedlist l1;
    for (int i=10 ; i>0 ; i--){
         l1.insert(i);
    }
    l1.display();
    cout << "numberofItems: "<<l1.numberofItems() << endl;
    cout << l1.getPos(10)->val <<endl;
    l1.insertAt(11,11);
    l1.display();
    l1.insertAt(10,1);
    l1.display();
    l1.deleteat(2);
    l1.display();
    l1.deleteat(1);
    l1.display();
return 0;
}

