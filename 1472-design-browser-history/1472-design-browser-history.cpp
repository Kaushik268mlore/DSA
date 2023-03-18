class doubly{
       public:
       string s;
       doubly *next,*prev;
       doubly(string url){
           s=url;
           prev=NULL;
           next=NULL;
       }
   };

class BrowserHistory {
public:
    //these design based questions are juat amazing, I knew that the browsor history is implemented using the linkedlists
    doubly *node,*curr;
    BrowserHistory(string homepage) {
        node=new doubly(homepage);
        curr=node;
    }
    
    void visit(string url) {//creating a new node for the new URL being visited, then we also assign the next and prev nodes to the existing curr and the next to the new node and then the current to the  new node as well, as that will be the present page .
        doubly *NewNode= new doubly(url);
        curr->next=NewNode;
        NewNode->prev=curr;
        curr=NewNode;
    }
    
    string back(int steps) {//very easy implementation of the back opertion.
        while(steps&&curr->prev){
            curr=curr->prev;
            steps--;
        }
        return curr->s;
    }
    
    string forward(int steps) {
        while(steps&&curr->next){
            curr=curr->next;
            steps--;}
    return curr->s;
        }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */