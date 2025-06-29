#include<iostream>
using namespace std;
int main() {
    int start[] = {1, 3, 0, 5, 8, 5}, finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    // Sort by finish time
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(finish[i]>finish[j]) {
                swap(finish[i],finish[j]);
                swap(start[i],start[j]);
            }
    int count = 1, end = finish[0];
    for(int i=1;i<n;i++)
        if(start[i] >= end) {
            count++;
            end = finish[i];
        }
    cout << "Max activities: " << count;
}