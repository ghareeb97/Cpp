#include <iostream>
#include <vector>
using namespace std;

class Robot{
private:
    float width;
    float length;
protected:
    string name;
    string type;
    float weight;
    float velocity;
    float acceleration;
public:
    // robot default constructor
    Robot(){
        // cout << "Entered default constructor" << endl;
        name=" ";
        type=" ";
        weight=1;
        width=0;
        length=0;
        velocity=1;
        acceleration=1;
    }
    // robot custom constructor
    Robot(string name, string type, float weight, float width, float length, float velocity, float acceleration){
        // cout << "Entered custom constructor" << endl;
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

    float getVelocity(){
        return velocity;
    }
    // void setVelocity(float velocity){
    //     this->velocity = velocity;
    // }
    float getAcceleration(){
        return acceleration;
    }
    // void setAcceleration(float acceleration){
    //     this->acceleration = acceleration;
    // }
    
    ~Robot(){
    }
};

class MobileRobot : virtual public Robot{
private:
    vector<string> sensors; //TODO push back sensors
    string cameraType;
    string LidarType;
protected:
    float numberOfWheels;
public:
    // Default constructor
    MobileRobot(){
        // cout<<"Entered Default Constructor"<<endl;
        numberOfWheels=0;
        cameraType=" ";
        LidarType=" ";
    }
    // MobileRobot Custom constructor
    MobileRobot(float numberOfWheels,string cameraType,string LidarType){
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
    float getNumberOfWheels(){
        return numberOfWheels;
    }
    // void setNumberOfWheels(float numberOfWheels){
    //     this->numberOfWheels = numberOfWheels;
    // }
    float getNumberOfSensors(){
        return sensors.size();
    }
    void move(){
        // TODO: robot moving
    }

};

class Manipulator : virtual public Robot{
private:    
    float workspace;
    float maxReach;
    vector<string> EndEffectors;
protected:
    float payload;
public:

    // Default constructor
    Manipulator(){
        // cout<<"Manipulator:Entered Default Constructor"<<endl;
        payload=1;
        workspace=0;
        maxReach=0;

    }
    // Manipulator custom constructor
    Manipulator(float payload, float workspace, float maxReach, vector<string> EndEffectors){
        this->payload = payload;
        this->workspace = workspace;
        this->maxReach = maxReach;
        this->EndEffectors = EndEffectors;
    } 
    ~Manipulator(){
        // cout << "Entered destructor" << endl;

    }
    float getPayload(){
        return payload;
    }
    void setEndEffectors(vector<string> EndEffectors){
        this->EndEffectors = EndEffectors;
    }
    float getMaxReach(){
        return maxReach;
    }
    void pickObject(){
    }
};

class Location{
protected:
    float *x_meters;
    float *y_meters;
    float *x_cm;
    float *y_cm;
public:
    // Default constructor
    Location(){
        cout<<"Entered custom default constructor"<<endl;
        x_meters=new float(0);
        y_meters=new float(0);
        x_cm=new float(0);
        y_cm=new float(0);
    }   
    // Custom constructor
    Location(float x_meters, float x_cm, float y_meters, float y_cm){
        cout<<"Entered custom constructor 2"<<endl;
        this->x_meters=new float(x_meters);
        this->x_cm=new float(x_cm);
        this->y_meters=new float(y_meters);
        this->y_cm=new float(y_cm);
        
        // *this->x_meters=x_meters;
        // *this->y_meters=y_meters;
        // *this->x_cm=x_cm;
        // *this->y_cm=y_cm;
    }
    // COPY constructor
    Location(const Location &r){
        cout<<"Entered custom copy constructor"<<endl;
        // *this->setter(x_meters,x_cm,y_meters, y_cm)
        this->x_meters=new float(*r.x_meters);
        this->y_meters=new float(*r.y_meters);
        this->x_cm=new float(*r.x_cm);
        this->y_cm=new float(*r.y_cm);
        cout<<"Inside copy constructor"
            <<" x_meters:"<<*this->x_meters
            <<" x_cm:"<<*this->x_cm
            <<"................................"
            <<" y_meters:"<<*this->y_meters
            <<" y_cm:"<<*this->y_cm<<endl;
    }
    void setter(float x_meters, float x_cm, float y_meters, float y_cm){

        cout<<"Entered setter "<<endl;
        *(this->x_meters)=x_meters;
        *(this->y_meters)=y_meters;
        *(this->x_cm)=x_cm;
        *(this->y_cm)=y_cm;
    }
    void getter(float &x_meters, float &x_cm, float &y_meters, float &y_cm){
        cout<<"Entered getter "<<endl;
        x_meters=*this->x_meters;
        x_cm=*this->x_cm;
        y_meters=*this->y_meters;
        y_cm=*this->y_cm;
    }
    // override + operator to add 2 locations
    Location operator+(const Location o){
        cout<<"Inside Operator Overloading Method"<<endl;
        Location temp(*o.x_meters, *o.x_cm, *o.y_meters, *o.y_cm);
        float x_meters2, y_meters2, x_cm2, y_cm2;
     
        *temp.x_meters += *this->x_meters;
        *temp.x_cm += *this->x_cm;
        *temp.y_meters += *this->y_meters;
        *temp.y_cm += *this->y_cm;
        if(*temp.x_cm >=100)
        {
            *temp.x_cm=*temp.x_cm-100;
            *temp.x_meters +=1;
        }
        if(*temp.y_cm >=100)
        {
            *temp.y_cm=*temp.y_cm-100;
            *temp.y_meters +=1;
        }

        return temp;
        
        
    }

    ~Location(){
        cout<<"Entered destructor"<<endl;
            // delete x_meters;
            // delete y_meters;
            // delete x_cm;
            // delete y_cm;

    }
};

class MobileManipulator : public MobileRobot, public Manipulator{
private:
    float range;
    float weight;
    float x_meters, x_cm, y_meters, y_cm;
public:
    Location l1;
    // Default constructor
    MobileManipulator(){
        cout<<"MobileManipulator : Default Constructor"<<endl;

        // x_meters=1;        weight=1;  

        // y_meters=2;
        // x_cm=3;
        // y_cm=4;
    }
    // MobileManipulator Custom constructor
    // MobileManipulator(float range, float weight, float workspace, float maxReach, vector<string> EndEffectors){
    //     cout<<"MobileManipulator : Custom Constructor"<<endl;
    //     this->range = range;
    //     this->weight = weight;
    // }
    MobileManipulator(string name, string type, float numberOfwheel, float velocity, float acceleration, float range, float payload){
        cout<<"MobileManipulator : Custom Constructor"<<endl;
        this->name = name;
        this->type = type;
        this->numberOfWheels = numberOfwheel;
        this->velocity = velocity;
        this->acceleration = acceleration;
        this->range = range;
        this->payload = payload;
        // this->x_meters = x_meters;
        // this->y_meters = y_meters;
        // this->x_cm = x_cm;
        // this->y_cm = y_cm;
        // l1.setter(this->x_meters, this->x_cm, this->y_meters, this->y_cm);
        
    }
    // MobileManipulator copy constructor //TODO: inherit copy from others
    MobileManipulator(const MobileManipulator &r){
        cout<<"MobileManipulator : copy constructor"<<endl;
        name=r.name;
        type=r.type;
        numberOfWheels=r.numberOfWheels;
        velocity=r.velocity;
        acceleration=r.acceleration;
        range=r.range;
        payload = r.payload;
        weight = r.weight;
    }
    ~MobileManipulator(){
        cout<<"MobileManipulator : Destructor"<<endl;
    }
    void navigate(float n_xm, float n_xc, float n_ym,float n_yc){
        float x_meters2, y_meters2, x_cm2, y_cm2;
        l1.getter(x_meters2, x_cm2, y_meters2, y_cm2);
        cout << "Location before modification: "
             << " x_meters=" << x_meters2
             << " x_cm=" << x_cm2
            <<"................................"
             << " y_meters=" << y_meters2
             << " y_cm=" << y_cm2
             << endl;
        Location l2(n_xm, n_xc, n_ym, n_yc); 
        Location l3 = l1 + l2;
        l3.getter(x_meters2, x_cm2, y_meters2, y_cm2);
        l1.setter(x_meters2, x_cm2, y_meters2, y_cm2);
        cout<<"navigated"<<endl;
        cout << "Location modified: "
             << " x_meters=" << x_meters2
             << " x_cm=" << x_cm2
            <<"................................"
             << " y_meters=" << y_meters2
             << " y_cm=" << y_cm2
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
    MobileManipulator m1;
    m1.display();
    MobileManipulator m2("turtle","waffle", 2, 2.5, 1.5, 2, 6);
    m2.display();
    MobileManipulator m3(m2);
    m3.display();
    m1.navigate(1,150,3,100);
    m1.move();
    m1.pickObject();
    return 0;
}