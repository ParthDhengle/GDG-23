#include<iostream>
using namespace std;
1.Generate Fibonacci series for N terms and store  all these in a singly list and display the list 
struct node{int data;node*link;};
class Llist{
    node*head;
    public:
    Llist(){head=NULL;}
    void create(int n);
    void display();
};
void Llist :: create(int n){
    node*nn,*temp;
    int i;
    int a=0,b=1;
    for(i=0;i<n;i++){
        nn= new node;
        if (nn==NULL){cout<<"memory full ";return ; }
        nn->link=NULL;
        if(i>1){
            nn->data=a+b;
            a=b;
            b=nn->data;
        }
        if (i==0){head=nn;temp = nn;nn->data=a;continue;}
        if(i==1){nn->data=b;}
        temp->link=nn;
        temp=nn;
    }
    cout<<"Linked list created with fibb series "<<endl;
}
void Llist:: display(){
    if ( head == NULL){cout<<"empty list "<<endl;return;}
    for(node*t=head;t!=NULL;t=t->link){
        cout<<t->data<<"\t";
    }
}
int main(){
    int i,n;
    cout<<"enter number : ";
    cin>>n;
    Llist obj;
    obj.create(n);
    obj.display();
}

2.  Generate first 15 prime numbers and store them in a circular link list and display the list. 
#include <cmath>
 struct node{int data;node*link;};
class Clist{
    node*last;
    public:
    Clist(){last=NULL;}
    void create(int n);
    void display();
};
void Clist :: create(int n){
   int i=1,x=1; node*nn;
   while(i<=n){
    int count=0;
    for (int j=2;j<=sqrt(x);j++){
        if(x%j==0){
            count++;
        }
    }
    if(count==0){
        i++;
        nn=new node; if(nn==NULL){ cout<<"Memeroy issue"; return;}
        nn->data=x;
        if(last==NULL){ 
            last=nn; nn->link=nn; 
        }
        else{
        nn->link=last->link;
        last->link=nn;
        } 
    }
    x++;    
    }
    cout<<"List created\n";
}
void Clist::display()
{
    node*t=last->link;
    do{
        cout<<t->data<<"\t";
        t=t->link;
        
    }while(t!=last->link);
    cout << endl;
}

int main()
{
    Clist cx;
    cx.create(15);
    cx.display();
    return 0;
}

3. Read name of a person and store each symbol in a circular list and display the list. 
#include <iostream>
using namespace std;
struct node {char data; node * link;};
class Clist
{
    node * last;
    
    public: Clist(){ last=NULL;}
    void create();
    void display();
};

void Clist::create()
{
   int i; node*nn;
   string name;
   //cout<<"Enter your name : \n"; cin>>name;
   name="parth"  
   int n=name.size();
   for(i=0;i<n;i++)
   {
       nn=new node; if(nn==NULL){ cout<<"Memeroy issue"; return;}
       nn->data=name[i];
       
       if(i==0)
       { last=nn; nn->link=nn; continue; }
       
       nn->link=last->link;
       last->link=nn;
       
   }
   cout<<"List created\n";
}

void Clist::display()
{
    node*t=last->link;
    do{
        cout<<t->data<<"\t";
        t=t->link;
        
    }while(t!=last->link);
}


int main()
{
    Clist cx;
    cx.create();
    cx.display();
    return 0;
}

4. Store N numbers in a singly link list and write a program to remove all the entries  of a given key. 

struct node{int data;node*link;};
class Llist{
    node*head;
    public:
    Llist(){head=NULL;}
    void create();
    void remove(int x);
    void display();
};
void Llist :: create() {
    node* nn, * temp;
    int n, i;
    cout << "Enter how many nodes\n";
    cin >> n;
    for (i = 0; i < n; i++) {
        nn = new node;
        if (nn == NULL) {
            cout << " No memory";
            return;
        }
        cout << "Enter data\t";
        cin >> nn->data;
        nn->link = NULL;
        if (i == 0) {
            head = nn;
            temp = nn;
            continue;
        }
        temp->link = nn;
        temp = nn;
    }
    cout << "List created\n";
}
void Llist:: remove(int key){
    node*curr=head;node*temp;
    node*prev=curr;
    while(curr!=NULL){
        if(curr->data==key){
            temp=curr;
            prev->link=curr->link;
            curr=curr->link;
            delete temp;
        }else{
            prev=curr;
            curr=curr->link;
        }
    }
}
void Llist:: display(){
    if ( head == NULL){cout<<"empty list "<<endl;return;}
    for(node*t=head;t!=NULL;t=t->link){
        cout<<t->data<<"\t";
    }
}
int main(){
    int i,x;
    Llist obj;
    obj.create();
    cout<<"enter element to remove : ";
    cin>>x;
    obj.remove(x);
    obj.display();
}

5. Implement a  stack using link list and check whether the give string is a palindrome or not. 
struct node{char data;node*link;};
class Stack{
    node*top;
    public:
    Stack() {
        top = NULL;
    }
    void push(char x);
    char pop();
};
void Stack::push(char x){
    node*nn=new node;
    if(nn==NULL){
        cout<<"memory issue ";
        return;
    }
    nn->data=x;
    nn->link=top;
    top=nn;
}
char Stack::pop(){
    if(top==NULL){
        cout<<"Stack is empty ";
        return 0;
    }
    char ch=top->data;
    node*temp=top;
    top=top->link;
    delete temp;
    return ch;
}
bool CheckPalindrom(string str){
    Stack stk;
    int leng=str.length();
    for(int i=0;i<leng;i++){
        stk.push(str[i]);
    }
    for (int i=0;i<leng;i++){
        if(str[i]!=stk.pop()){
            return false;
        }
    }
    return true;
}
int main(){
    string str;
    cout<<"enter string : ";
    cin>>str;
    if(CheckPalindrom(str)){
        cout<<str<<" is palindrome"<<endl;
    }
    else{
        cout<<str<<" is not palindrome"<<endl;
    }
}
6. Implement a two stack using array  with top1 and top2, and make provision to push items as long as there is free space available in any one of the stack. Demonstrate its use. 
class twowayStack{
    int top1,top2;
    int size;
    int *arr;
    public:
    twowayStack(int n){
        size=n;
        top1=-1;
        top2=size;
        arr=new int[size];
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
    void disp1();
    void disp2();
};
void twowayStack::push1(int x){
    if(top1==top2-1){
        cout<<"stack over flow in stack1"<<endl;
        return;
    }
    else{
        arr[++top1]=x;
    }
}
void twowayStack::push2(int x){
    if(top2==top1+1){
        cout<<"stack over flow in stack2"<<endl;
        return;
    }
    else{
        arr[--top2]=x;
    }
}
int twowayStack::pop1(){
    if(top1==-1){
        cout<<"stack 1 is empty "<<endl;
        return 0;
    }
    else{
        return arr[top1--];
    }
}
int twowayStack::pop2(){
    if(top2==size){
        cout<<"stack 2 is empty "<<endl;
        return 0;
    }
    else{
        return arr[top2++];
    }
}
void twowayStack::disp1(){
    if (top1 == -1) {
        cout << "Stack 1 is empty" << endl;
        return;
    }
    for (int i=0; i<=top1;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void twowayStack::disp2(){
    if (top2 == size) {
        cout << "Stack 2 is empty" << endl;
        return;
    }
    for (int i=size-1; i>=top2;i--){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int main(){
    int n,choice,temp,x;
    cout<<"enter the size of array : ";
    cin>>n;
    twowayStack obj1(n);
    do{
        cout<<"what operation do you want to perform : \n";
        cout<<"ADD n elements in STACK 1 : 1\n";
        cout<<"ADD 1 element in STACK 1 : 2\n";
        cout<<"POP element in STACK 1 : 3\n";
        cout<<"Display 1 : 4\n";
        cout<<"ADD n elements in STACK 2 : 9\n";
        cout<<"ADD 1 element in STACK 2 : 8\n";
        cout<<"POP element in STACK 2 : 7\n";
        cout<<"Display 2 : 6\n";
        cout<<"EXIT : 5\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter number of element to enter";
            cin>>temp;
            for(int i=0;i<temp;i++){
                cout<<"Enter : ";
                cin>>x;
                obj1.push1(x);
            }
            break;
        case 2:
            cout<<"Enter : ";
            cin>>x;
            obj1.push1(x);
            break;
        case 3:
            cout<<"Deleted element from stack : "<<obj1.pop1()<<endl;
            break;
        case 4: 
            obj1.disp1();
            break;
        case 9:
            cout<<"Enter number of element to enter";
            cin>>temp;
            for(int i=0;i<temp;i++){
                cout<<"enter : ";
                cin>>x;
                obj1.push2(x);
            }
            break;
        case 8:
            cout<<"enter : ";
            cin>>x;
            obj1.push2(x);
            break;
        case 7:
            cout<<"deleted element from stack : "<<obj1.pop2()<<endl;
            break;
        case 6: 
            obj1.disp2();
            break;
        case 5:
            cout<<"exiting....";
            break;
        default:
        cout<<"invalid choice\n";
            break;
        }
    }while(choice!=5);
}
7. Implement a   queue using link list and demonstrate its use.
struct node {
    int data;
    node* link;
};
class Queue{
    node*front;
    node*rear;
    public:
    Queue(){
        front=rear=NULL;
    }
    void insert(int x);
    int delf();
    void disp();
};
void Queue::insert(int x){
    node*nn=new node;
    if (nn==NULL){
        cout<<"memory full";
        return;
    }
    nn->data=x;
    nn->link=NULL;
    if(rear==NULL){
        rear=front=nn;
    }
    rear->link=nn;
    rear=nn;
    cout<<x<<" is inserted"<<endl;
}
int Queue::delf(){
    if(front==NULL){
        cout<<"Queue is empty";
        return 0;
    }
    int deleted=front->data;
    node*temp=front;
    front=front->link;
    delete temp;
    cout<<deleted<<" is deleted successfully."<<endl;
    return deleted;
}
void Queue::disp(){
    if(front==NULL){
        cout<<"queue is empty ";
        return;
    }
    node*temp=front;
    while(temp!=NULL){
        cout<<temp->data<<"     ";
        temp=temp->link;
    }
    cout<<endl;
}
int main(){
    Queue queue;
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.disp();

    queue.delf();
    queue.disp();

    queue.insert(40);
    queue.disp();

    queue.delf();
    queue.disp();

    return 0;
}
8. Implement a circular queue using an array and set queue overflow and under flow conditions for insert and delete without using count.
const int size=10;
class CQ{
    int r,f;
    int arr[size];
    public:
    CQ(){
        r=-1;f=-1;
    }
    void insert(int x);
    int delf();
    void disp();
};
void CQ::insert(int x){
    if(r+1==f || (f==0 && r==size-1)){
        cout<<"overflow"<<endl;
        return;
    }
    if(f==-1){
        f=0;
        r=0;
    }
    else if (r==size-1){
        r=-1;
    }
    else{
        r++;
    }
    arr[r]=x;
    cout<<x <<" is inserted"<<endl;
}
int CQ::delf(){
    if(f==-1){
        cout<<"queue is empty";
        return 0;
    }
    int y=arr[f++];
    if(f==r){
        f=-1;
        r=-1;
    }if(f==size-1){
        f=0;
    }
    cout<<y<<" is deleted";
    return y;
}
void CQ:: disp(){
    int i=f;
    while(true){
        if(i==size){
            i=0;
        }
        cout<<arr[i++]<<"   ";
        if(i==r+1){
            break;
        }
    }
    cout<<endl;
}
int main(){
    CQ queue;
    queue.insert(30);
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.disp();

    queue.delf();
    queue.disp();

    queue.insert(40);
    queue.disp();

    queue.delf();
    queue.disp();
}
9. Read an integer and convert it to binary and store the same in link list and display the list. 
struct node{int data;node*link;};
class Llist{
    node*head;
    public:
    Llist(){head=NULL;}
    void create();
    void display();
};
void Llist :: create() {
    node* nn, * temp;
    int n, i,x,j=0,m=1;
    cout << "Enter how many nodes\n";
    cin >> n;
    for (i = 0; i < n; i++) {
        nn = new node;
        if (nn == NULL) {
            cout << " No memory";
            return;
        }
        cout << "Enter data\t";
        cin >> x;
        int bin=0;
        while (x!=0){
            bin+=x%2*m;
            m*=10;
            x/=2;
        }
        m=1;
        nn->data=bin;
        nn->link = NULL;
        if (i == 0) {
            head = nn;
            temp = nn;
            continue;
        }
        temp->link = nn;
        temp = nn;
    }
    cout << "List created\n";
}
void Llist:: display(){
    if ( head == NULL){cout<<"empty list "<<endl;return;}
    for(node*t=head;t!=NULL;t=t->link){
        cout<<t->data<<"\t";
    }
}
int main(){
    int i,x;
    Llist obj;
    obj.create();
    obj.display();
}
10. Read an integer and reverse it using stack. 
const int size=10;
class Stack{
    int arr[size];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(int x);
    int pop();
    void reverse(int n);
    void disp();
};
void Stack::push(int x){
    if(top>=size-1){
        cout<<"overflow "<<endl;
        return;
    }
    arr[++top]=x;
    cout<<x<<" is inserted";
}
int Stack::pop(){
    if(top==-1){
        cout<<"Stack is empty";
        return 0;
    }
    return arr[top--];
}
void Stack::disp(){
    for(int i=0;i<=top;i++){
        cout<<arr[i];
    }
}
// void Stack::reverse(int n){
//     while (n){
//         push(n%10);
//         n/=10;
//     }
//     cout<<"\nReversed Stack : "<<endl;
//     disp();
// }
void Stack::reverse(int n){
    int digits[size];
    int digitcounter=0;
    while(n>0){
        digits[digitcounter++]=n%10;
        n/=10;
    }
    for(int i=digitcounter-1;i>=0;i--){
        push(digits[i]);
    }
    cout<<"\nReversed integer : ";
    while(top!=-1){
        cout<<pop();
    }
}
int main(){
    int n;
    cout<<"enter integer : ";
    cin>>n;
    Stack s;
    s.reverse(n);
}