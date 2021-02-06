#include <string>
#include <iostream>
#include "music.cpp"

class Node{
    public:
        Music music_element; //each element of this linked list is a Music object
        Node *next_pointer; //this pointer will be used as a pointer to the next element of the linked list
    //Default constructor?
    //Constructor?
    //Destructor? //como eu testo um destructor?
    //Getters and setters 
};

class LinkedList{
    public: //encapsulamento deve ser no estilo private/public?
        int size;
        Node *head_pointer;
        Node *tail_pointer;
    
        //Constructor
        LinkedList(){
            this->size = 0;
            this->head_pointer = nullptr;
            this->tail_pointer = nullptr;
        }
        //Destructor - como devo fazer isso?
        ~LinkedList(){
            Node* current_pointer = head_pointer;
            while(current_pointer!=nullptr){
                Node* auxiliary_pointer = current_pointer->next_pointer;
                delete current_pointer;
                current_pointer = auxiliary_pointer;
            }
            head_pointer = nullptr;
        }

        /*--------------- Member Functions ---------------*/

        //Getters and setters
        int getSize(void){
            return this->size;
        }

        Node* getHead(void){
            return this->head_pointer;
        }

        Node* getTail(void){
            return this->tail_pointer;
        }
        
        //Insertion of a element
        void addElement(Music new_music){
            //Get music element and create a new node 
            Node* new_node = new Node();
            new_node->music_element = new_music;
            new_node->next_pointer = nullptr;

            Node* auxiliary_pointer = new Node();
            auxiliary_pointer = head_pointer;

            //Checks if list is empty (or not), then insert the new node into it
            if(head_pointer==nullptr && size==0){
                head_pointer = new_node;
                tail_pointer = new_node;
            }else{
                while(auxiliary_pointer->next_pointer!=nullptr){
                    auxiliary_pointer = auxiliary_pointer->next_pointer;
                }
                auxiliary_pointer->next_pointer = new_node;
                tail_pointer = new_node;
            }
            size++;
        }

        void addElementAtFirst(Music new_music){
            addElementAtPosition(new_music,0);
        }

        void addElementAtPosition(Music new_music, int position){
            //Get music element and create a new node 
            Node* new_node = new Node();
            new_node->music_element = new_music;
            new_node->next_pointer = nullptr;

            //If the position is equal the beginning of the linked list
            if(position==0){
                new_node->next_pointer = head_pointer;
                head_pointer = new_node;
            //Otherwise
            }else{
                Node *previous_pointer = new Node();
                Node *current_pointer = new Node();

                current_pointer = head_pointer;

                for(int i=1; i<=position; i++){
                    previous_pointer = current_pointer;
                    current_pointer = current_pointer->next_pointer;
                }

                new_node->next_pointer = current_pointer;
                previous_pointer->next_pointer = new_node;
            }
        }

        //Remotion of a element
        void removeFirstElement(){
            Node *auxiliary_pointer = new Node();
            auxiliary_pointer = head_pointer;
            head_pointer = head_pointer->next_pointer;
            delete auxiliary_pointer;
        }

        void removeLastElement(){
            Node *previous_pointer = new Node();
            Node *current_pointer = new Node();
            current_pointer = head_pointer;

            while(current_pointer->next_pointer!=nullptr){
                previous_pointer = current_pointer;
                current_pointer = current_pointer->next_pointer;
            }
        
            delete current_pointer;
            previous_pointer->next_pointer = nullptr;
            tail_pointer = previous_pointer;
        }

        void removeElementAtPosition(int position){
            if(position==0){
                removeFirstElement();
            }else{
                Node *previous_pointer = new Node();
                Node *current_pointer = new Node();
                current_pointer = head_pointer;

                for(int i=1; i<=position; i++){
                    previous_pointer = current_pointer;
                    current_pointer = current_pointer->next_pointer;
                }

                previous_pointer->next_pointer = current_pointer->next_pointer;
                delete current_pointer;
            }
        }
        //1. remove from front 2. remove from back 3.remove ele at especific position
        
        void displayList(){
            Node* auxiliary_pointer = new Node();
            auxiliary_pointer = head_pointer;
            
            while(auxiliary_pointer!=nullptr){
                std::cout << "-------------------------------------------------------------" << std::endl;
                std::cout << "Track title: " << auxiliary_pointer->music_element.getTitle() << std::endl;
                std::cout << "Track artist: " << auxiliary_pointer->music_element.getArtist() << std::endl;
                std::cout << "-------------------------------------------------------------" << std::endl;
                auxiliary_pointer=auxiliary_pointer->next_pointer;
            }
            delete auxiliary_pointer;
        }

        //reversedisplay list
        //display one particular music
        //display all musics from one artist
};