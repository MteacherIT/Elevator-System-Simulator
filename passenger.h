#ifndef PASSENGER_H
#define PASSENGER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Passenger : public QObject
{
public:
    int num;
    Passenger(int num);
};

#endif // PASSENGER_H
