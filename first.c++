/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <algorithm>

using namespace std;


enum Type{
        
    TERRESTRIAL, 
    JOVIAN
}type;


int comp1(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

class Planet;

void findDistanceBetween(Planet &first, Planet &second);



class Planet {
    friend void findDistanceBetween();
    private:
        
        
    public:
        string name;
        int kg;
        int length_of_day;
        int distance_from_sun;
        int type;
    
        Planet()
        {
            cout<<"Give me your info about planet"<<endl;
            this->set_name();
            this->setkg();
            this->set_len_of_day();
            this->set_distance_from_sun();
            
        }
        
        void set_name(){
            cout << "Set name of planet"<<endl;
            cin>>this->name;
        }
        void setkg(){
            cout<<"Set kg"<<endl;
            cin >> this->kg;
        }
        
        void set_len_of_day(){
            cout<< "Set length of day"<<endl;
            cin >> this->length_of_day;
        }
        void set_distance_from_sun(){
            cout<< "Set distance from sun"<<endl;
            cin>>this->distance_from_sun;
        }
        void get_kg(){
          cout << this->kg <<endl;
        }
        void get_name(){
            cout << this->name <<endl;
        }
 
};



class Planetary{
    friend void findDistanceBetween();
    private:
        int count;
    public:
        int k = 0;
        vector<Planet> planets;
        vector<int> days;
    Planetary(int m){
        this->count = m;
        planets.reserve(m);
        days.reserve(m);
    }
  
        void addPlanet(Planet &planet)
        {
            planets.push_back(planet);
        }
        
        void sorted_by_day(){
          
            for(int i = 0;i<count;i++)
               days.push_back(this->planets[i].distance_from_sun);
            
            
              sort (days.begin(), days.end());
            for(int i=0; i<count; i++)
                cout<<days[i]<<" " <<endl;
            days.clear();
        }
        void findDistanceBetween()
        {
            string name1;
            string name2;
            cout<< "Give me first planet(name)";
            cin >> name1;
            cout<< "Give me second planet(name)";
            cin >> name2;
            for(int i = 0;i<planets.size();i++)
            {
                if (planets[i].name == name1){
                    days.push_back(planets[i].distance_from_sun);
                }
                if(planets[i].name == name2){
                    days.push_back(planets[i].distance_from_sun);
                }
            }
            int distance;
            distance = abs(days[0] - days[1]);
            cout<<"distance = "<<distance<<endl;
        }
         void findAvarageMass(){
            int sum = 0;
            for(int i =0;i<planets.size();i++){
                sum = planets[i].kg + sum;
            }
            double avarage = sum/planets.size();
            cout << "Avarage mass = " << avarage <<endl; 
        }
        

};





int main()
{  
    int n;
    cout <<"How many planets you want?"<<endl;
    cin >>n;
    Planetary planets = Planetary(n);
    for(int i = 1;i<=n;i++){
        Planet planet = Planet();
        planets.addPlanet(planet);    
    }
    
    string answer;
    planets.sorted_by_day();
    cout<<"Do you want to find distance between planets(yes/no)";
    cin>>answer;
    if (answer == "yes"){
        cout<<"give planets"<<endl;
        planets.findDistanceBetween();
    }
    cout<<"Do you want to find Avarage mass?(yes/no)";
    cin>>answer;
    if (answer == "yes"){
        planets.findAvarageMass();
    }
    return 0;
    
}
