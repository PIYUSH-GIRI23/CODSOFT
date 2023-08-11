// By Piyush Giri
#include <iostream>
using namespace std;
float addition(float a , float b){
    return a+b;
}
float substraction(float a , float b){
    return a-b;
}
float multiplication(float a , float b){
    return a*b;
}
float division(float a , float b){
    return a/b;
}
int main()
{
    cout<<endl<<"Welcome to the Basic Arithmetic Operational Calculator!"<<endl<<endl;
    float num1,num2;
    int choice;
    while(true){
        cout<<"Enter the first number: ";
        cin>>num1;
        cout<<"Enter the second number: ";
        cin>>num2;
        cout<<endl<<endl<<"Following are the Operations You can perform :"<<endl<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Subtraction"<<endl;
        cout<<"3. Multiplication"<<endl;
        cout<<"4. Division"<<endl;
        cout<<"5. Exit"<<endl<<endl;
        cout<<"Enter Your choice : ";
        cin>>choice;
        if(choice==1) cout<<endl<<num1<<" + "<<num2<<" = "<<addition(num1,num2)<<endl<<endl;
        else if(choice==2) cout<<endl<<num1<<" - "<<num2<<" = "<<substraction(num1,num2)<<endl<<endl;
        else if(choice==3) cout<<endl<<num1<<" X "<<num2<<" = "<<multiplication(num1,num2)<<endl<<endl;
        else if(choice==4) cout<<endl<<num1<<" / "<<num2<<" = "<<division(num1,num2)<<endl<<endl;
        else break;
    }
    return 0;
}