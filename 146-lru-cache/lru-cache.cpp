class LRUCache {
     class node {
        public : 
          int key , value ;
          node* next ; 
          node* prev;
          node(int key , int value){
             this->key = key ;
             this->value = value ;
             this->next = nullptr;
             this->prev= nullptr;
          }
};
public:
    node* head = new node(-1,-1);
    node* tail=new node(-1,-1);;
    unordered_map<int,node*> mpp;
    int cap=0;
    int count ;
    LRUCache(int capacity) {
           cap = capacity;
           head->next = tail;
           tail->prev = head;
           head->prev = nullptr;
           tail->next = nullptr;
           count =0;
    }
    
    int get(int key) {
        //searching in the map for the key 
        if ( mpp.find(key) == mpp.end())
        return -1;
        node* temp =  mpp.find(key)->second;//key detail most people miss is that every element <key, value> in map or unordered_map is a pair inside so you can access it here with mpp.find(key)-> first and second as mpp.find(key) gives the iterator to the pair
        remove(temp);
        frontinsert(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
          if ( mpp.find(key) != mpp.end()){
                node* temp = mpp.find(key)->second;
                temp->value = value;
                remove(temp);
                frontinsert(temp);
                
          }
        else if ( count == cap )
        {
            node* temp = tail->prev;
          mpp.erase(temp->key);
            temp->value = value;
            temp->key = key;
            remove(temp);
            frontinsert(temp);
            
            mpp[key] = temp;
        }
        else{
        node* temp = new node(key , value);
        frontinsert(temp);
        count++;
        mpp[key] = temp;
        }
        
    }
    void remove ( node * temp){
        node* tempnext = temp->next;
        node* tempprev = temp->prev;
        tempnext->prev = tempprev;
        tempprev->next = tempnext;
        temp->next = nullptr;
        temp->prev = nullptr;
    }
    void frontinsert(node* temp){
        node* realheadnext = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = realheadnext;
        realheadnext->prev = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */