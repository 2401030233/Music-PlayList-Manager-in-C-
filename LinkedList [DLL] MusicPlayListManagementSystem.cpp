# include <iostream>
# include <string>
using namespace std;
int listSize=0; //global variable for O(1) time complexity
struct Node
{
    Node *prev;
    int songID;
    string name;
    double duration;
    Node *next;
} *head=nullptr, *rear=nullptr;
Node *current=nullptr;
void createNode (int x, string n, double d)
{
    listSize++;
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->songID=x;
    temp->name=n;
    temp->duration=d;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    cout<<"\nCreated song with required data at position : "<<listSize<<endl;
}
void playCurrent ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to play\n";
    }
    else
    {
        if (current==nullptr)
        {
            cout<<"\nNo song is currently selected or being played..\n";
            current=head;
        }
        else
        {
            cout<<"\nCurrent song begin played : [ "<<current->songID<<", "<<current->name<<", "<<current->duration<<" sec. ]"<<endl;
        }
    }
}
void simulateNext ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to play\n";
    }
    else
    {
        if (current==nullptr)
        {
            playCurrent ();
        }
        else if (current->next==nullptr)
        {
            cout<<"\nAlready reached the end of the PlayList!\n";
        }
        else
        {
            current=current->next;
            cout<<"\nSimulated to Next song..\nNow playing : [ "<<current->songID<<", "<<current->name<<", "<<current->duration<<" sec. ]"<<endl;
        }
    }
}
void simulatePrevious ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to play\n";
    }
    else
    {
        if (current==nullptr)
        {
            playCurrent ();
        }
        else if (current->prev==nullptr)
        {
            cout<<"\nAlready at the start of the PlayList!\n";
        }
        else
        {
            current=current->prev;
            cout<<"\nSimulated to previous song..\nNow playing : [ "<<current->songID<<", "<<current->name<<", "<<current->duration<<" sec. ]"<<endl;
        }
    }
}
void displayPlayListForward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to display\n";
    }
    else
    {
        Node *temp=head;
        cout<<"\nDisplaying PlayList (Forward) : ";
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->songID<<", "<<temp->name<<", "<<temp->duration<<" sec. ] -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void displayPlayListBackward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to display\n";
    }
    else
    {
        Node *temp=rear;
        cout<<"\nDisplaying PlayList (Backward) : ";
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->songID<<", "<<temp->name<<", "<<temp->duration<<" sec. ] -> ";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
}
void insert_first (int x, string n, double d)
{
    listSize++;
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->next=nullptr;
    temp->songID=x;
    temp->name=n;
    temp->duration=d;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    cout<<"\nInserted song with required data at beginning\n";
}
void insert_last (int x, string n, double d)
{
    listSize++;
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->next=nullptr;
    temp->songID=x;
    temp->name=n;
    temp->duration=d;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    cout<<"\nInserted song with required data at end\n";
}
void insert_specified (int pos, int x, string s, double d)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (pos==1)
        {
            insert_first (x, s, d);
        }
        else
        {
            int num=listSize;
            if (pos>1 && pos<=num)
            {
                Node *temp=new Node (), *p=head, *n=head->next;
                int i=1;
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                p->next=temp;
                temp->next=n;
                n->prev=temp;
                temp->prev=p;
                temp->songID=x;
                temp->name=s;
                temp->duration=d;
                listSize++;
                cout<<"\nInserted song with required data at position : "<<pos<<endl;
            }
            else if (pos==num+1)
            {
                insert_last (x, s, d);
            }
            else
            {
                cerr<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void delete_first ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr && head!=nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nDeleted head node!\n";
        listSize--;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        temp=nullptr;
        cout<<"\nDeleted first song!\n";
        listSize--;
    }
}
void delete_last ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nDeleted head node!\n";
        listSize--;
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        rear->next=nullptr;
        delete temp;
        temp=nullptr;
        cout<<"\nDeleted last song!\n";
        listSize--;
    }
}
void delete_specified (int pos)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (pos==1)
        {
            delete_first ();
        }
        else
        {
            int num=listSize;
            if (pos>1 && pos<num)
            {
                Node *temp, *n=head->next, *p=head;
                int i=1;
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                temp=p->next;
                p->next=temp->next;
                temp->next->prev=p;
                delete temp;
                temp=nullptr;
                listSize--;
                cout<<"\nDeleted song at position : "<<pos<<endl;
            }
            else if (pos==num)
            {
                delete_last ();
            }
            else
            {
                cerr<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void searchSongByID (int ID)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to search for\n";
    }
    else
    {
        Node *temp=head;
        bool flag=0;
        int i=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->songID==ID)
            {
                flag=1;
                cout<<"\nSong with ID : "<<temp->songID<<" found at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nSong NOT found!\n";
        }
    }
}
void searchSongByPosition (int pos)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (head==nullptr)
        {
            cout<<"\nALERT : PlayList is empty!\nNothing to search for\n";
        }
        else
        {
            int num=listSize, i=0;
            bool flag=0;
            Node *temp=head;
            if (pos>=1 && pos<=num)
            {
                while (temp!=nullptr)
                {
                    i++;
                    if (i==pos)
                    {
                        flag=1;
                        cout<<"\nSong with ID : "<<temp->songID<<" found at position : "<<pos<<endl;
                        break;
                    }
                    temp=temp->next;
                }
                if (!flag)
                {
                    cout<<"\nSong NOT found!\n";
                }
            }
            else
            {
                cerr<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void deleteSongByID (int ID)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : PlayList is empty!\nNothing to delete\n";
    }
    else
    {
        bool flag=0;
        int i=0;
        Node *temp=head;
        while (temp!=nullptr)
        {
            i++;
            if (temp->songID==ID)
            {
                flag=1;
                delete_specified (i);
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nSong NOT found!\n";
        }
    }
}
void displayMenu ()
{
    cout<<"\n=====================================[Music PlayList]======================================\n";
    cout<<"\n1.Create song\t              2.Add song at beginning\t     3.Add song at ending\n";
    cout<<"4.Add song at specified pos   5.Display PlayList (Forward)";
    cout<<"   6.Display PlayList (Backward)\n7.Delete first song\t      8.Delete last song";
    cout<<"             9.Delete pos specified song\n10.Search song by ID\t      11.Search song by position";
    cout<<"     12.Delete song by ID\n13.Count songs in PlayList    14.Play Current Song\t     ";
    cout<<"15.Simulate NEXT\n16.Simulate PREV\t      17.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, x, pos;
    string n;
    double d;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput songID : ";
            cin>>x;
            cout<<"\nInput name of song : ";
            cin.ignore (); //clears input buffer
            getline (cin, n);
            cout<<"\nInput duration (sec.) : ";
            cin>>d;
            createNode (x, n, d);
            break;
        case 2:
            cout<<"\nInput songID : ";
            cin>>x;
            cout<<"\nInput name of song : ";
            cin.ignore (); //clears input buffer
            getline (cin, n);
            cout<<"\nInput duration (sec.) : ";
            cin>>d;
            insert_first (x, n, d);
            break;
        case 3:
            cout<<"\nInput songID : ";
            cin>>x;
            cout<<"\nInput name of song : ";
            cin.ignore (); //clears input buffer
            getline (cin, n);
            cout<<"\nInput duration (sec.) : ";
            cin>>d;
            insert_last (x, n, d);
            break;
        case 4:
            cout<<"\nInput songID : ";
            cin>>x;
            cout<<"\nInput name of song : ";
            cin.ignore (); //clears input buffer
            getline (cin, n);
            cout<<"\nInput duration (sec.) : ";
            cin>>d;
            cout<<"\nInput position for song addition : ";
            cin>>pos;
            insert_specified (pos, x, n, d);
            break;
        case 5:
            displayPlayListForward ();
            break;
        case 6:
            displayPlayListBackward ();
            break;
        case 7:
            delete_first ();
            break;
        case 8:
            delete_last ();
            break;
        case 9:
            cout<<"\nInput position for song deletion : ";
            cin>>pos;
            delete_specified (pos);
            break;
        case 10:
            cout<<"\nInput ID of song to be searched : ";
            cin>>x;
            searchSongByID (x);
            break;
        case 11:
            cout<<"\nInput position of song to be searched : ";
            cin>>pos;
            searchSongByPosition (pos);
            break;
        case 12:
            cout<<"\nInput ID of song to be deleted : ";
            cin>>x;
            deleteSongByID (x);
            break;
        case 13:
            cout<<"\nSize of PlayList is : "<<listSize<<endl;
            break;
        case 14:
            playCurrent ();
            break;
        case 15:
            simulateNext ();
            break;
        case 16:
            simulatePrevious ();
            break;
        case 17:
            cout<<"\n======[Exiting the program...]======\n";
            exit (0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=17);
    return 0;
}
