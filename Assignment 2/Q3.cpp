#include<iostream>
using namespace std;
struct Job { char id; int dead, profit; };
int main() {
    Job job[] = {{'A',4,20},{'B',1,10},{'C',1,40},{'D',1,30}};
    int n = sizeof(job)/sizeof(job[0]),
    slot[4] = {0}, totalProfit = 0, maxProfit = 0;

    for(int i = 0; i < n; i++)
        totalProfit += job[i].profit;

    // Step 2: Sort jobs by descending profit
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(job[i].profit < job[j].profit)
                swap(job[i], job[j]);

    // Step 3: Job scheduling
    for(int i = 0; i < n; i++)
        for(int j = job[i].dead - 1; j >= 0; j--)
            if(slot[j] == 0) {
                slot[j] = 1;
                maxProfit += job[i].profit;
                break;
            }
    int penalty = totalProfit - maxProfit;
    cout << "Max profit: " << maxProfit << endl;
    cout << "Penalty: " << penalty << endl;
}