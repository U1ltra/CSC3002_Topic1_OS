#include <iostream>
#include "math.h"
#include <list>
#include <pair.h>
#include <Buddy.h>
using namespace std;

int main(){
    int ini = 128;
    Buddy obj = Buddy(128);
    obj.allocate(16);
    obj.allocate(16);
    obj.allocate(16);
    obj.allocate(16);
    obj.deallocate(0);
    obj.deallocate(9);
    obj.deallocate(32);
    obj.deallocate(16);
    return 0;
}





