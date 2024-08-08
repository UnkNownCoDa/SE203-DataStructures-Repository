#include <iostream>

class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int add){
        this->data = add;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *head;
    LinkedList(){
        this->head = NULL;
    }
    LinkedList(int data){
        this->head = new Node(data);
    }
//Print function
    void print(){
        Node *ptr;
        if (this->head == NULL){
            std::cout<<"\n\nList: Empty\n\n";
            return;
        }
        ptr = this->head;
        std::cout<<"\n\nList: ";
        while (ptr->next != NULL){
            std::cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
        std::cout<<ptr->data<<"->END\n\n";
    }
//Insert functions
    void insertEnd(int data){
        Node *ptr;
        if (this->head == NULL){
            this->head = new Node(data);
            return;
        }
        for (ptr = this->head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = new Node(data);
        return;
    }

    void insertBegining(int data){
        Node *ptr;
        ptr = new Node(data);
        if (this->head == NULL){
            this->head = ptr;
            return;
        }
        ptr->next = this->head;
        this->head = ptr;
    }
//Delete functions
    void deleteEnd(void){
        Node *ptr;
        if (this->head == NULL){
            std::cout<<"List is already empty!\n";
            return;
        }
        for (ptr = this->head; ptr->next->next != NULL; ptr = ptr->next);
        delete ptr->next->next;
        ptr->next = NULL;
    }

    void deleteBeginning(void){
        Node *ptr;
        ptr = this->head->next;
        delete this->head;
        this->head = ptr;
    }

    void deleteElement(int data){
        Node *ptr, *nextPtr;
        ptr = this->head;
        if (ptr == NULL){
            std::cout<<"List is already empty!\n";
            return;
        }
        if (ptr->data == data){
            deleteBeginning();
            return;
        }
        for (nextPtr = ptr->next; nextPtr->next != NULL; nextPtr = ptr->next ){
            
            if (nextPtr->data == data){
                ptr->next = nextPtr->next;
                delete nextPtr;
                return;
            }
            ptr = nextPtr;
        }
        if (nextPtr->data == data){
            deleteEnd();
            return;
        }
        std::cout<<"Element not found!\n";
        return;
    }
//search function
    void searchElement(int data){
        Node *ptr;
        if (this->head == NULL){
            std::cout<<"List is empty!\n";
            return;
        }
        for (ptr = this->head; ptr->next != NULL; ptr = ptr->next){
            if (ptr->data == data){
                std::cout<<"Element is in the list\n";
                return;
            }
        }
        if (ptr->data == data){
            std::cout<<"Element is in the list\n";
            return;
        }
        std::cout<<"Element is not in the list!\n";
        return;
    }
};
int main(){
    LinkedList list;
    int target;

    for (int i = 10; i > 0; --i){
        list.insertBegining(i);
    }
    list.print();
    std::cout<<"Enter element to search: ";
    std::cin>>target;
    list.searchElement(target);
    return 0;
}
