#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class DoubleCircularList
{
    public:
	int counter = 0;

	/*
	 * Node Declaration
	 */
	struct node{
		int info;
		struct node *next;
		struct node *prev;
	}*start, *last;

        DoubleCircularList(){
            start = NULL;
            last = NULL;
        }

		/*
		 *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
		 */
		 node* createNode(int value){
			struct node *temp;
            temp->info = value;
            temp->next = start;
            temp->prev = last;
            
			
			return temp;
		}
		/*
		 *INSERTS ELEMENT AT BEGINNING
		 */
		void insertAtStart(){
			int value;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;
            // making node from createNode function
            node *node1 = createNode(value);

			if(start==last && start==NULL){
                start=last=node1;
                node1->next= NULL;
                node1->prev=NULL;

            }
            else{
                node1->next=start;
                //node1.prev=last;
                start=node1;
                start->prev=node1;
                start->prev=last;
                last->next=start;

            }

			
		}

		/*
		 *INSERTS ELEMNET AT LAST
		 */
		void insertLast(){
			int value;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;
			node *node2 = createNode(value);

			if(start==last && start==NULL){
                start=last=node2;
                node2->next= NULL;
                node2->prev=NULL;

            }
            else{
                last->next=node2;
                node2->prev=last;
                last=node2;
                last->next=start;
                start->prev=last;
                
            }
			
		}
        void insertAtPos(){

			int value, pos, i;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;
			cout<<endl<<"Enter the postion of element inserted: ";                      
			cin>>pos;

            if(pos==0){
                insertAtStart();
            }
            else if(!start){
                cout<<" Insertion not possible"<<endl;

            }
            else{
                int counter=0;
                 // creating temp pointer
                node* ptr;
                node *nextptr;

                ptr=start;
                nextptr=start;
                node *temp=createNode(value);

                for(i=0;i<pos;i++){

                    ptr=ptr->next;
                    nextptr=nextptr->next;

                    if(ptr->next==start){
                        cout<<"Insertion not possible"<<endl;
                    }
                    else{
                        ptr->next=nextptr;
                        ptr->next=temp;
                        nextptr->prev=temp;
                        temp->next=nextptr;
                        temp->prev=ptr;

                    }


                }
            }
		
		/*
		 * Delete Node at Particular Position
		 */
		void deleteAtPos()
		{
			int pos, i;
			node *ptr, *s;
			if (start == last && start == NULL)
			{
				cout<<"List is empty, nothing to delete"<<endl;
				return;
			}
			cout<<endl<<"Enter the postion of element to be deleted: ";
			cin>>pos;

            ptr=start;
            int counter=0;
            while(counter<=pos){
                ptr=ptr->next;
                counter++;
                if(ptr->next==start){
                    ptr->prev=start;

                    delete ptr;
                }

                else {
                    ptr->prev=ptr->prev->next;
                    ptr->next=NULL;
                    ptr->next->prev=ptr->prev;

                    delete ptr;

                
                }
            

		}
        }
		/*
		 * Display Elements of the List
		 */
		void display(){
            node *ptr;
            ptr=start;
			
            if(start==last && start==NULL){
                cout<<" No items to display "<<endl;

            }
            else{
                while(ptr->next!=start){

                    cout<<ptr->info<<endl;
                    ptr=ptr->next;

                }
            }
		}

};

/*
 * Main: Contains Menu
 */
int main(){
    int userChoice;
    DoubleCircularList cdl;
    while (1){
        cout<<"\n-------------------------------"<<endl;
        cout<<"Operations on Doubly Circular linked list"<<endl;
        cout<<"\n-------------------------------"<<endl;
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at Last"<<endl;
        cout<<"3.Insert at Specific Position"<<endl;
        cout<<"4.Delete at Specific Position"<<endl;
        cout<<"5.Display List"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>userChoice;
        switch(userChoice){
        case 1:
            cdl.insertAtStart();
            break;
        case 2:
            cdl.insertLast();
            break;
        case 3:
            cdl.insertAtPos();
            break;
        case 4:
            cdl.deleteAtPos();
            break;
        case 5:
            cdl.display();
            break;
        case 6:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
};
