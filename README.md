# Links in a Chain
## by A.J. L.

### Summary
This is a header and test program written in c++ that implements methods regarding making a linked list of "LinkedChains." Each node consists of a pair of pointers, one pointing up the chain the other pointing down the chain, and a referance to a "Chainlink" object.   

### A ChainLink object has the following:
- #### public
    - ChainLink(std::string color)
        - The default constructer, is intended to be used to create a "ChainLink" object with the specified color member.
    - std::string get_Color()
        - Returns the value of the "color" member
- #### private
    - std::string color
        - The "color" of this link of chain.

 
### A LinkedChain object has the following:
- #### public
    - LinkedChain(ChainLink* chain_link)
        - The default constructer, is intended to be used to make the head of the list when making the list all at once, or to create the links when using the "push_front" and "push_back" methods.
    - LinkedChain(ChainLink* chain_link, LinkedChain* prev_link)
        - A constucter intended to be used when making the list all at once.
    - LinkedChain* next()
        - Returns a referance to the next link in the list. But if this is tail of the list returns a "nullptr."
    - LinkedChain* prev()
        - Returns a referance to the previous link in the list. But if this is the head of the list returns a "nullptr."
    - ChainLink* data()
        - Returns a referance to the "ChainLink" object that is held by this link.
    - int size()
        - Returns an integer indicating how many links are further down the chain.
    - void push_Back(LinkedChain* next_link)
        - Appends the "next_link" object to the list, by setting this list's tail's "up_link" member to "next_link," and "next_link's" "down_link" member to the previous tail. 
    - void push_Front(LinkedChain* prev_link)
        - Prepends the "prev_link" object to the list, by setting the this list's head's "up_link" member to "prev_link," and "prev_link's" "up_link" member to the previous head. 
    - bool operator==(LinkedChain* other)
        - Defines what it means for two LinkedChain objects to be equal, by returning weather or not the memory adresses are the same.
- #### private
    - int size(int count)
        - Used in the recursion that makes the "size" method work. If this is not the tail then it inrements count and calls size(incremented count) on "up_link." 
    - ChainLink* chain_link
        - A referance to the "ChainLink" object held as the data for this entry in the list. 
    - LinkedChain* up_link
        - A referance to the next entry in the list.
    - LinkedChain* down_link
        - A referance to the previous entry in the list.

### Compilation
To complile the test program, that preforms unit tests on all the new methods, use the command
> make 1

To compile the example program, that preforms the example provided at https://cyrusvandrevala.com/teaching/csc/122/labs/links-in-a-chain.html, use the command
> make 3

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/qcYcpcX7)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=17230895&assignment_repo_type=AssignmentRepo)
