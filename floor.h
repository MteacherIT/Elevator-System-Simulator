#ifndef FLOOR_H
#define FLOOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QDebug>
#include <QString>

enum fl_button{
    P,
    U,
    D
};

class Floor
{
public:
    int num;
    enum fl_button slected;

    Floor(int num);

    void request_elevator(int s);
};

#endif // FLOOR_H
