#include <iostream>
using namespace std;
int main() 
{
    int arr[] ={2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int r = n - 1;
    int key = 23;
    bool found = false;
    while (l<=r) 
    {
        int mid = (l + r) / 2;

        if (arr[mid]==key) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        } 
        else if(arr[mid] > key) 
        {
            r = mid - 1;
        } 
        else 
        {
            l = mid + 1;
        }
    }
    if (!found) 
    {
        cout << "Element not present."<<endl;
    }
}