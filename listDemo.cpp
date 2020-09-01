#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool createList(Node **head_ref)  
{  
    char choice = 'y';
    int data=0;
    do
    {
        Node *new_node = new Node();  
        
        cout<<"\nEnter data: ";
        cin>>data;
        
        new_node->data = data;  
        new_node->next = (*head_ref);  
        (*head_ref) = new_node; 

        cout<<"\nPress Y/y to enter more. N to break: ";
        cin>>choice;
    } while (choice =='y' || choice == 'Y');
    
    return true;
}
bool insertNode(Node **head,int data,int position)
{
    int k=1;
    Node *p,*q,*new_node;
    new_node=new Node;
    if(!new_node)
    {
        cout<<"\nMemory Error.!!"<<endl;
        return false;
    }
    new_node->data=data;
    p=(*head);

    //Inserting at the first Position
    if(position==1)
    {
        new_node->next=p;
        (*head)=new_node;
    }
    else
    {
        while((p!=NULL) && (k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        q->next=new_node;
        new_node->next=p;
    }
    return true;
}

bool deleteNode(Node **head,int position)
{
    int k=1;
    Node *p,*q;
    if((*head)==NULL)
        return false;
    
    p=*head;

    //Deleting the first Node
    if(position==1)
    {
        (*head)=(*head)->next;
        free(p);
        return true;
    }
    else
    {
        while((p!=NULL) && (k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            cout<<"\n\aInvalid Position"<<endl;
            return false;
        }
        else
        {
            q->next=p->next;
            free(p);
        }
        return true;        
    }  
}

void displayList(Node *head)
{
    cout<<"NULL";
    while(head!=NULL)
    {
        cout<<"-->"<<head->data;
        head=head->next;
    }
}
int main()
{
    Node *head=NULL;
    char choice='Y';
    int mainMenu=1;
    X:
    cout<<"*************************************************************************"<<endl;
    cout<<"\t\t\tMAIN MENU"<<endl;
    cout<<"1.Create a Linked List."<<endl;
    cout<<"2.Insert Node into List."<<endl;
    cout<<"3.Delete Node from List."<<endl;
    cout<<"4.Display Linked List. "<<endl;
    cout<<"5.Exit program."<<endl;
    cin>>mainMenu;

    switch (mainMenu)
    {
        case 1:
            if(createList(&head))
            {   
                cout<<"\nList created Succesfully.."<<endl;
                goto X;
            }
            else
                goto X;
            break;

        case 2:
        do
        {
            
        } while (choice=='Y' || choice =='y');
        
        
        break;

        case 4:
        {
            cout<<"\nThe List is: "<<endl;
            displayList(head);
        }
    
    default:
        break;
    }
}