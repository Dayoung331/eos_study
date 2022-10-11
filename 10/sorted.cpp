#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstring>

#include "sorted.h"

using namespace std;

SortedArray::SortedArray(){

}
SortedArray::~SortedArray(){
    for(int i=0; i<(int)numbers_.size(); i++){
        numbers_.pop_back();
    }
}

void SortedArray::AddNumber(int num){
    numbers_.push_back(num);
}
vector<int> SortedArray::GetSortedAscending(){
    sort(numbers_.begin(), numbers_.end());
    return numbers_;
}
vector<int> SortedArray::GetSortedDescending(){
    sort(numbers_.begin(), numbers_.end(), greater<int>());
    return numbers_;
}
int SortedArray::GetMax(){
    return *max_element(numbers_.begin(), numbers_.end());
}
int SortedArray::GetMin(){
    return *min_element(numbers_.begin(), numbers_.end());
}