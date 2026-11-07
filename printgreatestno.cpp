#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter 1st number:";
    cin>>a;
    cout<<"Enter 2nd number:";
    cin>>b;
    cout<<"Enter 3rd number:";
    cin>>c;
    if(a>b && a>c){
    cout<<a<<"is greatest number";
    }
    else if(b>a && b>c){
        cout<<b<<"is greatest number";
        }
        else{
            cout<<c<<"is greatest number";
        }
}
/*Enter 1st number:5
Enter 2nd number:55
Enter 3rd number:5785
5785is greatest number*/