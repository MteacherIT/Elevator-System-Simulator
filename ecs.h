#ifndef ECS_H
#define ECS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QList>
#include <QtMath>


#include <elevator.h>
#include <passenger.h>
#include <floor.h>

class ECS
{
public:
    QList<Elevator*> elevators;
    QList<Passenger*> passengers;
    QList<Floor*> floors;


    int num_E;
    int num_P;
    int num_F;
    ECS(int num_E, int num_p, int num_F);

    void elevator_Centered_Strategy(int i, QString dir);
    void al_Strategy(int flNum, QString dir);
    void add_request(int elevator_num, int floor_num, QString dir);
    void notify(int x , int y,QString s);
    void checkOverLoad();



};

#endif // ECS_H
