#include<iostream>
using namespace std;
struct Item { int p, w; };
int main() {
    Item a[] = {{60,10},{100,20},{120,30}};
    int n=sizeof(a)/sizeof(a[0]), 
    W=50; float total=0;
    // Sort by profit/weight
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if((float)a[i].p/a[i].w < (float)a[j].p/a[j].w)
                swap(a[i],a[j]);
    for(int i=0;i<n && W>0;i++) {
        if(a[i].w <= W) { total += a[i].p; W -= a[i].w; }
        else { total += (float)a[i].p * W / a[i].w; break; }
    }
    cout << "Max value: " << total;
}