#include<iostream>
using namespace std;
int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            if(dep[i]>dep[j]) swap(dep[i],dep[j]);
        }
    int plat = 1, maxPlat = 1, i = 1, j = 0;
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) { plat++; i++; }
        else { plat--; j++; }
        if(plat > maxPlat) maxPlat = plat;
    }
    cout << "Min platforms: " << maxPlat;
}