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

void MainMenu(void);

int main(void){
    LinkedList list;
    int data, choice, run = 1;
    while (run){
        MainMenu();
        std::cout<<"Enter you choice: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                list.print();
                break;
            case 2:
                std::cout<<"Enter enter data: ";
                std::cin>>data;
                std::cout<<"Where do you want to insert data:\n";
                std::cout<<"1. At the beginning\n";
                std::cout<<"2. At the end\n";
                std::cout<<"Enter choice: ";
                std::cin>>choice;
                switch (choice){
                    case 1:
                        list.insertBegining(data);
                        list.print();
                        break;
                    case 2:
                        list.insertEnd(data);
                        list.print();
                        break;
                    default:
                        std::cout<<"Invalid input!\n";
                        run = 0;
                        break;
                }
                break;
            case 3:
                std::cout<<"What do you want to delete:\n";
                std::cout<<"1. Delete beginning\n";
                std::cout<<"2. Delete end\n";
                std::cout<<"3. Delete element\n";
                std::cout<<"Enter choice: ";
                std::cin>>choice;
                switch (choice){
                    case 1:
                        list.deleteBeginning();
                        list.print();
                        break;
                    case 2:
                        list.deleteEnd();
                        list.print();
                        break;
                    case 3:
                        std::cout<<"Enter data: ";
                        std::cin>>data;
                        list.deleteElement(data);
                        list.print();
                        break;
                    default:
                        std::cout<<"Invalid input!\n";
                        run = 0;
                        break;
                }
                break;
            case 4:
                std::cout<<"Enter element to search: ";
                std::cin>>data;
                list.print();
                list.searchElement(data);
                break;
            case 5:
                --run;
                break;
            default:
                std::cout<<"Invalid input!\n";
                break;
        }
    }
    return 0;
}

void MainMenu(void){
    std::cout<<"\n\nWorking with linked lists!!!\n\n";
    std::cout<<"What do you want to do today:\n";
    std::cout<<"1. Print list\n";
    std::cout<<"2. Insert into list\n";
    std::cout<<"3. Delete from list\n";
    std::cout<<"4. Search element in list\n";
    std::cout<<"5. Exit\n";

}
