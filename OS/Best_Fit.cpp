#include<iostream>
using namespace std;

int main() {
    int i, j, block[10], process[10], n1, n2, check;
    
    cout << "Enter the number of memory blocks: ";
    cin >> n1;
    cout << "Enter the number of processes: ";
    cin >> n2;

    // Input memory blocks
    cout << "Enter memory blocks :  ";
    for (i = 0; i < n1; i++)
    {
        cin >> block[i];
    }

    // Input process sizes
    cout << "Enter memory required by processes : ";
     for (i = 0; i < n2; i++) 
    {
        cin >> process[i];
    }

    cout << "Process\tProcess Size\tMemory Block" << endl;
    for (i = 0; i < n2; i++) {
        check = 0;
        int bestFitBlock = -1;  // Initialize to an invalid index
        for (j = 0; j < n1; j++) {
            if (process[i] <= block[j]) {
                if (bestFitBlock == -1 || block[j] < block[bestFitBlock]) {
                    bestFitBlock = j;
                }
                check = 1;
            }
        }

        if (check == 1) {
            block[bestFitBlock] -= process[i];
            cout << i + 1 << "\t\t" << process[i] << "\t\t" << bestFitBlock + 1 << endl;
        } else {
            cout << i + 1 << "\t\t" << process[i] << "\t\t" << "Not allocated" << endl;
        }
    }

    return 0;
}
