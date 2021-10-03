#Represent a node of doubly linked list    
class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.previous = None;    
        self.next = None;    
            
class MinMax:    
    #Represent the head and tail of the doubly linked list    
    def __init__(self):    
        self.head = None;    
        self.tail = None;    
            
    #addNode() will add a node to the list    
    def addNode(self, data):    
        #Create a new node    
        newNode = Node(data);    
            
        #If list is empty    
        if(self.head == None):    
            #Both head and tail will point to newNode    
            self.head = self.tail = newNode;    
            #head's previous will point to None    
            self.head.previous = None;    
            #tail's next will point to None, as it is the last node of the list    
            self.tail.next = None;    
        else:    
            #newNode will be added after tail such that tail's next will point to newNode    
            self.tail.next = newNode;    
            #newNode's previous will point to tail    
            newNode.previous = self.tail;    
            #newNode will become new tail    
            self.tail = newNode;    
            #As it is last node, tail's next will point to None    
            self.tail.next = None;    
                
    #MinimumNode() will find out minimum value node in the list    
    def minimumNode(self):    
        #Node current will point to head    
        current = self.head;    
            
        #Checks if list is empty    
        if(self.head == None):    
            print("List is empty");    
            return 0;    
        else:    
            #Initially, min will store the value of head's data    
            min = self.head.data;    
            while(current != None):    
                #If value of min is greater than current's data    
                #Then, replace value of min with current node's data    
                if(min > current.data):    
                    min = current.data;    
                current = current.next;    
        return min;    
            
    #MaximumNode() will find out maximum value node in the list    
    def maximumNode(self):    
        #Node current will point to head    
        current = self.head;    
            
        #Checks if list is empty    
        if(self.head == None):    
            print("List is empty");    
            return 0;    
        else:    
            #Initially, max will store the value of head's data    
            max = self.head.data;    
            #If value of max is lesser than current's data    
            #Then, replace value of max with current node's data    
            while(current != None):    
                if(current.data > max):    
                    max = current.data;    
                current = current.next;    
        return max;    
                
dList = MinMax();    
#Add nodes to the list    
dList.addNode(5);    
dList.addNode(7);    
dList.addNode(9);    
dList.addNode(1);    
dList.addNode(2);    
     
#Prints the minimum value node in the list    
print("Minimum value node in the list: "+ str(dList.minimumNode()));    
#Prints the maximum value node in the list    
print("Maximum value node in the list: "+ str(dList.maximumNode()));   
