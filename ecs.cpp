#include "ecs.h"

// create list of elevators passengers anf floors inside ECS

ECS::ECS(int num_E, int num_P, int num_F)
{
    for(int i = 1 ; i<num_E+1; ++i){
        Elevator* e = new Elevator(i);
        elevators.append(e);
    }
    qInfo()<<num_E<<" Elevator opjects are created \n";
    for(int i = 0 ; i<num_P; ++i){
        Passenger* p = new Passenger(i);
        passengers.append(p);
    }
    qInfo()<<num_P<<" Passenger opjects are created \n";
    for(int i = 0 ; i<num_F; ++i){
        Floor* f = new Floor(i);
        floors.append(f);
    }
    qInfo()<<num_F<<" Floor opjects are created \n";
}

// first use case allocation stratigy , chosoe the closer elevator to the requested floor
void ECS::elevator_Centered_Strategy( int floorNum, QString dir){
    int closer = 0;

    if((qFabs(elevators[0]->current_floor - floorNum))<= (qFabs(elevators[1]->current_floor-floorNum)) ){
          closer = 0;


       }
     else{
            closer = 1;
        }


   add_request(closer,floorNum ,dir);

}

// first use case allocation stratigy , choose the less floor stopes elevator
void ECS::al_Strategy(int flNum, QString dir){
    int elev_stops = 0;

    if(elevators[0]->stops_num <=elevators[1]->stops_num){
         elev_stops = 0;
     }
    else{
            elev_stops = 1;
        }


    add_request(elev_stops,flNum, dir);


}

// add the floor request to the choosen elevator vector object

void ECS::add_request(int elevator_num, int floor_num, QString direction){
    elevators[elevator_num]->requests.append(floor_num);

    qInfo()<<"Elevator # "<<elevator_num+1<<" selected to move to Floor # "<<floor_num<<" \n";
    this->notify(elevator_num,floor_num, direction);

}
// notify the elevator about the new floor request
void ECS::notify(int x, int y, QString s){
    elevators[x]->run_car(y, s);
    \
}
