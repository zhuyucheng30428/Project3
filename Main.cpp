#include <iostream>
#include "Matrix.c"
using namespace std;
int main(){
    int row,col;
    cout<<"Please input row and col"<<endl;
    cin>>row;
    cin>>col;
    struct Matrix *a= inputMatrix(row,col);
    cout<<"delete matrix a"<<endl;
    deleteMatrix(&a);
    cout<<"try print matrix a"<<endl;
    printMatrix(a);
    cout<<"try add 3.0 to a"<<endl;
    a=addMatrix(a,3.0f);
    cout<<"try multiply 2.0 with a"<<endl;
    a=addMatrix(a,2.0f);
    return 0;
}