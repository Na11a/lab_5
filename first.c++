#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <algorithm>

using namespace std;


enum type_of_planet{
        
    TERRESTRIAL, 
    JOVIAN
}type;

class Planet;

void findDistanceBetween(Planet &first, Planet &second);

class Planet {
    friend void findDistanceBetween();
    protected:
        string name;
        int kg;
        int length_of_day;
        int distance_from_sun;
        int type;
        
    public:
       
        Planet()
        {
            cout<<"Give me your info about planet"<<endl;
            this->set_name();
            this->set_kg();
            this->set_len_of_day();
            this->set_distance_from_sun();
            
        }
        
        void set_name(){
            cout << "Set name of planet"<<endl;
            cin>>this->name;
        }
        void set_kg(){
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
        int get_kg(){
          return this->kg;
        }
        string get_name(){
            return this->name;
        }
        int get_length_of_day(){
            return this->length_of_day;
        }
        int get_distance_from_sun(){
            return this->distance_from_sun;
        }
 
};



class Planetary : Planet{
    friend void findDistanceBetween();
    private:
        int count;
        vector<Planet> planets;
        vector<int> distances;
        vector<int> length_of_days;
    public:
        
    Planetary(int m){
        this->count = m;
        planets.reserve(m);
        length_of_days.reserve(m);
    }
  
        void addPlanet(Planet &planet)
        {
            planets.push_back(planet);
        }
        
        void sorted_by_length_of_days(){
          
            for(int i = 0;i<count;i++)
               length_of_days.push_back(this->planets[i].get_length_of_day());
            
            
            sort (length_of_days.begin(), length_of_days.end());
            for(int i=0; i<count; i++)
                cout<<length_of_days[i]<<" " <<endl;
            length_of_days.clear();
        }
        void findDistanceBetween(){
            string name1;
            string name2;
            int distance;
            cout<< "Give me first planet(name)";
            cin >> name1;
            cout<< "Give me second planet(name)";
            cin >> name2;
            for(int i = 0;i<planets.size();i++)
            {
                if (planets[i].get_name() == name1){
                    distances.push_back(planets[i].get_distance_from_sun());
                }
                if(planets[i].get_name() == name2){
                    distances.push_back(planets[i].get_distance_from_sun());
                }
            }
            
            distance = abs(distances[0] - distances[1]);
            cout<<"distance = "<<distance<<endl;
}
};





int main()
{  
    int n;
    string answer;
    cout <<"How many planets you want?"<<endl;
    cin >>n;
    
    
    Planetary planets = Planetary(n);
     
    for(int i = 1;i<=n;i++){
        Planet new_planet = Planet();
        planets.addPlanet(new_planet);    
    }
    
    
    planets.sorted_by_length_of_days();
    cout<<"Do you want to find distance between planets(yes/no)";
    cin>>answer;
    if (answer == "yes"){
        cout<<"give planets"<<endl;
        planets.findDistanceBetween();
    }
    return 0;
    
}
