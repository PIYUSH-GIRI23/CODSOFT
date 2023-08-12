//By Piyush Giri
#include <iostream>
using namespace std;
char arr[3][3]={' '};
int check(int a , int b  , char c){
    if(arr[a-1][b-1]=='X' || arr[a-1][b-1]=='O') return -1;
    if((a>=1 && a<=3) && (b>=1 && b<=3)){
        arr[a-1][b-1]=c;
        return 1;
    }
    return -1;
}
void reset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=' ';
        }
    }
}
void print(){
    cout<<endl;
    cout<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl;
    cout<<"---------"<<endl;
    cout<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
    cout<<"---------"<<endl;
    cout<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl;
}
char result(){
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==' ') count+=1;
        }
    }
    if(count==0) return 'e';
    else if((arr[1][1]!=' ') && ((arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]) || (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]))) return arr[1][1];
    for(int i=0;i<3;i++){
        if((arr[i][0]!=' ') && (arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2])) return arr[i][1];
        else if((arr[0][i]!=' ') && (arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])) return arr[1][i];
    }
    return 'n';
}
int main()
{
    cout<<endl<<"\t\tWelcome To Tic Tac Toe Game"<<endl;
    reset();
    while(true){
        int r,c,ans;
        cout<<endl<<endl<<"Player 1 (X)-> ";
        cin>>r>>c;
        ans=check(r,c,'X');
        if(ans==-1) cout<<endl<<endl<<"Inappropriate Move .. Wait for next turn"<<endl<<endl;
        print();
        if(result()=='e'){
            cout<<endl<<endl<<"Game Draw"<<endl;
            break;
        }
        else if(result()!='n'){
            cout<<endl<<endl<<result()<<" won the match !!"<<endl;
            break;
        }
        cout<<endl<<"Player 2 (O)-> ";
        cin>>r>>c;
        ans=check(r,c,'O');
        if(ans==-1) cout<<endl<<endl<<"Inappropriate Move .. Wait for next turn"<<endl<<endl;
        print();
        if(result()=='e'){
            cout<<endl<<endl<<"Game Draw"<<endl;
            break;
        }
        else if(result()!='n'){
            cout<<endl<<endl<<result()<<" won the match !!"<<endl;
            break;
        }
    }
    cout<<endl<<endl<<"Do You want to play more (y/n) : ";
    char choice;
    cin>>choice;
    if(choice=='y' || choice=='Y') main();
    else return 0;
}