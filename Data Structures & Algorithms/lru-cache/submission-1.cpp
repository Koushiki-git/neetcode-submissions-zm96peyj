class LRUCache {
public:
    struct Node{
        int key,val;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=nullptr;
        }
    };
    int cap;
    unordered_map<int,Node*> mpp;
    Node* head;//dummy
    Node* tail;//dummy
    
     
    //Constructor
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);//create dummy head and tail

        head->next=tail;
        tail->prev=head;
    }
    //remove the node
    void remove(Node* node){
        Node* p=node->prev;
        Node* n=node->next;
        p->next=n;
        n->prev=p;
    }
    //insert after head as it is most recently used(MRU)
    void insert(Node* node){
        //H--T   // H -- node -- T
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;

    }
    
    int get(int key) {
        //if key not present
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node = mpp[key];

        remove(node);
        insert(node);//move to front

        return node->val;
        
    }
    
    void put(int key, int value) {
        //if it exists
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;//update the value;

            remove(node);
            insert(node);//insert to front


        }
        else{
            if(mpp.size()==cap){
                Node* lru=tail->prev;
                remove(lru);
                mpp.erase(lru->key);
            }
            //create new node
            Node* node=new Node(key,value);
            insert(node);
            mpp[key]=node;
        }
        
    }
};
