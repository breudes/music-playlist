#include "./include/linked_list.h"

/*!
    * In this .cpp file is implemented a particular linked list, which each element is a music 
    * object (music class is included), every music object has a track title name and a artist name. 
    * The idea of this list is to have acess of a first element by a 'head' pointer (in this case, a Node pointer),
    * and to have acess of each element until the last one (this as a 'tail' pointer) by others Node pointers. Every pointer its linked
    * because a Node object has a 'next_pointer' propertie, each means the every pointer of a Node class has a link 
    * to its next pointer; the list use this idea to display elements or do some changes of its elements.
*/
    /*--------------- Constructor and Destructor -----------------------------------*/
    //Constructor
    LinkedList::LinkedList(){
        /**
            * Constructs an empty linked list with a default-constructed allocator.
        */
        this->size = 0;
        this->head_pointer = nullptr;
        this->tail_pointer = nullptr;
    }
    
    //Destructor
    LinkedList::~LinkedList(){
        /**
            * Destructs the linked list, i.e., destructs each element of list and stored space is deallocated.
        */
        Node* current_pointer = head_pointer;
        while(current_pointer!=nullptr){
            Node* auxiliary_pointer = current_pointer->next_pointer;
            delete current_pointer;
            current_pointer = auxiliary_pointer;
        }
        head_pointer = nullptr;
    }

    /* ---------------------------- Member functions --------------------------------*/
    
    /* ---------------------------- Getters and setters -----------------------------*/        
    //Get Size
    int LinkedList::getSize(void){
        /**
            * Returns the size, each means, the length of list.
        */
        return this->size;
    }
    
    //Get Head
    Node* LinkedList::getHead(void){
        /**
            * Returns the 'head' pointer, each means, the adress of first element of list.
        */
        return this->head_pointer;
    }
    
    //Get Tail
    Node* LinkedList::getTail(void){
        /**
            * Returns the 'tail' pointer, each means, the adress of last element of list.
        */
        return this->tail_pointer;
    }

    //Set Size 
    void LinkedList::setSize(int new_size){
        /**
            * Set a new size value, each means, refresh the length of list.
            *param 'new_size': an integer value;
        */
        this->size = new_size;
    }
    
    //Set Head
    void LinkedList::setHead(Node *head_new_pointer){
        /**
            * Set a new Node pointer to be acess by the 'head' pointer, each means, a new address referring to the first element of list.
            *param 'head_new_pointer': a Node class's pointer;
        */
        this->head_pointer = head_new_pointer;
    }
    
    //Set Tail
    void LinkedList::setTail(Node *tail_new_pointer){
        /**
            * Set a new Node pointer to be acess by the 'tail' pointer, each means, a new address referring to the last element of list.
            *param 'tail_new_pointer': a Node class's pointer;
        */
        this->tail_pointer = tail_new_pointer;
    }

    /* ---------------------------- Insertion of an element -----------------------------*/
    //Add Element (at Last Position)
    void LinkedList::addElement(Music new_music){
        /**
            * Adds an element at the last position of list. This element is a Music object passed by user input.
            * The previous 'last' element's pointer will have a 'next_pointer' to the new 'last' element's pointer.
            *param 'new_music': a Music class's object;
        */

        //Get music element and create a new node 
        Node* new_node = new Node();
        new_node->music_element = new_music;
        new_node->next_pointer = nullptr;
        //Set a auxiliar_pointer
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

    //Add Element at First (Position)
    void LinkedList::addElementAtFirst(Music new_music){
        /**
            * Adds an element at the first position of list. This element is a Music object passed by user input.
            * The previous 'first' element's pointer will have a 'next_pointer' to the new 'first' element's pointer;
            *param 'new_music': a Music class's object;
        */
        addElementAtPosition(new_music,0);
    }

    //Add Element at Position
    void LinkedList::addElementAtPosition(Music new_music, int position){
        /**
            * Adds an element at a particular position of list. This element is a Music object and the position is an integer value, 
            * both passed by user input; 
            * The previous element's pointer at the particular position will have a 'next_pointer' to the new element's pointer; 
            *param 'new_music': a Music class's object;
            *param 'position': a integer value;
        */
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

    /* ---------------------------- Remotion of an element -----------------------------*/
    //Remove First Element
    void LinkedList::removeFirstElement(){
        /**
            * Removes the first element in list.
        */
        Node *auxiliary_pointer = new Node();
        auxiliary_pointer = head_pointer;
        head_pointer = head_pointer->next_pointer;
        delete auxiliary_pointer;
    }
    
    //Remove Last Element
    void LinkedList::removeLastElement(){
        /**
            * Removes the last element in list.
        */
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

    //Remove element at position
    void LinkedList::removeElementAtPosition(int position){
        /**
            * Removes a element at an especific position in list, this position is an integer value passed by user input;
            *param 'position': an integer value.
        */
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

    /* ---------------------------- Display of elements -----------------------------*/
    //Display List 
    void LinkedList::displayList(){
        /**
            * Display all elements of list.
        */
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

    //Display One Element 
    void LinkedList::displayOneElement(int position){
        /**
            * Display the element at an especific position in list, this position is an integer value 
            * passed by user input;
            *param 'position': an integer value.
        */
        Node *current_pointer = new Node();
        current_pointer = head_pointer;

        for(int i=1; i<=position; i++){
            if(current_pointer==nullptr) break;
            current_pointer = current_pointer->next_pointer;
        } 
        if(current_pointer!=nullptr){
            std::cout << "------------ Track at "<< position << " ---------------------" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Track title: " << current_pointer->music_element.getTitle() << std::endl;
            std::cout << "Track artist: " << current_pointer->music_element.getArtist() << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }else{
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Invalid index of linked list. Try another position!" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }
        delete current_pointer;
    }
    
    //Display First Element
    void LinkedList::displayFirstElement(){
        /**
            * Display the first element of the list. Its pointer is allocated at 'head_pointer' (a Node pointer).
        */
        std::cout << "------------ Track at the beginning of list -----------------" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Track title: " << head_pointer->music_element.getTitle() << std::endl;
        std::cout << "Track artist: " << head_pointer->music_element.getArtist() << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }

    //Display Last Element
    void LinkedList::displayLastElement(){
        /**
            * Display the last element of the list. Its pointer is allocated at 'tail_pointer' (a Node pointer).
        */
        std::cout << "------------ Track at the end of list -----------------------" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Track title: " << tail_pointer->music_element.getTitle() << std::endl;
        std::cout << "Track artist: " << tail_pointer->music_element.getArtist() << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }