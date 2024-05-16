#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QDebug>
#include <QString>
//the dirction status up down or puse , its not in request
enum elev_Direction {
    PUSE,
    UP,
    DOWN
};


// the elevator door states

enum elev_door{
    OPEN,
    CLOSE
};

class Elevator : public QObject

{
public:
    Elevator(int num);


    char open_button;
    char close_button;
    int elev_num;
    int requested_floor;
    int current_floor;
    int stops_num;
    enum elev_Direction direction ;
    enum elev_door door;
    int current_weight;
    int max_weight = 1000; // max mumm weight is 1000 KG
    QString dir_s ;
    QVector<int> requests;

    void openDoor();
    void closeDoor();
    void selectDistnatiion(elev_Direction e);
    void ringBell();
    void displayUpdate(QString s);
    void audioUpdate(QString a);
    void floorUpdate(int num);
    bool checkWieght();
    void updateStopesNum(int n);
    void run_car(int y, QString s);
    void move(int floor_num);
    void updatDir(QString s);
    void updateWieght(int num);


};

#endif // ELEVATOR_H


