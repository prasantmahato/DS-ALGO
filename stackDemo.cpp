#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{   Node *top;  };

typedef struct Stack STACK;

//INITIALIZE THE STACK WITH NULL VALUE
bool stackInit(STACK *s)
{   s->top=NULL;    }

//DETERMINE STACK IS EMPTY OR NOT     
bool stackEmpty(STACK *s)
{
    return (s->top==NULL);
}

//EXAMINE THE TOP VALUE
bool stackTop(STACK *s,int &info)
{
    if(stackEmpty(s))
        return false;
    else
    {
        info=s->top->data;
        return true;
    }
}

//PUSH DATA INTO THE STACK
bool stackPush(STACK *s,int &info)
{
    Node *temp;
    temp = new Node;
    temp->data=info;

    if(s->top!=NULL)
    {
        temp->next=s->top;
        s->top=temp;
    }
    else
    {
        s->top=temp;
        s->top->next=NULL;
    }
    return true;
}

//POP DATA FROM THE STACK
bool stackPop(STACK *s,int &info)
{
    Node *temp;
    if(stackEmpty(s))
        return false;
    else
    {
        temp=s->top;
        s->top=s->top->next;
        info=temp->data;
        free(temp);
        return true;
    }
}

int main()
{
    STACK s1;
    int element;
    char choice='Y';
    int menuChoice=0;
    stackInit(&s1);

    X:
    cout<<"***********************************************************************"<<endl;
    cout<<"\t\t\tMAIN MENU "<<endl;
    cout<<"1.PUSH ELEMENT IN STACK "<<endl;
    cout<<"2.POP ELEMENT FROM STACK "<<endl;
    cout<<"3.INTIALIZE STACK TO NULL "<<endl;
    cout<<"4.VIEW TOP ELEMENT "<<endl;
    cout<<"5.Exit "<<endl;
    cout<<"***********************************************************************"<<endl;
    cin>>menuChoice;

    switch (menuChoice)
    {
    case 1:
        do
        {
            cout<<"\n\nENTER ELEMENT(int type.) TO BE PUSHED IN THE STACK: \t";
            cin>>element;
            if(stackPush(&s1,element)==true)
                cout<<"Element "<<element<<" pushed in STACK successfully..";
            else
                cout<<"\nError.! :: STACK OVERFLOW ";
        
            cout<<"\nPress Y to continue and N to goto Main Menu ";
            cin>>choice;
            system("clear");
            if(choice== 'N' || choice== 'n')
                goto X;
        }while(choice == 'Y' || choice == 'y');   
        break;
    case 2:
        do
        {
            if(stackPop(&s1,element)==true)
            {    
                cout<<"\nElement Popped Successfully.. ";
                cout<<"\n*********************************************"<<endl;
                if(stackTop(&s1,element)==true)
                    cout<<"\nTOP ELEMENT NOW: "<<element<<endl;
                else
                    cout<<"\nSTACK EMPTY"<<endl;
                cout<<"\n*********************************************"<<endl;
            }
            else
            {    
                cout<<"\nStack Underflow.. ";
                goto X;
            }
            cout<<"\nPress Y to continue and N to goto Main Menu ";
            cin>>choice;
            system("clear");
            if(choice== 'N' || choice== 'n')
                goto X;

        }while(choice == 'Y' || choice == 'y');
    
    case 3:
        if(stackInit(&s1));
            cout<<"STACK INITIALIZED TO NULL"<<endl;
        goto X;
    case 4:
        if(stackTop(&s1,element)==true)
            cout<<"\nTOP ELEMENT: "<<element<<"\n\n";
        else
        {    
           cout<<"\nSTACK EMPTY"<<endl;
           goto X;
        }
        goto X;
    case 5:
        cout<<"\nThank You, Have a Great Day..."<<endl;
        return EXIT_SUCCESS;
    default:
        cout<<"\nERROR::INVALID CHOICE. "<<endl;
        break;
    }
    return 0;
}
