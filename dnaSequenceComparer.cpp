/// dnaSequenceComparer.cpp : This file contains the 'main' function. Program execution begins and ends there.
///
/// author:Josh Matulenas
/// 
/// Generates two 4-tuples of user-defined length, with the format "Letter,Number". 
/// 
/// Searches for matching letters in tuples, 
/// then calculates closeness by getting the absolute value of difference of the two Numbers.
/// 
/// The Complexity of the algorithm is: 
/// O(M)+O(N)+O(Min(N,M) == O(N+M)+O(Min(M,N)), where N=Length of sequence N, M=Length of sequence M
/// 
/// This is because we must loop N and M times to construct each sequence respectively.
/// Then we must loop Min(N,M) times to compare each sequence.
/// 
#include "dnaSequenceComparer.h"
#include <ctime>
#include <cmath>
#include <iostream>

int main()
{
    SequenceComparer* sequence = new SequenceComparer;
    sequence->compareSequences();
    delete sequence;
    return 0;
}

void SequenceComparer::genSequences()
{
    std::string s;
    std::string nums;
    int sequenceLength;
    char c;
    int seqNums;
    int r;
    std::cout << "Enter length of new sequence M: "; std::cin >> sequenceLength; 
    while (!std::cin)
    {
        std::cout << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Enter length of new sequence M: "; std::cin >> sequenceLength;

    }
    std::cout << std::endl;
    srand(time(NULL));     // initialize the random number generator
    for (int i = 0; i < sequenceLength; i++) //*O(M)*
    {
        r = rand() % 26;   // generate a random number
        c = 'A' + r;       // Convert to a character from A-Z
        std::random_device seq;
        std::normal_distribution<float> generator (300.0, 100.0);
        seqNums = (int)round(generator(seq));
        nums = std::to_string(seqNums);
        s = c + nums;
        this->_fullSequenceM.push_back(s);
    }
    std::cout << "Enter length of new sequence N: "; std::cin >> sequenceLength;
    while (!std::cin)
    {
        std::cout << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Enter length of new sequence N: "; std::cin >> sequenceLength;

    }
    srand(time(NULL));     // initialize the random number generator
    for (int i = 0; i < sequenceLength; i++)//*O(N)*
    {
        r = rand() % 26;   // generate a random number
        c = 'A' + r;       // Convert to a character from A-Z
        std::random_device seq;
        std::normal_distribution<float> generator(300.0, 100.0);
        seqNums = (int)round(generator(seq));
        nums = std::to_string(seqNums);
        s = c + nums;
        this->_fullSequenceN.push_back(s);
    }
}
void SequenceComparer::compareSequences()
{
    int scoreIntN;
    int scoreIntM;
    std::string scoreStringN;
    std::string scoreStringM;
    genSequences();
    if (this->_fullSequenceM.size() > this->_fullSequenceN.size()) {
        for (int i = 0; i < this->_fullSequenceN.size(); i++)   // if M>N, O(N). No need to compare rest, as guaranteed to be not a match
        {
            if (this->_fullSequenceN[i].front() == this->_fullSequenceM[i].front())
            {
                scoreStringN = this->_fullSequenceN[i].substr(1);
                scoreIntN = std::stoi(scoreStringN);
                scoreStringM = this->_fullSequenceM[i].substr(1);
                scoreIntM = std::stoi(scoreStringM);
                
                std::cout << "Match found: " << this->_fullSequenceM[i] 
                          << " and " << this->_fullSequenceN[i] 
                          << ", with a closeness of: " << ((1000 - (abs(scoreIntM - scoreIntN))) / 10)
                          << std::endl;
            }
        }
    }
    else {
        for (int i = 0; i < this->_fullSequenceM.size(); i++)   // if M<N, O(M). No need to compare rest, as guaranteed to be not a match
        {
            if (this->_fullSequenceN[i].front() == this->_fullSequenceM[i].front())
            {
                scoreStringN = this->_fullSequenceN[i].substr(1);
                scoreIntN = std::stoi(scoreStringN);
                scoreStringM = this->_fullSequenceM[i].substr(1);
                scoreIntM = std::stoi(scoreStringM);
               
                std::cout << "Match found: " << this->_fullSequenceM[i] 
                          << " and " << this->_fullSequenceN[i] 
                          << ", with closeness of: " << ((1000 - (abs(scoreIntM - scoreIntN))) / 10) 
                          << std::endl;
            }
        }
    }
}
