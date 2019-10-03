#include <iostream>
#include <fstream>
#include <armadillo>
#include "functions.h"
#include "test.h"


using namespace std;
using namespace arma;

int testing(){
    cout <<"test initiated!"<<endl;

    // test if maxoffdiag finds the largets value
    int n = 5;
    double eps = pow(10,-8);
    double maxValue = -51.9;
    mat temp = mat(n,n,fill::eye);

    temp(2,3) = 5;
    temp(3,2) = 5;
    temp(1,4) = 51.2;
    temp(4,1) = 51.2;
    temp(3,0) = -51.9;
    temp(0,3) = -51.9;
    int k = 0;
    int l = 0;
    double maxfound = maxoffdiag(temp,&k,&l,n);
    cout<<"Testing max value"<<endl;
    if (maxfound == fabs(maxValue)){
        cout<<"Success! Max value = expected max value"<<endl;
    }else{
        cout<<"ERROR!!! (Not the right max value)"<<endl;
    }

    return 0;
}
