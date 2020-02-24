#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void merge1(int* leftarray, int* rightarray, int* a, int leftlength, int rightlength)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<leftlength && j<rightlength)
    {
        if(leftarray[i]<=rightarray[j])
        {
            a[k]=leftarray[i];
            i++;
            k++;
        }
        else
        {
            a[k]=rightarray[j];
            j++;
            k++;
        }
    }
    while(i<leftlength)
    {
        a[k]=leftarray[i];
        k++;
        i++;
    }
    while(j<rightlength)
    {
        a[k]=rightarray[j];
        k++;
        j++;
    }
}

void mergesort(int* a, int l, int r){
    int arraylength = (r-l)+1;
    if(arraylength<2){
        return;
    }
    else{
        int midpoint = (arraylength/2);
        int leftarray[midpoint];
        int rightarray[r-midpoint];
        for(int i=0; i<midpoint; i++){
            leftarray[i]=a[i];
        }
        for(int j=midpoint;j<r;j++){
            rightarray[j]=a[j];
        }
        mergesort(leftarray,l,midpoint-1);
        mergesort(rightarray,midpoint,r);
        merge1(leftarray,rightarray,a, midpoint, (arraylength-midpoint));
    }
}

int main()
{
    int a[10];
    for(int i = 0 ; i<10;i++){
      cin>>a[i];
    }
    mergesort(a,0,9);
    // for(int i = 0; i<10; i++){
    //         cout<<a[i];
    // }
    return 0;
}