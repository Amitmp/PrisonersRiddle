/* 
   This program implements the problem and solution described in The Veritasium Youtube channel
   https://www.youtube.com/watch?v=iSNsgj1OCLA

   Defaults :
   numberOfPrisioners = 100
   numberOfTries     = 100

*/

#include <iostream>
#include <array>
#include <unordered_map>
#include <ctime> 

void swapNum(unsigned int* a, unsigned int* b)
{
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

void generateRandom(std::unordered_map<size_t, unsigned>& box, unsigned n)
{
    for (int i = 0; i < n; i++)
    {
        box[i] = i;
    }

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swapNum(&box[i], &box[j]);
    }
}

void printBox(std::unordered_map<size_t, unsigned>& box)
{
    for (auto itr : box) {
        std::cout << itr.first << " : " << itr.second << "\n";
    } 
}

void fillPrisoners(std::vector<unsigned>& prisioners, size_t numberOfPrisoners)
{
    for (size_t i = 0; i < numberOfPrisoners; i++) {
        prisioners.push_back(i);
    }
}

void showPrisoners(std::vector<unsigned>& prisioners)
{
    for (auto itr : prisioners) {
        std::cout << itr << "\t";
    }
}

bool prisonerSearch(std::unordered_map<size_t, unsigned>& box, size_t prisoner, size_t numberOfPrisoners)
{
    size_t searchBox = prisoner;
    size_t count = 0;
    while((box.at(searchBox) != prisoner) && count < (numberOfPrisoners/2)) {
        //std::cout << "prisoner "<< prisoner <<" searching in box : " << box.at(searchBox)<< " : # of tries="<< count <<"\n";
        count++;
        searchBox = box.at(searchBox);
    }
    if (box.at(searchBox) == prisoner) {
        //std::cout << "FOUND : " << prisoner << " : " << searchBox << "\n";
        return true;
    }
    else if (count == (numberOfPrisoners / 2)) {
        // std::cout << prisoner << " FAILED ";
        return false;
    }
    return false;
}

int main()
{
   size_t numberOfPrisoners = 100;
   size_t numberOfTries = 500;
   size_t fail = 0;
   size_t pass = 0;
   size_t total_fail = 0;
   bool status = false;
   std::vector<unsigned> prisoners;
   srand(time(NULL));
   std::unordered_map<size_t, unsigned> box;

   fillPrisoners(prisoners, numberOfPrisoners);
   //showPrisoners(prisoners);

   for (size_t j = 0; j < numberOfTries; j++) {
       pass = 0;
       fail = 0;

       generateRandom(box, numberOfPrisoners);
       //printBox(box);
       for (size_t i = 0; i < numberOfPrisoners; i++) {
           status = prisonerSearch(box, i, numberOfPrisoners);
           if (status) {
               //std::cout << "prisoner " << i << " : " << status <<"\n";
               pass++;
           }
           else {
               //std::cout << "prisoner " << i << " : " << status << "\n";
               fail++;
               break;
           }
         }

       if (fail > 0) {
           total_fail++;
           //std::cout << "\n" << total_fail << "\n";
       }
   }

   std::cout << "No. of tries: " << numberOfTries << " \t Success: " << ((numberOfTries-total_fail)*100/ numberOfTries) <<"%"<< std::endl;

   return 0;
}
