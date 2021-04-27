//Vincent Hong
//COSC 
//April 26, 2021
//Dr. T

#include <iostream>
#include <string> 
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    string homeCity; 
    string coachName; 
  public:
      Team()
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "TeamName"; 
        homeCity = "CityName"; 
        coachName = "CoachName"; 
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void sethomeCity(string city) { homeCity = city; }
      void setCoachName(string coach) { coachName = coach; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      string getHomeCity() const { return homeCity; }
      string getCoachName() const { return coachName; }
};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int x) { half = x; }
    void setHome(Team setHome) { home = setHome; }
    void setVisitor(Team setVisitor) { visitor = setVisitor; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string reset = "\x1b[0m";
      cout << "Football Scoreboard" << reset << endl; 
      cout << home.getName() << "\t\t\t" << visitor.getName() << endl; 
      cout << home.getHomeCity() << "\t\t" << visitor.getHomeCity() << endl;
      cout << "\t"  << home.getScore() << reset << "\t\t\t\t" << visitor.getScore() << endl; 
      cout  << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << endl; 
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  tOne.setHomeStatus(true);
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  do 
  {
      system("clear");
      s.showScoreboard();
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Status" << endl; 
      cout << "D = Update Visting Team Coach" << endl; 
      cout << "E = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        cout << "Update Home Team Name" << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName;
        tOne.setName(newName);
      }
      else(userChoice == "B" || userChoice == "b")
      {
        cout << "Update Visitor Team Name" << endl; 
        cout << "\nPlease enter a new name for the visitor team: ";
        cin >> newName;
        tTwo.setName(newName);
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status" << endl; 
        cout << "\nWho is the home team: 1 = Team 1, 2=Team 2: ";
        cin >> homeTeamQuestion;
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
        }
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Visitor Coach" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else
      {
        cout << "\nInvalid input." << endl; 
      }

      s.setHome(tOne);
      s.setVisitor(tTwo);
  
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
}