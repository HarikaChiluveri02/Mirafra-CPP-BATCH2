#include <iostream>
#include<cstdlib>

using namespace std;
int main() {
int blockCount=3,i,j;
int sizes[3]={5,3,6};

float **doublepointer=(float **)malloc(3*sizeof(float *));
    for (i = 0; i < blockCount; i++) {
        doublepointer[i] = (float *)malloc(sizes[i] * sizeof(float));
        if (!doublepointer[i]) {
            cout << "Memory allocation failed\n";
            return 1;
        }
    }
    for (i = 0; i < sizes[0]; i++)
        doublepointer[0][i] = 50.0f + i;
    for (i = 0; i < sizes[1]; i++)
        doublepointer[1][i] = 20.0f + i;
    for (i = 0; i < sizes[2]; i++)
        doublepointer[2][i] = 100.0f + i;
    const char* names[3] = {"Humidity", "Temperature", "Other"};
    for (i = 0; i < blockCount; i++) {
        cout << names[i] << " values:\n";
        for (j = 0; j < sizes[i]; j++)
            cout << doublepointer[i][j] << " ";
        cout<<endl;
    }
    for (i = 0; i < blockCount; i++)
        free(doublepointer[i]);
    free(doublepointer);
    return 0;
}




