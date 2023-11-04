#include<iostream>
using namespace std;

int main(){
    int random = 1+(rand()%100);
    int num;
    
    int score =10;
    while(score!=0){
    cout << "enter the no."<< endl;
    cin >> num;
    if(num == random){
        cout << "you guessed right"<<endl;
        break;
    }
    else if(num > random){
        cout << "guess a smaller number"<<endl;
        
    }
    else{
        cout << "guess a larger number"<<endl;
    }
    score--;
    }
    cout<<"the number is "<<random<<endl;
    cout<<"score is "<<score<<endl;
    return 0;
    }