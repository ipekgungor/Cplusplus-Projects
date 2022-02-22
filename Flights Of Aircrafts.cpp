#include<iostream>
#include<algorithm>
using namespace std;

//------------------
class Flight{
	private:
		string flightName;	
		int launchHour;
		int launchMin;
		int landHour;
		int landMin;
		int duration;
		string state;
	public:
		int getLaunchHour();
		int getLaunchMin();
		int getLandHour();
		int getLandMin();
		string getFlightName();
		string getState();
		void setState(string);
		void calculateLanding();
		Flight(){}
		Flight(string flight_name, int launch_hour, int launch_minutes, int flight_duration){
			flightName = flight_name;
			launchHour = launch_hour;
			launchMin = launch_minutes;
			duration = flight_duration;
			state = "IDLE";
			calculateLanding();

		}
};

string Flight::getFlightName(){
	return flightName;
}
int Flight::getLaunchHour(){
	return launchHour;
}
int Flight::getLaunchMin(){
	return launchMin;
}
string	Flight::getState(){
	return state;
}
void Flight::setState(string flightState){
	state = flightState;
}
void Flight::calculateLanding(){
	landMin = launchMin + duration;
	landHour = launchHour + landMin/60; 
	landMin = landMin%60;
	if(landHour == 24 || landHour > 24){
		landHour = landHour - 24;
    }
}
int Flight::getLandHour(){
	return landHour;
}
int Flight::getLandMin(){
	return landMin;
}

//-------------------------------------

class FlightSchedule{
	private:
		Flight flights[3];
		int currentIndex ;
	public:
		void addFlightToSchedule(Flight);
		Flight * getFlights(){
			return flights;
		}
};

void FlightSchedule::addFlightToSchedule(Flight flight){
	flights[currentIndex] = flight;
	currentIndex++;
}

//-------------------------------------

class LaunchController{
	protected:
	int launchHour1;
	int launchHour2;
	int launchMin1;
	int launchMin2;
	public:
		void launchSchedule(FlightSchedule *);
};

void LaunchController::launchSchedule(FlightSchedule * flightSchedule){
	if( flightSchedule->getFlights()[0].getLaunchHour() > flightSchedule->getFlights()[1].getLaunchHour() || (flightSchedule->getFlights()[0].getLaunchHour() == flightSchedule->getFlights()[1].getLaunchHour()&&flightSchedule->getFlights()[0].getLaunchMin() > flightSchedule->getFlights()[1].getLaunchMin()) ){
		swap(flightSchedule->getFlights()[0], flightSchedule->getFlights()[1]); 
	}
	if (flightSchedule->getFlights()[0].getLaunchHour() > flightSchedule->getFlights()[2].getLaunchHour() || (flightSchedule->getFlights()[0].getLaunchHour() == flightSchedule->getFlights()[2].getLaunchHour()&&flightSchedule->getFlights()[0].getLaunchMin() > flightSchedule->getFlights()[2].getLaunchMin())){
		swap(flightSchedule->getFlights()[0], flightSchedule->getFlights()[2]);
	}
	if (flightSchedule->getFlights()[1].getLaunchHour() > flightSchedule->getFlights()[2].getLaunchHour()|| (flightSchedule->getFlights()[1].getLaunchHour() == flightSchedule->getFlights()[2].getLaunchHour()&&flightSchedule->getFlights()[1].getLaunchMin() > flightSchedule->getFlights()[2].getLaunchMin())){
		swap(flightSchedule->getFlights()[1], flightSchedule->getFlights()[2]);
	}
	if(flightSchedule->getFlights()[0].getLaunchHour() == flightSchedule->getFlights()[1].getLaunchHour() && flightSchedule->getFlights()[0].getLaunchMin() == flightSchedule->getFlights()[1].getLaunchMin()){
			flightSchedule->getFlights()[2].setState("Delayed");
	}

	cout<<"Launch Order"<<endl;	
	cout<<flightSchedule->getFlights()[0].getFlightName()<<" Launch at "<<flightSchedule->getFlights()[0].getLaunchHour()<<" : "<<flightSchedule->getFlights()[0].getLaunchMin()<<"  Flight State: "<<flightSchedule->getFlights()[0].getState()<<endl;
	cout<<flightSchedule->getFlights()[1].getFlightName()<<" Launch at "<<flightSchedule->getFlights()[1].getLaunchHour()<<" : "<<flightSchedule->getFlights()[1].getLaunchMin()<<"  Flight State: "<<flightSchedule->getFlights()[1].getState()<<endl;
	cout<<flightSchedule->getFlights()[2].getFlightName()<<" Launch at "<<flightSchedule->getFlights()[2].getLaunchHour()<<" : "<<flightSchedule->getFlights()[2].getLaunchMin()<<"  Flight State: "<<flightSchedule->getFlights()[2].getState()<<endl;
	cout<<endl;
}

//--------------------------------------

class LandingController{
	protected:
	int landHour1;
	int landHour2;
	int landMin1;
	int landMin2;
	public:
		void landingSchedule(FlightSchedule *);
};

void LandingController::landingSchedule(FlightSchedule * flightSchedule){
	
	if( flightSchedule->getFlights()[0].getLandHour() > flightSchedule->getFlights()[1].getLandHour() || (flightSchedule->getFlights()[0].getLandHour() == flightSchedule->getFlights()[1].getLandHour()&&flightSchedule->getFlights()[0].getLandMin() > flightSchedule->getFlights()[1].getLandMin()) ){
		swap(flightSchedule->getFlights()[0], flightSchedule->getFlights()[1]); 
	}
	if (flightSchedule->getFlights()[0].getLandHour() > flightSchedule->getFlights()[2].getLandHour() || (flightSchedule->getFlights()[0].getLandHour() == flightSchedule->getFlights()[2].getLandHour()&&flightSchedule->getFlights()[0].getLandMin() > flightSchedule->getFlights()[2].getLandMin())){
		swap(flightSchedule->getFlights()[0], flightSchedule->getFlights()[2]);
	}
	if (flightSchedule->getFlights()[1].getLandHour() > flightSchedule->getFlights()[2].getLandHour()|| (flightSchedule->getFlights()[1].getLandHour() == flightSchedule->getFlights()[2].getLandHour()&&flightSchedule->getFlights()[1].getLandMin() > flightSchedule->getFlights()[2].getLandMin())){
		swap(flightSchedule->getFlights()[1], flightSchedule->getFlights()[2]);
	}	

	if(flightSchedule->getFlights()[0].getLandHour() == flightSchedule->getFlights()[1].getLandHour() && flightSchedule->getFlights()[0].getLandMin() == flightSchedule->getFlights()[1].getLandMin()){
		flightSchedule->getFlights()[2].setState("Delayed");
	}
	cout<<"Landing Order"<<endl;
	cout<<flightSchedule->getFlights()[0].getFlightName()<<" Landing at "<<flightSchedule->getFlights()[0].getLandHour()<<" : "<<flightSchedule->getFlights()[0].getLandMin()<<" Flight State: "<<flightSchedule->getFlights()[0].getState()<<endl;
	cout<<flightSchedule->getFlights()[1].getFlightName()<<" Landing at "<<flightSchedule->getFlights()[1].getLandHour()<<" : "<<flightSchedule->getFlights()[1].getLandMin()<<" Flight State: "<<flightSchedule->getFlights()[1].getState()<<endl;
	cout<<flightSchedule->getFlights()[2].getFlightName()<<" Landing at "<<flightSchedule->getFlights()[2].getLandHour()<<" : "<<flightSchedule->getFlights()[2].getLandMin()<<" Flight State: "<<flightSchedule->getFlights()[2].getState()<<endl;;
	

}
	
//------------------------------------------

class FlightController : public LaunchController , public LandingController{
	private:
		FlightSchedule * flights;
	public:
		FlightController(FlightSchedule * flightSchedule){
			flights = flightSchedule;
		};
		FlightSchedule * getFlightSchedule();
};

FlightSchedule * FlightController::getFlightSchedule(){
	return flights;
}

//-------------------------------------------

int main(){
	string nameOfflight;
	int hour,minute,duration;
	FlightSchedule schedule = FlightSchedule();
	for(int i=0 ; i<3 ;i++){
		cout<<"Enter the name of the flight: ";
		cin>>nameOfflight;
		cout<<"Enter the departure time of the plane: ";
		cin>>hour>>minute;
		cout<<"Enter the duration of the flight in minutes: ";
		cin>>duration;
		Flight flight = Flight(nameOfflight,hour,minute,duration); 
		cout<<endl;
		schedule.addFlightToSchedule(flight);
	}
	FlightController controller = FlightController(&schedule);
	controller.launchSchedule(controller.getFlightSchedule());
	controller.landingSchedule(controller.getFlightSchedule());
}
	
