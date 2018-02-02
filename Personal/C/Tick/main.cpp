#include <iostream>
#include <cstdlib>

using namespace std;
void printDiagram(char diag[3][3]);
bool checkIfWin(char diag[3][3]);
//char** emptyArray(char[3][3] diag);

int main()
{
    char diag[3][3]= {};

    char CONTINUE='N';
    int noOfChance=0;

    printDiagram(diag);

    char value;
    bool bWon;
restart:
    do
    {
        if(CONTINUE=='Y' || CONTINUE=='y')
        {
            for(int row=0; row<3; row++)
            {
                for(int column=0; column<3; column++)
                {
                    diag[row][column]='\0';
                }
            }
            noOfChance=0;
            CONTINUE='N';
            value='\0';
            printDiagram(diag);
        }
        ++noOfChance;
        if(noOfChance>9)
        {
           break;
        }

        int option;

        cout<<"Enter the position";
        if(value=='\0' || value=='O')
        {
            cout<<" for Player 1:";
            value='X';
        }
        else
        {
            cout<<" for Player 2:";
            value='O';
        }
        cout<<endl;

        bool bNotValid=true;
        while(bNotValid)
        {
            bNotValid=false;
            cin>>option;
            switch(option)
            {
            case 1:
                diag[0][0]=value;
                break;
            case 2:
                diag[0][1]=value;
                break;
            case 3:
                diag[0][2]=value;
                break;
            case 4:
                diag[1][0]=value;
                break;
            case 5:
                diag[1][1]=value;
                break;
            case 6:
                diag[1][2]=value;
                break;
            case 7:
                diag[2][0]=value;
                break;
            case 8:
                diag[2][1]=value;
                break;
            case 9:
                diag[2][2]=value;
                break;
            default:
                cout<<"Not valid position";
                bNotValid=true;
                break;
            }
        }

        printDiagram(diag);
        bWon=checkIfWin(diag);
    }
    while((!bWon) || (CONTINUE=='Y') || (CONTINUE=='y'));

    int xCount=0;
    int oCount=0;
    for(int row=0; row<3; row++)
    {
        for(int column=0; column<3; column++)
        {
            if(diag[row][column]=='X')
            {
                ++xCount;
            }
            else if(diag[row][column]=='O')
            {
                ++oCount;
            }
        }
    }

    if(!bWon){
        cout<<"Match is drawn";
    }
    else if(xCount>oCount)
    {
        cout<<"Player 1 has won!!!";
    }
    else
    {
        cout<<"Player 2 has won!!!";
    }
    cout<<endl;

    cout<<"Do you want to play again?(Y/N)"<<endl;
    cin >> CONTINUE;
    if(CONTINUE=='Y' || CONTINUE=='y')
    {
        goto restart;
    }
    cout<<endl;

    cout << "End of game" << endl;
    return 0;
}

void printDiagram(char diag[3][3])
{
    system("CLS");
    cout<<diag[0][0]<<"|"<<diag[0][1]<<"|" <<diag[0][2]<<endl;
    cout<<"-----"<<endl;
    cout<<diag[1][0]<<"|"<<diag[1][1]<<"|" <<diag[1][2]<<endl;
    cout<<"-----"<<endl;
    cout<<diag[2][0]<<"|"<<diag[2][1]<<"|" <<diag[2][2]<<endl;
}


bool checkIfWin(char diag[3][3])
{

    bool bWin=true;
    //row wise
    if((diag[0][0]=='X' && diag[0][1]=='X' && diag[0][2]=='X')||(diag[0][0]=='O' && diag[0][1]=='O' && diag[0][2]=='O'))
    {
        return bWin;
    }
    else if((diag[1][0]=='X' && diag[1][1]=='X' && diag[1][2]=='X')||(diag[1][0]=='O' && diag[1][1]=='O' && diag[1][2]=='O'))
    {
        return bWin;
    }
    else if((diag[2][0]=='X' && diag[2][1]=='X' && diag[2][2]=='X')||(diag[2][0]=='O' && diag[2][1]=='O' && diag[2][2]=='O'))
    {
        return bWin;
    }
    //column wise
    else if((diag[0][0]=='X' && diag[1][0]=='X' && diag[2][0]=='X')||(diag[0][0]=='O' && diag[1][0]=='O' && diag[2][0]=='O'))
    {
        return bWin;
    }
    else if((diag[0][1]=='X' && diag[1][1]=='X' && diag[2][1]=='X')||(diag[0][1]=='O' && diag[1][1]=='O' && diag[2][1]=='O'))
    {
        return bWin;
    }
    else if((diag[0][2]=='X' && diag[1][2]=='X' && diag[2][2]=='X')||(diag[0][2]=='O' && diag[1][2]=='O' && diag[2][2]=='O'))
    {
        return bWin;
    }
    //diagonal wise
    else if((diag[0][0]=='X' && diag[1][1]=='X' && diag[2][2]=='X')||(diag[0][0]=='O' && diag[1][1]=='O' && diag[2][2]=='O'))
    {
        return bWin;
    }
    else if((diag[0][2]=='X' && diag[1][1]=='X' && diag[2][0]=='X')||(diag[0][2]=='O' && diag[1][1]=='O' && diag[2][0]=='O'))
    {
        return bWin;
    }
    //if it lost
    else
    {
        return false;
    }
}

//char** emptyArray(char[3][3] diag)
//{
//    for(int row=0; row<3; row++)
//    {
//        for(int column=0; column<3; column++)
//        {
//            diag[row][column]='\0';
//        }
//    }
//
//    return diag;
//}
