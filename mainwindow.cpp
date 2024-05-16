#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ecs.h"
#include <QObject>
#include <QMessageBox>
#include <QTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

// button to start simulation,
void MainWindow::on_pushButton_simulation_clicked()
{
    QString e = ui->lineEdit_elevators->text();

    int elevNums = e.toInt();

    QString f = ui->lineEdit_floors->text();
    int flNum = f.toInt();

    QString p = ui->lineEdit_passenges->text();
    int pNum = p.toInt();

    ecs_elevator = new ECS(elevNums,pNum, flNum);

// initialize the elevators floor button dynamically

    for(int i = 1; i<=flNum; ++i ){

        QVBoxLayout* L= qobject_cast<QVBoxLayout*>(ui->verticalLayout_2->layout());

        QPushButton* button = new QPushButton();
        button->setText(QString::number(i));
        button->setObjectName(QString::number(i));
        L->addWidget((button));
        button->show();
        QObject::connect(button, &QPushButton::clicked, this,&MainWindow::floor_request);

    }


    return;
}
// for the elevator floor buttons press
void MainWindow::floor_request(){
    QObject *senderO = sender();
    QString name = senderO->objectName();
    int floorNum = name.toInt();

    QString floor = ui->lineEdit_floorNum->text();
     int flNum = floor.toInt();

    if(ecs_elevator->elevators[1]->current_floor == flNum){

       ecs_elevator->elevators[1]->move(floorNum);
    }else {
        ecs_elevator->elevators[0]->move(floorNum);

}



}

// floor up button

void MainWindow::on_UP_clicked()
{
    QObject *sender1 = sender();
    QString name = sender1->objectName();

    QString floor = ui->lineEdit_floorNum->text();
     qInfo()<<"name"<<name<<"\n";
    int floor_num = floor.toInt();

  // Elevator Centred Strategy
    //ecs_elevator->elevator_Centered_Strategy(floor_num,name );

  // al Strategy

     ecs_elevator->al_Strategy(floor_num, name);
}
//floor down button
void MainWindow::on_DOWN_clicked()
{
    QObject *sender2 = sender();
    QString name = sender2->objectName();

    QString floor = ui->lineEdit_floorNum->text();

    int floor_num = floor.toInt();

    // Elevator Centred Strategy
    ecs_elevator->elevator_Centered_Strategy(floor_num,name );

    // al Strategy

     //ecs_elevator->al_Strategy(floor_num, name);
}
// over wieght button
void MainWindow::on_pushButton_5_clicked()

{
    QString w = ui->lineEdit->text();
     int wieght = w.toInt();

    ecs_elevator->elevators[ElevatorNum()]->updateWieght(wieght);
    if(ecs_elevator->elevators[ElevatorNum()]->checkWieght()){
        QMessageBox::warning(this, "Over load", " Reduce the load plaes before move!");
    }
}
// check the car number requested
int MainWindow::ElevatorNum(){
    QString floor = ui->lineEdit_floorNum->text();
     int flNum = floor.toInt();

    if(ecs_elevator->elevators[1]->current_floor == flNum){

        return 1;
    }else {

        return 0;

        }
    return 0;

}
// open button
void MainWindow::on_pushButton_clicked()
{
    ecs_elevator->elevators[ElevatorNum()]->openDoor();
}
//close button
void MainWindow::on_pushButton_2_clicked()
{
    ecs_elevator->elevators[ElevatorNum()]->closeDoor();
}
// block door button
void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::warning(this, "Door Block", " Door Block!");
    ecs_elevator->elevators[ElevatorNum()]->displayUpdate("Display: Door Block!");
     ecs_elevator->elevators[ElevatorNum()]->audioUpdate("Audio: Door Block!");
     QTime endTime3 = QTime::currentTime().addSecs(5);
     while(QTime::currentTime()<endTime3){
         ui->pushButton->setEnabled(false);
         ui->pushButton_2->setEnabled((false));
     }
     ui->pushButton->setEnabled(true);
     ui->pushButton_2->setEnabled((true));
}
//power Outage button
void MainWindow::on_pushButton_4_clicked()
{
    ecs_elevator->elevators[ElevatorNum()]->displayUpdate("Display:Power Outage!");
    ecs_elevator->elevators[ElevatorNum()]->audioUpdate("Audio: Power Outage!");
    ecs_elevator->elevators[0]->move(1);
    ecs_elevator->elevators[1]->move(1);
    ecs_elevator->elevators[ElevatorNum()]->displayUpdate("Display:The safe floor is reached,disembark please !");
    ecs_elevator->elevators[ElevatorNum()]->audioUpdate("Audio: The safe floor is reached,disembark please !");


}
// help button
void MainWindow::on_pushButton_3_clicked()
{
// generate random number between 0 and 9 or 8 to randomize the building saftey service or passenger respond to get differnt situation
    int x = qrand()%8;
    int y = qrand()%9;


    if(x<5 || y<5){
        qInfo()<<"The passenger  is connected to  Building Saftey Service\n";
    }else{
         qInfo()<<"911 Emergency call is placed \n";

    }
}
