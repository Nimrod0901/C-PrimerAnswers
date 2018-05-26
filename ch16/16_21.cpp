/*
 * @Author: Nimrod 
 * @Date: 2018-05-26 20:11:50 
 */
#include "16_21.h"
#include <memory>

int main() {
    double *dp = new double;
    DebugDelete d;
    d(dp);
    int *ip = new int;
    DebugDelete() (ip);
    return 0;
}