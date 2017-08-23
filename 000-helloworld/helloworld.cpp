#include <iostream>
#include <stdint.h>

int main (int argc, char **argv)
{

   std::cout << "hello world" << std::endl;

   uint8_t   i = 0;
   uint8_t  counter  = -1;
   uint16_t  counter2 = 1; 
   uint32_t  counter3 = 2;

   while(i < 10)
   {
      std::cout << "counter: " << std::dec << static_cast<int>(counter) << "," << std::hex <<  static_cast<int>(counter) << std::endl;
      ++i;
      ++counter; // vs counter = counter + 1;
   }

std::cout << "----------------------" << std::endl;

    counter = 255;
    
   for (int j = 0; j < 10; ++j)
   {
      std::cout << "counter: " << std::dec << static_cast<int>(counter) << "," << std::hex << static_cast<int>(counter) << std::endl;
      counter = counter>>1;
   }

std::cout << "----------------------" << std::endl;


    counter3 = 0xFFFF;
    
   for (int j = 0; j < 10; ++j)
   {
      std::cout << "counter3: " << std::dec << static_cast<int>(counter3) << "," << std::hex << static_cast<int>(counter3) << std::endl;
      counter3 = counter3>>1;
   }



   return 0;
}

