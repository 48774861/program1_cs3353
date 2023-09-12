#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include <stack>
#include <cmath>
#include "stuff.h"

using namespace std;

void build_hlist(std::stack<int>& hlist, size_t sort_list_size, int code) {
   hlist.push(1);

   if(code == 1) {
      int k = 2;
      size_t currentNumber = pow(k,2);
      //Keep adding k^2 to the hlist until it is greater than s.size().
      while(currentNumber < sort_list_size) {
         hlist.push(currentNumber);
         k++;
         currentNumber = pow(k,2);
      }
      
   } else if (code == 2) {
      int k = 1;
      size_t currentNumber = pow(2,k);
      //Keep adding 2^k to the hlist until it is greater than s.size().
      while(currentNumber < sort_list_size) {
         hlist.push(currentNumber);
         k++;
         currentNumber = pow(2,k);
      }

   } else if (code == 3) {
      int k = 2;
      size_t currentNumber = pow(2,k) - 1;
      //Keep adding 2^k - 1 to the hlist until it is greater than s.size().
      while(currentNumber < sort_list_size) {
         hlist.push(currentNumber);
         k++;
         currentNumber = pow(2,k) - 1;
      }

   } else if (code == 4 && sort_list_size > 8) { //If s.size() <= 8, hlist is just 1.
      int k = 0;
      size_t currentNumber = pow(4,k+1) + 3*pow(2,k) + 1;
      //Keep adding 4^{k+1} + 3*2^k + 1 to the hlist until it is greater than s.size().
      while(currentNumber < sort_list_size) {
         hlist.push(currentNumber);
         k++;
         currentNumber = pow(4,k+1) + 3*pow(2,k) + 1;
      }
      
   } else if(code != 0 && code != 4) { // Must check code != 4 because of s.size() check.
      throw std::invalid_argument("Code must be integers between 0 and 4!\n");
      //Throw an error.
   }
}

void test_hlist(std::stack<int>& hlist) {
   while(!hlist.empty()) {
      cout << hlist.top() << ", ";
      hlist.pop();
   }
   cout << "\n";
}

void ShellSort(vector<Stuff>& s, int code) {
   // Sort the vector s in stuff in Descending Order.
   std::stack<int> hlist;
   build_hlist(hlist, s.size(), code);

   while(!hlist.empty()) {
      int h = hlist.top();
      hlist.pop();
      for(int j = 1; j < s.size(); j++) {
         int i = j;
         while((i >= h) && (s.at(i) < s.at(i-h))) {
            Stuff temp(s.at(i));
            s.at(i) = s.at(i-h);
            s.at(i-h) = temp;
            i -= h;
         }
      }
   }

}


int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
   int vector_sizes[] = {3000, 5000, 7000, 9000, 11000, 13000, 15000};
   for(size_t vec_i = 0; vec_i < 7; vec_i++) {

      std::cout << "\n\n\nVector Size: " << vector_sizes[vec_i] << "\n\n\n";
      for(int code = 0; code < 5; code++) {
         vector<int> compareCounts(100);
         for(int i = 0; i < 100; i++) {
            vector<Stuff> vec;
            size_t vec_size = vector_sizes[vec_i];

            for (size_t i = 0; i < vec_size; i++)
            {
               Stuff s;
               vec.push_back(s);
            }

            // for (size_t i = 0; i < vec_size; i++)
            // {
            //    cout << vec[i] << endl;
            // }

            // cout << "-----\n";

            // uncomment this line when the shell sort is implemented
            ShellSort(vec, code);

            // for (size_t i = 0; i < vec_size; i++)
            // {
            //    cout << vec[i] << endl;
            // }

            //cout << (vec[0] < vec[1]) << endl;
            //cout << "compareCount : " << Stuff::compareCount << endl;
            compareCounts.at(i) = Stuff::compareCount;
            Stuff::compareCount = 0;
         }
         std::cout << "={";
         for(int i = 0; i < 99; i++) {
            std::cout << compareCounts.at(i) << ";";
         }
         std::cout << compareCounts.at(99) << "}\n\n";
      }
   }
}
