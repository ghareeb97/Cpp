#include <iostream>
#include <vector>
using namespace std;

class Robot{
private:
    int width;
    int length;
protected:
    string name;
    string type;
    int weight;
    int velocity;
    int acceleration;
public:
    // robot default constructor
    Robot(){
        cout << "Entered default constructor" << endl;
        name=" ";
        type=" ";
        weight=1;
        width=0;
        length=0;
        velocity=1;
        acceleration=1;
    }
    // robot custom constructor
    Robot(string name, string type, int weight, int width, int length, int velocity, int acceleration){
        cout << "Entered custom constructor" << endl;
        this->name = name;
        this->type = type;
        this->weight = weight;
        this->width = width;
        this->length = length;
        this->velocity = velocity;
        this->acceleration = acceleration;
    }
    // Robot copy constructor
    Robot(const Robot &r){
        // cout<<"Entered copy constructor"<<endl;
        name=r.name;
        type=r.type;
        weight=r.weight;
        width=r.width;
        length=r.length;
        velocity=r.velocity;
        acceleration=r.acceleration;
    }

    int getVelocity(){
        return velocity;
    }
    // void setVelocity(int velocity){
    //     this->velocity = velocity;
    // }
    int getAcceleration(){
        return acceleration;
    }
    // void setAcceleration(int acceleration){
    //     this->acceleration = acceleration;
    // }
    
    ~Robot(){
    }
};

class MobileRobot : virtual public Robot{
private:
    vector<string> sensors;
    string cameraType;
    string LidarType;
protected:
    int numberOfWheels;
public:
    // Default constructor
    MobileRobot(){
        // cout<<"Entered Default Constructor"<<endl;
        numberOfWheels=0;
        cameraType=" ";
        LidarType=" ";
    }
    // MobileRobot Custom constructor
    MobileRobot(int numberOfWheels,string cameraType,string LidarType){
        // cout<<"Entered Custom Constructor"<<endl;
        this->numberOfWheels=numberOfWheels;
        this->cameraType=cameraType;
        this->LidarType=LidarType;
    }
    // MobileRobot copy constructor
    MobileRobot(const MobileRobot &r){
        // cout<<"Entered copy constructor"<<endl;
        numberOfWheels=r.numberOfWheels;
        sensors=r.sensors;
        cameraType=r.cameraType;
        LidarType=r.LidarType;
    }
    ~MobileRobot(){
        // cout << "Entered destructor" << endl;

    }
    int getNumberOfWheels(){
        return numberOfWheels;
    }
    // void setNumberOfWheels(int numberOfWheels){
    //     this->numberOfWheels = numberOfWheels;
    // }
    int getNumberOfSensors(){
        return sensors.size();
    }
    void move(){

    }

};

class Manipulator : virtual public Robot{
private:    
    int workspace;
    int maxReach;
    vector<string> EndEffectors;
protected:
    int payload;
public:

    // Default constructor
    Manipulator(){
        // cout<<"Manipulator:Entered Default Constructor"<<endl;
        payload=1;
        workspace=0;
        maxReach=0;

    }
    // Manipulator custom constructor
    Manipulator(int payload, int workspace, int maxReach, vector<string> EndEffectors){
        this->payload = payload;
        this->workspace = workspace;
        this->maxReach = maxReach;
        this->EndEffectors = EndEffectors;
    } 
    ~Manipulator(){
        // cout << "Entered destructor" << endl;

    }
    int getPayload(){
        return payload;
    }
    void setEndEffectors(vector<string> EndEffectors){
        this->EndEffectors = EndEffectors;
    }
    int getMaxReach(){
        return maxReach;
    }
    void pickObject(){
    
    }
};

class Location{
protected:
    int *x_meters;
    int *y_meters;
    int *x_cm;
    int *y_cm;
public:
    // Default constructor
    Location(){
        cout<<"Entered custom default constructor"<<endl;
        x_meters=new int(0);
        y_meters=new int(0);
        x_cm=new int(0);
        y_cm=new int(0);
    }
    // Custom constructor
    Location(int x_meters, int x_cm, int y_meters, int y_cm){
        cout<<"Entered custom constructor 2"<<endl;
        this->x_meters=new int;
        this->y_meters=new int;
        this->x_cm=new int;
        this->y_cm=new int;
        
        *this->x_meters=x_meters;
        *this->y_meters=y_meters;
        *this->x_cm=x_cm;
        *this->y_cm=y_cm;
    }
    // COPY constructor
    Location(const Location &r){
        cout<<"Entered custom copy constructor"<<endl;
        this->x_meters=r.x_meters;
        this->y_meters=r.y_meters;
        this->x_cm=r.x_cm;
        this->y_cm=r.y_cm;
    }
    void setter(int x_meters, int x_cm, int y_meters, int y_cm){
        cout<<"Entered setter "<<endl;
        *this->x_meters=x_meters;
        *this->y_meters=y_meters;
        *this->x_cm=x_cm;
        *this->y_cm=y_cm;
    }
    void getter(int &x_meters, int &y_meters, int &x_cm, int &y_cm){
        cout<<"Entered getter "<<endl;
        x_meters=*this->x_meters;
        y_meters=*this->y_meters;
        x_cm=*this->x_cm;
        y_cm=*this->y_cm;
    }

    ~Location(){
        cout<<"Entered destructor"<<endl;

    }
};

class MobileManipulator : public MobileRobot, public Manipulator{
private:
    int range;
    int weight;
    int x_meters, x_cm, y_meters, y_cm;
    // Location of the robot
public:
    Location l1;
    // Default constructor
    MobileManipulator(){
        cout<<"MobileManipulator : Default Constructor"<<endl;
        range=2;
        weight=1;
        x_meters=0;
        y_meters=0;
        x_cm=0;
        y_cm=0;
    }
    // MobileManipulator Custom constructor
    // MobileManipulator(int range, int weight, int workspace, int maxReach, vector<string> EndEffectors){
    //     cout<<"MobileManipulator : Custom Constructor"<<endl;
    //     this->range = range;
    //     this->weight = weight;
    // }
    MobileManipulator(string name, string type, int numberOfwheel, int x_meters, int y_meters, int x_cm, int y_cm){
        cout<<"MobileManipulator : Custom Constructor"<<endl;
        this->name = name;
        this->type = type;
        this->numberOfWheels = numberOfwheel;
        this->x_meters = x_meters;
        this->y_meters = y_meters;
        this->x_cm = x_cm;
        this->y_cm = y_cm;
        range=2;
        weight=1;  
        
    }
    // MobileManipulator copy constructor
    MobileManipulator(const MobileManipulator &r){
        cout<<"MobileManipulator : copy constructor"<<endl;
        name=r.name;
        type=r.type;
        numberOfWheels=r.numberOfWheels;
        range=2;
        weight=1;  
    }
    ~MobileManipulator(){
        cout<<"MobileManipulator : Destructor"<<endl;
    }
    void navigate(){
        l1.getter(x_meters, y_meters, x_cm, y_cm);
        cout << "Location before modification: "
             << " x_meters=" << x_meters
             << " x_cm=" << x_cm
             << " y_meters=" << y_meters
             << " y_cm=" << y_cm
             << endl;
        
             
    }
    void move(){
        cout << "moving..." << endl;
    }
    void pickObject(){
        cout<<"MobileManipulator : Picking Object..."<<endl;

    }
    void display(){
        cout << "Mobile Manipulator data: "
             << "name=" << name 
             << " type=" << type 
             << " weight= " << weight
             << " velocity= " << velocity
             << " acceleration= " << acceleration 
             << " number of wheels= " << numberOfWheels 
             << " payload= " << payload 
             << " range= " << range << endl;
    }
};



int main(){
    // MobileManipulator m1;
    // m1.display();
    // MobileManipulator m2("turtle","waffle", 2, 2.5, 1.5, 2, 6);
    // m2.display();
    // MobileManipulator m3(m2);
    // m3.display();
    // m1.navigate();
    int xm =1;
    int ym =1;
    int xc =1;
    int yc =1;
    int *ptrxm = &xm;
    int *ptrym = &ym;
    int *ptrxc = &xc;
    int *ptryc = &yc;

    cout << *ptrxm << endl;
    cout << *ptrxc << endl;
    cout << *ptrym << endl;
    cout << *ptryc << endl;
    Location l1;
    l1.getter(*ptrxm,*ptrxc,*ptrym,*ptryc);
    cout << "Location after modification: "
         << " x_meters=" << xm
         << " x_cm=" << *ptrxc
         << " y_meters=" << *ptrym
         << " y_cm=" << *ptryc<<endl;
    l1.setter(1, 2, 3, 4);
    l1.getter(*ptrxm,*ptrxc,*ptrym,*ptryc);
    cout << "Location after modification: "
         << " x_meters=" << xm
         << " x_cm=" << *ptrxc
         << " y_meters=" << *ptrym
         << " y_cm=" << *ptryc<<endl;
    MobileManipulator m1;
    m1.display();
    MobileManipulator m2("turtle","waffle", 2, 2.5, 1.5, 2, 6);
    m2.display();
    MobileManipulator m3(m2);
    m3.display();
    // m1.navigate(1,2,3,4);    
    return 0;
}