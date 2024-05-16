#include "floor.h"

Floor::Floor(int n)
{
    num = n;
    slected = P;
}
// when the passenger request an alvator up or down
void Floor::request_elevator(int s){
    qInfo()<<"Floor # "<< s <<" : Passenger presses button \n";
}
