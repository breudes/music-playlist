#include "../include/linked_list.h"

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
            Node* auxiliary_pointer = current_pointer->getNextPointer();
            delete current_pointer;
            current_pointer = auxiliary_pointer;
        }
        head_pointer = nullptr;
    }

    /* ---------------------------- Member functions --------------------------------*/
    
    /* ---------------------------- Getters and setters -----------------------------*/        
    //Get Size
    int LinkedList::getSize(void) const{
        /**
            * Returns the size, each means, the length of list.
            * @return int: the length of list (an integer value).
        */
        return this->size;
    }
    //Get Head
    Node* LinkedList::getHead(void) const {
        /**
            * Returns the 'head' pointer, each means, the adress of first element of list.
            * @return Node*: head pointer of list (node pointer).
        */
        return this->head_pointer;
    }
    //Get Tail
    Node* LinkedList::getTail(void) const {
        /**
            * Returns the 'tail' pointer, each means, the adress of last element of list.
            * @return Node*: tail pointer of list (node pointer).
        */
        return this->tail_pointer;
    }
    //Set Size 
    void LinkedList::setSize(int new_size){
        /**
            * Set a new size value, each means, refresh the length of list.
            * @param new_size: new length of list (an integer value).
        */
        this->size = new_size;
    }
    //Set Head
    void LinkedList::setHead(Node *head_new_pointer){
        /**
            * Set a new Node pointer to be acess by the 'head' pointer, each means, a new address referring to the first element of list.
            * @param head_new_pointer: Node class's pointer.
        */
        this->head_pointer = head_new_pointer;
    }
    //Set Tail
    void LinkedList::setTail(Node *tail_new_pointer){
        /**
            * Set a new Node pointer to be acess by the 'tail' pointer, each means, a new address referring to the last element of list.
            * @param tail_new_pointer: Node class's pointer.
        */
        this->tail_pointer = tail_new_pointer;
    }

    /* ---------------------------- Insertion of an element -----------------------------*/
    //Add Element (at Last Position)
    void LinkedList::addElement(Music new_music){
        /**
            * Adds an element at the last position of list. This element is a Music object passed by user input.
            * The previous 'last' element's pointer will have a 'next_pointer' to the new 'last' element's pointer.
            * @param new_music: new Music class's object.
        */

        //Get music element and create a new node 
        Node* new_node = new Node();
        new_node->setMusicElement(new_music);
        new_node->setNextPointer(nullptr);
        //Set a auxiliar_pointer
        Node* auxiliary_pointer = head_pointer;
        //Checks if list is empty (or not), then insert the new node into it
        if(head_pointer==nullptr && size==0){
            head_pointer = new_node;
            tail_pointer = new_node;
        }else{
            while(auxiliary_pointer->getNextPointer()!=nullptr){
                auxiliary_pointer = auxiliary_pointer->getNextPointer();
            }
            auxiliary_pointer->setNextPointer(new_node);
            tail_pointer = new_node;
        }
        size++;
    }
    //Add Element at First (Position)
    void LinkedList::addElementAtFirst(Music new_music){
        /**
            * Adds an element at the first position of list. This element is a Music object passed by user input.
            * The previous 'first' element's pointer will have a 'next_pointer' to the new 'first' element's pointer;
            * @param new_music: new Music class's object.
        */
        addElementAtPosition(new_music,0);
    }

    //Add Element at Position
    void LinkedList::addElementAtPosition(Music new_music, int position){
        /**
            * Adds an element at a particular position of list. This element is a Music object and the position is an integer value, 
            * both passed by user input; 
            * The previous element's pointer at the particular position will have a 'next_pointer' to the new element's pointer; 
            * @param new_music: new Music class's object;
            * @param position: position of the song (an integer value).
        */
        //Get music element and create a new node 
        Node* new_node = new Node();
        new_node->setMusicElement(new_music);
        new_node->setNextPointer(nullptr);
        //If the position is equal the beginning of the linked list
        if(position==0){
            if(head_pointer!=nullptr) new_node->setNextPointer(head_pointer);
            head_pointer = new_node;
            tail_pointer = new_node;
        //Otherwise
        }else{
            Node *current_pointer = head_pointer;
            Node *previous_pointer = current_pointer;
            for(int i=1; i<=position; i++){
                previous_pointer = current_pointer;
                current_pointer = current_pointer->getNextPointer();
            }

            new_node->setNextPointer(current_pointer);
            previous_pointer->setNextPointer(new_node);
        }
        size++;
    }

    /* ---------------------------- Remotion of an element -----------------------------*/
    //Remove Element By Name
    int LinkedList::removeElementByName(Music new_music){
        /**
            * Removes a element at list, this element is music object (with title and artist to search to) passed by user input;
            * @param new_music: music object to be removed of list.
            * @return: number of songs deleted.
        */
        Node *current_pointer = head_pointer;
        Node *previous_pointer = current_pointer;

        while(current_pointer!=nullptr){
            if(current_pointer==nullptr) break;
            if( current_pointer->getMusicElement().getTitle() == new_music.getTitle() && current_pointer->getMusicElement().getArtist() == new_music.getArtist() ) break;
            previous_pointer = current_pointer;
            current_pointer = current_pointer->getNextPointer();

        }

        if(current_pointer!=nullptr){
            previous_pointer->setNextPointer(current_pointer->getNextPointer());
            if(current_pointer==head_pointer) head_pointer = current_pointer->getNextPointer();
            if(current_pointer==tail_pointer){
                previous_pointer->setNextPointer(nullptr);
                tail_pointer = previous_pointer;
            }
            free(current_pointer);
            --size;
            return 1;
        }  
        return 0;
    }
    /* ---------------------------- Display of elements -----------------------------*/
    //Get One Element Node
    Node* LinkedList::getOneElementNode(Music new_music){
        /** Returns a node pointer based on a music object passed as user input.
          * @param new_music: music object.
          * @return: node pointer.
        */
        Node *current_pointer = new Node();
        current_pointer = head_pointer;

        while(current_pointer!=nullptr){
            if( current_pointer->getMusicElement().getTitle() == new_music.getTitle() && 
            current_pointer->getMusicElement().getArtist() == new_music.getArtist()){
                break;
            }
            current_pointer = current_pointer->getNextPointer();
        }
        return current_pointer;
    }
    //Display List 
    void LinkedList::displayList(){
        /**
            * Display all elements of list.
        */
        Node* auxiliary_pointer = new Node();
        auxiliary_pointer = head_pointer;  
        
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "                       ALL SONGS                             " << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        while(auxiliary_pointer!=nullptr){
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Track title: " << auxiliary_pointer->getMusicElement().getTitle() << std::endl;
            std::cout << "Track artist: " << auxiliary_pointer->getMusicElement().getArtist() << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            auxiliary_pointer=auxiliary_pointer->getNextPointer();
        }
        free(auxiliary_pointer);
    }

    //Display One Element 
    void LinkedList::displayOneElement(int position){
        /**
            * Display the element at an especific position in list, this position is an integer value 
            * passed by user input;
            * @param position: position of the song (an integer value).
        */
        Node *current_pointer = new Node();
        current_pointer = head_pointer;

        for(int i=1; i<=position; i++){
            if(current_pointer==nullptr) break;
            current_pointer = current_pointer->getNextPointer();
        } 
        if(current_pointer!=nullptr && current_pointer->getMusicElement().getTitle()!=""){
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Track title: " << current_pointer->getMusicElement().getTitle() << std::endl;
            std::cout << "Track artist: " << current_pointer->getMusicElement().getArtist() << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }else{
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Invalid index of linked list. Try another position!" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }
        free(current_pointer);
    }
    //Display One Element
    void LinkedList::displayOneElement(Music new_music){
        /**
            * Display the element by its particular title and artist music's properties in list, passed by user input;
            * @param new_music: music object to search on system.
        */
        Node *current_pointer = new Node();
        current_pointer = head_pointer;

        while(current_pointer!=nullptr){
            if( current_pointer->getMusicElement().getTitle() == new_music.getTitle() && 
            current_pointer->getMusicElement().getArtist() == new_music.getArtist()){
                std::cout << "-------------------------------------------------------------" << std::endl;
                std::cout << "Track title: " << current_pointer->getMusicElement().getTitle() << std::endl;
                std::cout << "Track artist: " << current_pointer->getMusicElement().getArtist() << std::endl;
                std::cout << "-------------------------------------------------------------" << std::endl;
                break;
            }
            current_pointer = current_pointer->getNextPointer();
        }
        if(current_pointer==nullptr){
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Invalid index of linked list. Try another position!" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }
        free(current_pointer);
    }
    //Display First Element
    void LinkedList::displayFirstElement(){
        /**
            * Display the first element of the list. Its pointer is allocated at 'head_pointer' (a Node pointer).
        */
        std::cout << "------------ Track at position 0 -----------------" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Track title: " << head_pointer->getMusicElement().getTitle() << std::endl;
        std::cout << "Track artist: " << head_pointer->getMusicElement().getArtist() << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    //Display Last Element
    void LinkedList::displayLastElement(){
        /**
            * Display the last element of the list. Its pointer is allocated at 'tail_pointer' (a Node pointer).
        */
        std::cout << "------------ Track at the end of list -----------------------" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Track title: " << tail_pointer->getMusicElement().getTitle() << std::endl;
        std::cout << "Track artist: " << tail_pointer->getMusicElement().getArtist() << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }


    /*===================== (New) Methods required by second task (with this project) ======================= */

    void LinkedList::addElement(const LinkedList& new_list){
        /**
            * Adds all songs of a linked list passed as parameter on this linked list. The given linked list is passed by
            * reference.
            * @param 'new_list': a const LinkedList reference.
        */
        if(new_list.getSize()>0){
            Node *new_node = new_list.getHead();

            while(new_node!=nullptr){
                this->addElement(new_node->getMusicElement());
                new_node = new_node->getNextPointer();
            }
        }else return;
    }
    //Remove Element By Name (With LinkedList object as parameter)
    void LinkedList::removeElementByName(const LinkedList &new_list){
        /**
            * Removes all songs on this list that are the same songs on a linked list passed by reference.
            * @param 'new_list': a const LinkedList reference.
        */
        if(new_list.getSize()>0){
            Node *new_node = new_list.getHead();

            while(new_node!=nullptr){
                this->removeElementByName(new_node->getMusicElement());
                new_node = new_node->getNextPointer();
            }
        }
    } 

    //Constructor by Copy
    LinkedList::LinkedList(const LinkedList &new_list){
        /**
            * Constructs a linked list with another linked list, i.e., by copying all songs from this list passed by reference.
            * @param 'new_list': a const LinkedList reference.
        */
        this->setSize(0);
        this->setHead(nullptr);
        this->setTail(nullptr);
        
        if(new_list.getSize()>0){
            Node *new_node = new_list.getHead();

            while(new_node!=nullptr){
                this->addElement(new_node->getMusicElement());
                new_node = new_node->getNextPointer();
            }
        }
    } 

    //Overload of + operator
    LinkedList LinkedList::operator+(const LinkedList& new_list){
        /**
            * Create a new linked list and adds all songs within this linked list and another linked list, this last list
            * passed by reference, thus, returns the new linked list. This method is executed by overloading the '+' operator.
            * @param 'new_list': a const LinkedList reference;
            * @return: a (new) LinkedList object.
        */
        LinkedList thirdList;
        Node *new_node = this->getHead();
        
        while(new_node!=nullptr){
            Node *node_pointer = new Node();
            node_pointer = new_node;
            thirdList.addElement(node_pointer->getMusicElement());
            new_node = new_node->getNextPointer();
            thirdList.size++;
        }

        new_node = new_list.getHead();

        while(new_node!=nullptr){
            Node *node_pointer = new Node();
            node_pointer = new_node;
            thirdList.addElement(node_pointer->getMusicElement());
            new_node = new_node->getNextPointer();
            thirdList.size++;
        }

        return thirdList;
    }
    
    //Overload of >> operator
    void LinkedList::operator>>(Node* &tail_pointer){
        /**
            * Adds a new song (within the last position of this linked list) on a Node pointer's adress. 
            * This operation is executed by overloading the '>>' operator and the given node is passed by reference.
            * @param 'tail_pointer': a node reference.
        */
        if(this->getSize()>0){
            tail_pointer->setMusicElement(this->getTail()->getMusicElement());
            tail_pointer->setNextPointer(this->getTail()->getNextPointer());
            this->removeElementByName(this->getTail()->getMusicElement());
        }else{
            tail_pointer = nullptr;
        }
    }
    
    //Overload of << operator
    void LinkedList::operator<<(const Node* new_pointer){
        /**
            * Adds a new song (passed within a node pointer) at the end of this linked list. This operation is executed
            * by overloagind the '<<' operator.
            * @param 'new_pointer': a const node pointer.
        */
        if(new_pointer!=nullptr){
            this->addElement(new_pointer->getMusicElement());
        }else return;
    }