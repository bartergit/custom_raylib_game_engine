#include "utility.h"


int get_unique_id(){
    static int i = 0;
    return i++;
}