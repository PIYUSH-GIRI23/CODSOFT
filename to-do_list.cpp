// By Piyush Giri

#include <iostream>
#include <time.h>
using namespace std;
int id=0;
int temp[6];
struct task{
    int id;
    string name;
    string description;
    string status;
    string date;
    string time;
}t[100];
void date_time(){
    time_t currentTime;
    time(&currentTime);
    struct tm* localTime = localtime(&currentTime);
    int hours = localTime->tm_hour;
    int minutes = localTime->tm_min;
    int seconds = localTime->tm_sec;
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;
    temp[0]=hours;
    temp[1]=minutes;
    temp[2]=seconds;
    temp[3]=day;
    temp[4]=month;
    temp[5]=year;
}
void add_task()
{
    if(id<=100){
            t[id].status="Incomplete";
            cout<<endl<<endl<<"This is Your "<<id+1<<" Task"<<endl;
            cout<<endl<<"Enter Task Name: ";
            cin.ignore();
            getline(cin, t[id].name);
            cout<<"Enter Task Description: ";
            getline(cin, t[id].description);
            date_time();
            t[id].date=((temp[3]<10)?(to_string('0'+(temp[3]))):to_string(temp[3]))+"/"+
                        ((temp[4]<10)?(to_string('0'+(temp[4]))):to_string(temp[4]))+"/"+
                        ((temp[5]<10)?(to_string('0'+(temp[5]))):to_string(temp[5]));
            t[id].time = ((temp[0] > 12) ? to_string(temp[0] - 12) : to_string(temp[0])) + ":" +
                    ((temp[1] < 10) ? "0" + to_string(temp[1]) : to_string(temp[1])) + ":" +
                    ((temp[2] < 10) ? "0" + to_string(temp[2]) : to_string(temp[2])) +
                    ((temp[0] >= 12) ? " PM" : " AM");
            cout<<endl<<"Task Added Successfully"<<endl<<endl;
            id++;
            t[id].id=id;

    }
}
void delete_task()
{
    if(id!=0){
        cout<<"Enter The task id to delete: ";
        int id1;
        cin>>id1;
        if(id1<=id){
            for(int i=id1-1;i<id;i++){
                t[i]=t[i+1];
                t[i].id=i+1;
            }
            id--;
            cout<<endl<<endl<<"Task Deleted Successfully"<<endl<<endl;
        }
        else cout<<endl<<endl<<"No Task Found"<<endl<<endl;
    }
    else cout<<endl<<endl<<"No Task Found"<<endl<<endl;
}
void view_task()
{
    if(id!=0){
        cout<<endl<<endl<<"View all tasks"<<endl<<endl;
        for(int i=0;i<id;i++) {
            cout<<"\t\t Task "<<i+1<<endl;
            cout<<"\t\t------------"<<endl<<endl;
            cout<<"\tTask Name: "<<t[i].name<<endl;
            cout<<"\tTask Description: "<<t[i].description<<endl;
            cout<<"\tTask Status: "<<t[i].status<<endl;
            cout<<"\tTask Date: "<<t[i].date<<endl;
            cout<<"\tTask Time: "<<t[i].time<<endl<<endl;
        }
    }
    else cout<<endl<<endl<<"No Task Found"<<endl<<endl;
}   
void mark_task()
{
    cout<<"Enter The task id to mark as completed: ";
    int id1;
    cin>>id1;
    if(id1<=id){
        t[id1-1].status="Completed";
        cout<<endl<<endl<<"Task Marked as Completed"<<endl;
        cout<<"Do you want to delete the completed Task (y/n) : ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y'){
            for(int i=id1-1;i<id;i++){
                t[i]=t[i+1];
                t[i].id=i+1;
            }
            id--;
            cout<<endl<<endl<<"Task Deleted Successfully"<<endl<<endl;
        }
    }
    else cout<<endl<<endl<<"No Task Found"<<endl<<endl;
}   
int main()
{
    cout<<endl<<"\t\tWelcome to To-Do List"<<endl<<endl;
    while(true){
        cout<<"1. Add a task"<<endl;
        cout<<"2. Delete a task"<<endl;
        cout<<"3. View all tasks"<<endl;
        cout<<"4. Mark Task as Completed"<<endl;
        cout<<"5. Exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice==1) add_task();
        else if(choice==2) delete_task();
        else if(choice==3) view_task();
        else if(choice==4) mark_task();
        else break;
    }
    return 0;
}