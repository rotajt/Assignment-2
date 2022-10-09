#include <iostream>
#include <fstream>
#include <string>
#include <queue>


using namespace std;

class Person {

    string Name;
    int ID;
    int Age;
public:
    Person(){
        Name="";
        ID = 0;
        Age = 0;
    }
    Person(string Name, int ID, int Age)
    {
        Name = Name;
        ID = ID;
        Age = Age;
    }
    void set_Name(string Name) {
        this->Name = Name;
    }
    void set_ID(int ID) {
         this->ID = ID;
    }
    void set_Age(int Age) {
        this->Age = Age;
    }
    string get_Name() {
        return this->Name;
    }
    int get_ID() {
        return this->ID;
    }
    int get_Age() {
        return this->Age;
    }
    void printinfo(){
        cout <<"The user's name is:" << Name << endl;
        cout <<"The user's ID is:" << ID << endl;
        cout <<"The user's Age is:" << Age << endl;
    }
    ~Person(){
    }
};

struct Appointment{
  int hours;
  int mins;
} appointment;

class customer: public Person {
private:
    int MechanicalID;
    struct Appointment appointment ;

public:
    void set_MechanicID(int MechanicalID) {
        this->MechanicalID = MechanicalID;
    }
    int get_MechanicID(int MechanicalID) {
        return this->MechanicalID;
    }

    void set_Appointment(Appointment appointment) {
        this->appointment = appointment;
    }
    Appointment get_Appointment() {
        return this->appointment;
    }

    bool operator<(customer x)
    {
			if(this->appointment.hours>x.appointment.hours)
                return true;
			else if(this->appointment.hours==x.appointment.hours)
            {
                if(this->appointment.mins>x.appointment.mins)
                    return true;
            }

			return false;
    }

    bool operator>(customer x)
    {
			if(this->appointment.hours<x.appointment.hours)
                return true;
			else if(this->appointment.hours==x.appointment.hours)
            {
                if(this->appointment.mins<x.appointment.mins)
                    return true;
            }

			return false;
    }

    bool operator==(customer x)
    {
			if(this->appointment.hours==x.appointment.hours && this->appointment.mins==x.appointment.mins)
                return true;

			return false;
    }


};

class mechanic: public Person{
private:
    int counter= 0;
    Appointment appointment[24];

public:
    bool isAvailable(Appointment slot){
        for(int i=0; i<24; i++){
            if(this->appointment[i].hours == slot.hours && this->appointment[i].mins==slot.mins){
                return false;
            }
        }
        return true;
    };

    void set_counter(int counter) {
        this->counter = counter;
    };

    int get_counter() {
        return this->counter;
    };

    bool set_appointment(Appointment slot) {
        if(isAvailable(slot)){
            this->appointment[counter]= slot;
            set_counter(this->counter++);

            return true;
        }
        else
        {
            cout<<"Slot is Not Available"<<endl;
            return false;
        }
    }

    Appointment* get_appointment() {
        return this->appointment;
    }

};

template<typename T>
class Queue{
	T* data;
	int frontIndex;    // It stores the index of an element which is present at the top of a queue.
	int rearIndex;     // It tells us the next position in the array where the element is to inserted.
	int maxSize;      // It stores the total capacity of an array.
	int size;         // It stores the number of elements which are being present in the array.

	public:
	Queue(int size){
		maxSize = size;
		data = new T[maxSize];
		frontIndex = -1;
		rearIndex = 0;
		this->size = 0;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	T front(){
        customer c1;
        Appointment fake;
        fake.hours= INT_MAX;
        fake.mins= INT_MAX;
        c1.set_Appointment(fake);

		if(frontIndex == -1){
            cout<<"Queue is empty "<<endl;
			return c1;
		}
		return data[frontIndex];
	}

	void push(T elem){
			if(size == maxSize){
                cout<<"Queue is full "<<endl;
				return;
			}

			if(frontIndex == -1){
				frontIndex = 0;
			}

            Queue <customer>temp(26);


            while(this->front() < elem)
            {
                temp.push(this->front());
                this->pop();
                rearIndex--;


            }

			data[rearIndex] = elem;

			while(!temp.isEmpty())
            {
                this->push(temp.front());
                temp.pop();
                rearIndex++;

            }

			size++;

	}


	void pop(){

		if(frontIndex == -1){
            cout<<"Queue is empty "<<endl;
			return ;
		}

        for (int i = 0; i <size; i++) {
                data[i] = data[i + 1];
        }
        rearIndex--;
        size--;
		if(size == 0){
			frontIndex = -1;
			rearIndex = 0;
		}
		return ;
	}
};


int main() {

    mechanic mech[3];
    //mechanic
    mechanic m1;
    m1.set_Age(20);
    m1.set_ID(0);
    m1.set_Name("Ayman");
    //m1.printinfo();
    mech[0]=m1;

    mechanic m2;
    m2.set_Age(21);
    m2.set_ID(1);
    m2.set_Name("Khaled");
    //m2.printinfo();
    mech[1]=m2;

    mechanic m3;
    m3.set_Age(22);
    m3.set_ID(2);
    m3.set_Name("Mai");
    //m3.printinfo();
    mech[2]=m3;

    //customers
    Appointment ap;

    customer cust[4];

    customer c1;
    c1.set_Age(20);
    c1.set_ID(0);
    c1.set_Name("Ahmed");
    //c1.printinfo();
    ap.hours=1;
    ap.mins=0;
    c1.set_Appointment(ap);
    cust[0]=c1;

    customer c4;
    c4.set_Age(20);
    c4.set_ID(1);
    c4.set_Name("Sara");
    //c4.printinfo();
    ap.hours=4;
    ap.mins=0;
    c4.set_Appointment(ap);
    cust[1]=c4;

    customer c2;
    c2.set_Age(21);
    c2.set_ID(2);
    c2.set_Name("Kareem");
    //c2.printinfo();
    ap.hours=3;
    ap.mins=0;
    c2.set_Appointment(ap);
    cust[2]=c2;

    customer c3;
    c3.set_Age(22);
    c3.set_ID(3);
    c3.set_Name("Mohammed");
    //c3.printinfo();
    ap.hours=1;
    ap.mins=0;
    c3.set_Appointment(ap);
    cust[3]=c3;



    Queue <customer>a(26);

    for(int i=0;i<4;i++)
    {

            if(mech[i%3].set_appointment(cust[i].get_Appointment()))
            {

                    cout<<"Mr/Mrs "<<cust[i].get_Name()<<" should be assigned to "<<mech[i%3].get_Name()<<" at "<<cust[i].get_Appointment().hours<<":"<<cust[i].get_Appointment().mins<<endl;

                }
            else{
                    int j=0;
                while(j<3 && !mech[j%3].set_appointment(cust[i].get_Appointment()))
                {
                    j++;
                }
                cout<<"Mr/Mrs "<<cust[i].get_Name()<<" should be assigned to "<<mech[j%3].get_Name()<<" at "<<cust[i].get_Appointment().hours<<":"<<cust[i].get_Appointment().mins<<endl;
            }
    }

    cout<<"After inserting the customers into the queue"<<endl;

    for (int i=0; i<4; i++){
        a.push(cust[i]);
    };

    for (int i=0; i<4; i++){
        cout<<a.front().get_ID()<<endl;
        a.pop();
    }



}
