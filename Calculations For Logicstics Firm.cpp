#include<iostream>
#include<string>
using namespace std;
class Transportation{
	protected:
		float weight_of_cargo;
		float distance_of_route;
		float initial_fuel;
		float fuel_consumption;
		float fuel_for_completing;
	public:
		void virtual checkAvailability()=0;
		
		friend istream & operator >>(istream &is, Transportation &x){
			cout<<"Enter the weight of the cargo: ";
			is>>x.weight_of_cargo;
			cout<<"Enter the travel distance: ";
			is>>x.distance_of_route;
			cout<<endl;
			return is;
		}
	
	
};

class Ship:public Transportation{
	public:
		Ship(){
			cout<<"A cargo ship is on hold for current transportation"<<endl;
			cout<<"Enter the amount for initial fuel: ";
			cin>>initial_fuel;
			fuel_consumption=60;
		}
		void checkAvailability(){
			float increaing_fuel_with_weight, x;
			fuel_for_completing = (distance_of_route*(fuel_consumption + weight_of_cargo*0.5))/100  ;
		    x =	fuel_for_completing - initial_fuel;
			try{
				if((initial_fuel-fuel_for_completing)>=0){
					cout<<"Sufficient amount of fuel in the ship."<<endl;
					cout<<"Transportation ship can reach to destination in single trip"<<endl;
				}
				else{
					throw x;
				}
			
			}
			catch (float x){		
 				cout<<"Transportation ship needs to refuel at the harbor"<<endl;
				cout<<"Need to refuel "<<x<<" L more."<<endl;
			}
		}
		
};

class Truck:public Transportation{
	public:
		Truck(){
			cout<<"A truck is on hold for transportation"<<endl;
			cout<<"Enter the amount for initial fuel: ";
			cin>>initial_fuel;
			fuel_consumption=30;
			
		}
		void checkAvailability(){
			float increaing_fuel_with_weight, x;
			fuel_for_completing = (distance_of_route*(fuel_consumption+weight_of_cargo*1.0))/100;
			x =	fuel_for_completing - initial_fuel;
			try{
				if((initial_fuel-fuel_for_completing)>=0){
					cout<<"Sufficient amount of fuel in truck."<<endl;
					cout<<"Transportation truck can reach to destination in single trip"<<endl;
				}
				else{
					throw x;
				}
			}
			catch(float x){
				cout<<"Transportation Truck needs to refuel at the station"<<endl;
   				cout<<"Need to refuel "<<x<<" L more."<<endl;
			}		
		}
};

int main(){
	cout<<"        Please enter required information for the transportation of goods"<<endl;
	cout<<endl;
	Ship obj1;
	cout<<endl;
	cin>>obj1;
	obj1.checkAvailability();
	cout<<endl;
	Truck obj2;
	cout<<endl;
	cin>>obj2;
	obj2.checkAvailability();

}
