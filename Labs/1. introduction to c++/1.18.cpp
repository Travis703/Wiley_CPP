#include <iostream>
#include <string>
using namespace std;
void characters(string a,int size){
    for(int i=0;i<size;i++){
        cout<<a;
    }

}

int main(){
    int base,head,lengthhead;
    cin>>base>>head;

    for(int k=0;k<7;k++){
        lengthhead=(k/4) ? 7-k:(k+1);
        (lengthhead>2) ? characters(to_string(base),5):characters(" ",5);

        characters(to_string(head),lengthhead);
        cout<<endl;
    }
    
    return 0;

}