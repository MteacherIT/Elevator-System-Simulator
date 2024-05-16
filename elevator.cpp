#include "elevator.h"
#include <QtMath>
#include <QTime>
#include <QString>
Elevator::Elevator(int num )
{
   open_button = 'F';
   close_button = 'O';
   elev_num = num;
    requested_floor = -1;
    current_floor = 0;
    stops_num =0;
    direction = PUSE;
    door = CLOSE;
    current_weight = 0;



}

void Elevator::openDoor(){
    open_button = 'O';
    close_button = 'F';
    qInfo()<<"The door is open \n";

}
void Elevator:: closeDoor(){
    open_button = 'F';
    close_button = 'O';
    qInfo()<<"The door is close \n";

}
// select the moving dirction depend on the floor request
void Elevator::selectDistnatiion(elev_Direction e){
    this->direction = e;

}
void Elevator::ringBell(){
    qInfo()<<"Bell is ringing \n";

}
void Elevator::displayUpdate(QString s){

    qInfo()<<s;

}
void Elevator::audioUpdate(QString a){
    qInfo()<<a;
}
// update the current floor when the elevator stop for any floor
void Elevator::floorUpdate(int num){
    this->current_floor = num;

}
bool Elevator::checkWieght(){
    if(current_weight<=max_weight){
        this->closeDoor();
        QTime endTime3 = QTime::currentTime().addSecs(5);
        while(QTime::currentTime()<endTime3){

        }
        return false;
    }
    return true;


}
void Elevator::updateWieght(int num){
    this->current_weight = num ;
}
// when the elevator pass the floors up or down , it takes 5 second , this fumction update how many floor passed
void Elevator::updateStopesNum(int n){

    stops_num+=n;
}
// convert rnum to string to update the direction in the display
void Elevator::updatDir(QString s){
    this->dir_s = s;
}
// move the car to requested floor before the passenger become insside the elevator
void Elevator::run_car(int y, QString s){

    this->updatDir(s);

    qInfo()<<"Elevator # "<<this->elev_num<<" is ready to move to floor # "<<y<<"\n";
    int steps = qFabs(this->current_floor-y);
    int stopes = steps;
    updateStopesNum(stopes);
    while(steps>0){
         QTime endTime = QTime::currentTime().addSecs(5);
         while(QTime::currentTime()<endTime){

         }
         steps-=1;

    }
    floorUpdate(y);

    qInfo()<<"Elevator "<<this->elev_num<<" arrived at floor "<<y<<"\n";
    QTime endTime1 = QTime::currentTime().addSecs(2);
    while(QTime::currentTime()<endTime1){

    }
    this->ringBell();

    QString ss = QString::number(y);
    this->displayUpdate("Floor # "+ ss);

    this->openDoor();
    QTime endTime2 = QTime::currentTime().addSecs(5);
    while(QTime::currentTime()<endTime2){

    }



}
// move the elevator and passenger to distnation floor
void Elevator::move(int floor_num){

    qInfo()<<"Elavator # "<<this->elev_num<<" is moving "<<dir_s<<"to floor # "<<floor_num<<"\n";

    int steps = qFabs(this->current_floor-floor_num);
    int stopes = steps;
    updateStopesNum(stopes);

    while(steps>0){
         QTime endTime = QTime::currentTime().addSecs(5);
         while(QTime::currentTime()<endTime){

         }
         steps-=1;

    }
    qInfo()<<"Elavator # "<<this->elev_num<<"arrived at floor "<<floor_num<<"\n";
    QTime endTime1 = QTime::currentTime().addSecs(2);
    while(QTime::currentTime()<endTime1){

    }
    this->ringBell();

    QString ss = QString::number(floor_num);
    this->displayUpdate("Floor # "+ ss);

    this->openDoor();
    QTime endTime2 = QTime::currentTime().addSecs(5);
    while(QTime::currentTime()<endTime2){

    }
    this->closeDoor();
    QTime endTime3 = QTime::currentTime().addSecs(5);
    while(QTime::currentTime()<endTime3){

    }

    floorUpdate(floor_num);
    this->selectDistnatiion(PUSE);
    this->updatDir("Puse");


}
