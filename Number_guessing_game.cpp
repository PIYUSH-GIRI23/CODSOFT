// By PIYUSH GIRI
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    cout<<endl<<"Welcome to Number Guessing Game"<<endl<<endl;
    srand(time(NULL));
    char choice='y';
    int innerLoop;
    while(choice=='y' || choice=='Y'){
        cout<<endl<<endl<<"\t\tGUESS THE NUMBER FROM 1 TO 100"<<endl<<endl;
        innerLoop=1;
        int randomNumber = rand() % 100 + 1;
        int a;
        while(innerLoop){
            cout<<endl<<"Enter Your Guessed Number: ";
            cin>>a;
            if(a==randomNumber){
                cout<<endl<<"Your Guess is Right .. The Number is "<<randomNumber<<endl;
                cout<<endl<<"Do You want to play More (Y/N) : ";
                cin>>choice;
                innerLoop=0;
            }
            else if(a>randomNumber) cout<<"Your Guess is Too High"<<endl;
            else cout<<"Your Guess is Too Low"<<endl;
        }
    }
    return 0;
}