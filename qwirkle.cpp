
#include "LinkedList.h"
#include "QwirkleGameEngine.h"
#include <iostream>

#define EXIT_SUCCESS 0

int main(void) {
   LinkedList *list = new LinkedList();
   delete list;

   std::cout << "Welcome to Qwirkle" << std::endl;
   std::cout << "------------------" << std::endl;

   QwirkleGameEngine *engine = new QwirkleGameEngine();
   engine->start();

   delete engine;
   return EXIT_SUCCESS;
}
