#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
 
void MaxMin(const std::vector<int> &vect, int index = 0, int maxValue = INT_MIN, int minValue = INT_MAX){
    if (index >= vect.size()){
        std::cout<<"Min "<<minValue<<" Max "<<maxValue<<std::endl;
        return;
    }
    
    if(vect[index] < minValue){
        minValue = vect[index];
    }

    if(vect[index] > maxValue){
        maxValue = vect[index];
    }

    MaxMin(vect, ++index, maxValue, minValue);
}

int main(){

    std::vector<int> nums = {1,2,3,-4,10000,6,7,8,9};
    MaxMin(nums);
    
    return 0;
}

