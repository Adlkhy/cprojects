#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    int* numPtr = &n;
    
    while (*numPtr > 0) {
        sum += *numPtr % 10;
        *numPtr /= 10;
    }
    return sum;
}

int countLuckyTickets(int M, int N) {
    int digitSum[10000];
    int* digitPtr = digitSum;
    
    for (int i = 0; i <= 9999; i++) {
        *(digitPtr + i) = sumOfDigits(i);
    }
    
    int sumCount[37] = {0};
    int* countPtr = sumCount;
    
    for (int i = 0; i <= 9999; i++) {
        (*(countPtr + *(digitPtr + i)))++;
    }
    
    int count = 0;
    int* countMain = &count;
    
    int startFirst4 = M / 10000;
    int endFirst4 = N / 10000;
    int* startPtr = &startFirst4;
    int* endPtr = &endFirst4;
    
    for (int first4 = *startPtr + 1; first4 < *endPtr; first4++) {
        *countMain += *(countPtr + *(digitPtr + first4));
    }
    
    int firstSum = *(digitPtr + *startPtr);
    int firstMin = M % 10000;
    int firstMax = (*startPtr == *endPtr) ? (N % 10000) : 9999;
    int* minPtr = &firstMin;
    int* maxPtr = &firstMax;
    
    for (int last4 = *minPtr; last4 <= *maxPtr; last4++) {
        if (*(digitPtr + last4) == firstSum) {
            (*countMain)++;
        }
    }
    
    if (*startPtr != *endPtr) {
        int lastSum = *(digitPtr + *endPtr);
        for (int last4 = 0; last4 <= (N % 10000); last4++) {
            if (*(digitPtr + last4) == lastSum) {
                (*countMain)++;
            }
        }
    }
    
    return *countMain;
}

int main() {
    int M, N;
    int* mPtr = &M;
    int* nPtr = &N;

    cin >> *mPtr >> *nPtr;
    
    int result = countLuckyTickets(*mPtr, *nPtr);
    cout << result << endl;
    
    return 0;
}