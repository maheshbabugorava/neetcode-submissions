struct node{
    int value;
    node* ptr;
};


class LinkedList {

    node* head = nullptr;
    node* tail = nullptr;

    int numNodes{0};

public:
    LinkedList() {
        numNodes = 0;
    }

    int get(int index) {
        if(index < 0 || index >= numNodes){
            return -1;
        }

        node* temp = head;

        for(int i = 0; i < index; i++){
            temp = temp->ptr;
        }

        return temp->value;
    }

    void insertHead(int val) {
       
        node* firstone = new node;
        firstone->value = val;
        firstone->ptr = head;
        head = firstone;

        numNodes++;

        if(numNodes == 1){
            tail = head;
        }
    }
    
    void insertTail(int val) {
        node* lastone = new node;
        lastone->value = val;
        lastone->ptr = nullptr;
        
        if (tail) {
            tail->ptr = lastone;
        }
        tail = lastone;

        numNodes++;

        if(numNodes == 1){
            head = tail;
        }
    }

    bool remove(int index) {

        if(index < 0 || index >= numNodes){
            return false;
        }

        
        node* temp = head;

        if(index == 0){
            head = temp->ptr;
            if (numNodes == 1) tail = nullptr;
            delete temp;
            numNodes--;
            return true;
        }

        node *tempPrev = nullptr;


        for(int i = 0; i < index; i++){
            tempPrev = temp;
            temp = temp->ptr;
        }

        tempPrev->ptr = temp->ptr;
        if (temp == tail) tail = tempPrev;
        delete temp;
        numNodes--;

        return true;

    }

    vector<int> getValues() {
        vector<int> returnArr;

        node* temp = head;
        for(int i = 0; i < numNodes; i++){
            returnArr.push_back(temp->value);
            temp = temp->ptr;
        }

        return returnArr;
    }
};