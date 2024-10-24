//Made a map for all the tiles
#include<iostream>
#include<cstdlib>
using namespace std;


int main(){
    srand(time(0));
    int random;
    int bomb = 0;
    int n;
    cin>>n;
    int table [n+1] [n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            random = rand() % 8;
            if (random == 2)
                bomb = 9;
            else 
                bomb = 0;
            table[i][j]=bomb;
        }
    }

    // table[0][0] = 1;
    // table[0][1] = 1;
    // table[0][2] = 1;
    // table[1][0] = 1;
    // table[1][2] = 1;
    // table[2][0] = 1;
    // table[2][1] = 1;
    // table[2][2] = 1;

    int counter=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j]!=9){
                if(table[i-1][j-1]==9)
                    counter++;
                if(table[i-1][j]==9)
                    counter++;
                if(table[i-1][j+1]==9)
                    counter++;
                if(table[i][j-1]==9)
                    counter++;
                if(table[i][j+1]==9)
                    counter++;
                if(table[i+1][j-1]==9)
                    counter++;
                if(table[i+1][j]==9)
                    counter++;
                if(table[i+1][j+1]==9)
                    counter++;
                // cout<<i<<","<<j<<" "<<counter<<endl;
                table[i][j]=counter;
                counter=0;
            }

        }
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"igor";

}
