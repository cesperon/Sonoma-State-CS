// Christian Esperon
// Project01: Bit Manipulation
// cs242

#include <bitset>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Weapon: uint8_t
{
  None = 0,
  Melee = 1<<0,
  Fire = 1<<1,
  Ice = 1<<2,
  Poison = 1<<3,
};

// Max value that myweapon can get.
const uint8_t maxWeapons = 16;

// Prototypes
bool checkWeapon(uint8_t currentWeapon, Weapon weapon); //checks if weapon is part of currentWeapon or not.
void displayWeapon(uint8_t currentWeapon);

int main()
{
  
  srand(time(0));

  //Randomly initializes the value of myweapon to lie between 0
  // and maxWeapons
  int myWeapon=(rand()%maxWeapons);
  
  cout<<"\n""Starting with myweapon = "<<myWeapon<<endl;

  // Converts myWeapon into binary format..
  std::string myWeaponBin=std::bitset<8>(myWeapon).to_string();

  // Displays binary format of myWeapon.
  cout<<"Binary representation: "<<myWeaponBin<<"\n";

  // Calls the displayWeapon function to print out the weapons
  // currently in the inventory as represented by myweapon.
  displayWeapon(myWeapon);

  
  return 0;
}
  
// Function Implementations

// Checks if weapon is part of currentWeapon or not.
bool checkWeapon(uint8_t currentWeapon, Weapon weapon)
{
  static_cast<int>(weapon);

  int IsWeapon = currentWeapon & uint(weapon);

  if(IsWeapon != 0)
    {
      return true;
    }
  else if(IsWeapon == 0)
    {
      return false;
    }
  
}

// Prints out all the weapons in the current inventory.
void displayWeapon(uint8_t currentWeapon)
{
  cout<<"Your Weapons: ";

  if(currentWeapon == 0)
    {
      cout<<"None";
    }
  
  if(checkWeapon(currentWeapon, Weapon::Melee)== true)
    {
      cout<<"Melee ";
    }

  if(checkWeapon(currentWeapon, Weapon::Fire)== true)
    {
      cout<<"Fire ";
    }
  if(checkWeapon(currentWeapon, Weapon::Ice)== true)
    {
      cout<<"Ice ";
    }
  if(checkWeapon(currentWeapon, Weapon::Poison)== true)
    {
      cout<<"Poison";
    }

  cout<<"\n";
  
}
  

