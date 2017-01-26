//Dustin W. Pack
//25 JAN 2017
//g++ algo4.cpp -o maxSum -g -Wall

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
#include <sys/stat.h>
#include <ctime>
#include <cstdlib>


// NOTES FOR GROUP INCLUDE LIMITS??
#include <limits>

class Timer {
private:
    timespec begin, end;
public:
    Timer() {
        clock_gettime(CLOCK_REALTIME, &begin);
    }
    double elapsed() {
        clock_gettime(CLOCK_REALTIME, &end);
        return end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec);
    }
    void reset() {
        clock_gettime(CLOCK_REALTIME, &begin);
    }
    
};


// Prototypes.
//void maxSumSubArray_1(std::vector<std::vector<int> > allData, std::vector<std::vector<int> > &results, int showTime);
//void maxSumSubArray_2(std::vector<std::vector<int> > allData, std::vector<std::vector<int> > &results, int showTime);
void maxSumSubArray_3();
void maxSumSubArray_4();
bool fileExists(std::string fileName);
void append2file(std::vector<std::vector<int> > &results);

/*
void maxSumSubArray_4(std::vector<int> > allData, std::vector<std::vector<int> > &results, int showTime) {
    
    //1D int vector to capture the maxSumSubArray elements.
    std::vector<int> resultsData;
    
    //1D int vetor (of length 1) to capture maxSumSubarray total.
    std::vector<int> mssTotal;
    
    //Clear 2D results vector (passed by ref, so old 1D vectors still hanging around).
    //results.clear();
    
    Timer algoTime;
    
    
    // Determine max sum of subarray with a nonrecursive linear time O(n) method.
 
    
    int theArray[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    
    int currentSum = 0;
    int maxSum = std::numeric_limits<int>::min();  //Initially set MaxSum to the lowest possible integer.
    int currentArrayStart = 0;
    int maxStart = 0; //Beginning index of the max subarray
    int maxEnd = 0; //Ending index of the max subarray
    
    for (int i = 0; i < theArray.length(); i++) {
        currentSum = currentSum + theArray[i];
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        
    }
    
    
}
*/


int main () {
    
    std::cout << "Hello SubArray" << std::endl; //notifies user that file compiled
    
    /* Determine max sum of subarray with a nonrecursive linear time O(n) method.
     */
    
    //int testArray[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    std::vector<int> theArray;
    theArray.push_back(31);
    theArray.push_back(-41);
    theArray.push_back(59);
    theArray.push_back(26);
    theArray.push_back(-53);
    theArray.push_back(58);
    theArray.push_back(97);
    theArray.push_back(-93);
    theArray.push_back(-23);
    theArray.push_back(84);
    
    int currentSum = 0;
    int maxSum = std::numeric_limits<int>::min();  //Initially set MaxSum to the lowest possible integer.
    
    std::cout << "maxSum Initial Value = " << maxSum << std::endl;
    
    int currentArrayStart = 0;
    int maxStart = 0; //Beginning index of the max subarray
    int maxEnd = 0; //Ending index of the max subarray
    
    for (int i = 0; i < theArray.size(); i++) {
        currentSum = currentSum + theArray[i];
        
        
        
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxStart = currentArrayStart;
            maxEnd = i;
        } else if (currentSum < 0) {
            currentSum = 0;
            currentArrayStart = i+1;
        }
        
        std::cout << "loop# " << i << std::endl;
        std::cout << "Max Sum = " << maxSum << std::endl;
        std::cout << "maxStart Index = " << maxStart << std::endl;
        std::cout << "maxEnd Index = " << maxEnd << std::endl;
        std::cout << std::endl;
    }
    
    

    
    return 0;
}
