#include <iostream>
 #include <vector>
 #include <chrono>
 
 std::vector<int> SieveOfEratosthenes(int num) {
     std::vector<int> answers;
     std::vector<bool> prime(num + 1, true);
     int p = 2;
     while (p * p <= num) {
         if (prime[p]) {
             for (int i = p * p; i <= num; i += p) {
                 prime[i] = false;
             }
         }
         p++;
     }
     for (int p = 2; p <= num; p++) {
         if (prime[p]) {
             answers.push_back(p);
         }
     }
     return answers;
 }
 
 vector<int> lessDisastercode() {
     std::vector<int> primes = SieveOfEratosthenes(1000);
     return SieveOfEratosthenes(2500);
 }
