#include<stdio.h>
#include<stdlib.h> // for exit()
#include "sts_queue.h"
 /*
struct test{
    int num1;
    int num2;
};

int main() {
  // Create queue
  //creates the queue at a memory adress
  StsHeader *handle = StsQueue.create();


  //creates array of numbers
  struct test test1;
  test1.num1 = 1;
  test1.num2 = 2;

  struct test test2;
  test2.num1 = 1;
  test2.num2 = 2;

  //push to queue, passes queue and adress of item
  StsQueue.push(handle, &test1);
  StsQueue.push(handle, &test2);

  // Print stuff from queue, returns a (void?) pointer to content 
  struct test *mem;
  while ( (mem = StsQueue.pop(handle)) != NULL) {
	printf("%i\n", (*mem).num1);
    printf("%i\n", (*mem).num2);
  }

  // Kill queue
  StsQueue.destroy(handle);
  return 0;
}
*/
//https://github.com/petercrona/StsQueue