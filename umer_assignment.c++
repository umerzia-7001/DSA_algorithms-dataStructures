
#include <iostream>
#include <string>
#include "list"

using namespace std;





class RoundRobinAlgo {

    private:
        struct Node{
            string processName;
            int timeLength;
            struct Node* nextNodePtr;
        };
        Node* head;
   
public:


    void addProcess(const string& processName, int time) {
        Node *newNode, *nodePtr;

        newNode = new Node;
        newNode->timeLength = time;
        newNode->processName = processName;

        if (head == nullptr){
            head = newNode;
        } else {
            nodePtr = head;
            while(nodePtr->nextNodePtr != head){
                nodePtr = nodePtr->nextNodePtr;
            }
            nodePtr->nextNodePtr = newNode;
        }
        newNode->nextNodePtr = head;

    }

    void display(){
        if (!head){
            cout << "No Process to Be Executed\n";
            return;
        }
    
        Node *nodePtr;
        nodePtr = head;
        while(nodePtr->nextNodePtr != head){
        
            nodePtr = nodePtr->nextNodePtr;
        }

    }

    void deleteProcess(const string& processName) {
        Node *nodePtr, *previousNode;
        if (head == nullptr){
            return;
        }if (head->processName == processName){
            if (head->nextNodePtr == head){
                delete head;
                head = nullptr;
                return;
            } else {
                previousNode = head;
                while (previousNode->nextNodePtr != head) {
                    previousNode = previousNode->nextNodePtr;
                }
                nodePtr = head->nextNodePtr;
                delete head;
                head = nodePtr;
                previousNode->nextNodePtr = head;
            }
        }else{
            nodePtr = head;
            while(nodePtr != nullptr && nodePtr->processName != processName){
                previousNode = nodePtr;
                nodePtr = nodePtr->nextNodePtr;
            }
            previousNode->nextNodePtr = nodePtr->nextNodePtr;
            delete nodePtr;
        }
    }

    void process() {
        Node *temp, *currentProcess;
        currentProcess = head;
        while(head){
            cout << "\n Processing " << currentProcess->processName ;
            
            currentProcess->timeLength -= 5;
            if (currentProcess->timeLength <= 0) {
                temp = currentProcess;
                currentProcess = currentProcess->nextNodePtr;
                cout << "\nProcess " << temp->processName << " Finished.\n";
                deleteProcess(temp->processName);
                display();
            }else{
                currentProcess = currentProcess->nextNodePtr;
            }
        }
}
};

int main(){
    RoundRobinAlgo pl;
    pl.addProcess("L", 15);
    pl.addProcess("M", 6);
    pl.addProcess("N", 10);
    pl.addProcess("O", 8);
    pl.display();
    pl.process();



    return 0;
};