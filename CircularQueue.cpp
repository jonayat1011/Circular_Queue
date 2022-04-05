#include<iostream>
using namespace std;
#define MAXSIZE 5

int q[MAXSIZE]; 
int front; 			
int rear; 			

void enqueue(int element);
int dequeue();
bool isQueueEmpty();
int queueSize();
bool isQueueFull();
void display_queue();



void enqueue(int element)
{
    if(isQueueFull()){
         cout<<"\t Queue is Full ..."<<endl;
    }
    else if(isQueueEmpty()){
        front=rear=0;
        q[rear] = element;
    }
    else{
       rear=(rear+1)%MAXSIZE;
        q[rear]=element;
    }
    
}

int dequeue()
{
    int dequeueElement=q[front];

    if(isQueueEmpty()){
        cout<<"queue is empty! dequeue not possible"<<endl;
        return NULL;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAXSIZE;
    }

    return dequeueElement;

 
}

bool isQueueEmpty()
{
    if ((front==-1) and (rear==-1))
        return true;
    else
        return false;
}

bool isQueueFull()
{
    if (((rear+1)%MAXSIZE)==front)
        return true;
    else
        return false;

}

int frontElement(){
    if(isQueueEmpty())
        return NULL;
    else
        return q[front];
}
/*
int queueSize()
{
    return rear-front;

    //your code here
   //return current allocated size of the queue
}*/

void display_queue()
{
    if(isQueueEmpty()){
        cout<<"Queue is empty! Nothing to show"<<endl;
    }
    else if(front <= rear){
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<"\t";
        }
    }
    else{
        for(int i=front; i<=(MAXSIZE-1); i++){
             cout<<q[i]<<"\t";
        }
        for(int i=0; i<=rear; i++){
             cout<<q[i]<<"\t";
        }
    }

    cout<<endl;

}
int main()
{
    front=rear=-1;
    int option,n, value;
    cout<<"C++ program to implement Queue operations\n";
    do
    {
        cout<<"\n 1.Insert an element in Queue";
        cout<<"\n 2.Delete an element from Queue";
        cout<<"\n 3.Display Queue";
        cout<<"\n 4.Exit";
        cout<<"\n Enter your choice: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<" Insert an element in Queue: ";
            cin>>n;
            enqueue(n);
            break;
        case 2:
            value = dequeue();
            if(value != NULL)
            cout<<" Dequeue element is: "<<value<<endl;
            break;
        case 3:
            display_queue();
            break;
        case 4:
            return 0;
        }
    }
    while(option!=4);

    return 0;
}
