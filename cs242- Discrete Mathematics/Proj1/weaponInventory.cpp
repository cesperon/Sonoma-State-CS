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
uint8_t toggleWeapon(uint8_t currentWeapon, Weapon weapon);
uint8_t removeWeapon(uint8_t currentWeapon, Weapon weapon);
uint8_t addWeapon(uint8_t currentWeapon, Weapon weapon);

int main()
{
  
  srand(time(0));

  //Randomly initializes the value of myweapon to lie between 0
  // and maxWeapons.
  int myWeapon=(rand()%maxWeapons);
  
  cout<<"\n""Starting with myweapon = "<<myWeapon<<endl;

  // Converts myWeapon into binary format..
  std::string myWeaponBin=std::bitset<8>(myWeapon).to_string();

  // Displays binary format of myWeapon.
  cout<<"Binary representation: "<<myWeaponBin<<"\n";

  // Calls the displayWeapon function to print out the weapons
  // currently in the inventory as represented by myweapon.
  displayWeapon(myWeapon);

  // Display message that the Weapon Poison will be toggled.
  cout<<"***Toggling Poison***"<<endl;

  // Toggle Weapon Poison.
  myWeapon =toggleWeapon(myWeapon, Weapon::Poison);

  // Display message that the Weapon Fire will be toggled.
  cout<<"***Toggling Fire***"<<endl;

  // Toggle Weapon Fire.
  myWeapon =toggleWeapon(myWeapon, Weapon::Fire);

  // Create a variable called removedWeapon.
  uint8_t removedWeapon = removeWeapon(myWeapon, Weapon::Ice);

  // Check to see if ice is in inventory if not print out a message stating
  // ice not found if it is in inventory remove it from current inventory.
  if(myWeapon==removedWeapon)
    {
      cout<<"***Ice not found.. can't remove it***\n";
    }
  if(myWeapon != removedWeapon)
    {
      myWeapon = removedWeapon;

      cout<<"***Found Ice.. removing it***\n";
      displayWeapon(myWeapon);
    
    }

  // Create a variable called addedWeapon.
  uint8_t addedWeapon = addWeapon(myWeapon, Weapon::Melee);

  // Check to see if melee exists in inventory if so print message stating
  // melee already exists in inventory if it is not in the inventory then
  // add it to current inventory.
  if(myWeapon == addedWeapon)
    {
      cout<<"***Melee already exists.. can't add it***\n";
    }
  else if(myWeapon != addedWeapon)
    {
      cout<<"***Melee not found.. adding it***\n";
      myWeapon = addedWeapon;
      displayWeapon(myWeapon);
    }

  // Print out integr value of myWeapon.
  cout<< "Ending with myweapon = "<<myWeapon<<"\n";

  // convert myWeapon into binary format.
  std::string myWeaponBin2=std::bitset<8>(myWeapon).to_string();

  // Displays binary format of myWeapon.
  cout<<"Binary representation: "<<myWeaponBin2<<"\n";

 

  
  
  return 0;
}
  
// Function Implementations

// Checks if weapon is part of currentWeapon or not.
bool checkWeapon(uint8_t currentWeapon, Weapon weapon)
{
  static_cast<int>(weapon);

  uint8_t IsWeapon = currentWeapon & uint(weapon);

  if(IsWeapon != 0)
    {
      return true;
    }
  else if(IsWeapon == 0)
    {
      return false;
    }
  
}

// Adds weapon to current weapon inventory.
uint8_t addWeapon(uint8_t currentWeapon, Weapon weapon)
{
  uint8_t addedWeapon = currentWeapon;

  if(checkWeapon(currentWeapon, weapon) == true)
    {
      addedWeapon = currentWeapon;
    }

  if(checkWeapon(currentWeapon, weapon) == false)
    {
      addedWeapon = currentWeapon ^ uint(weapon);
    }

  return addedWeapon;
}

// Remvoes weapon from current weapon inventory.
uint8_t removeWeapon(uint8_t currentWeapon, Weapon weapon)
{
  uint8_t removedWeapon = currentWeapon;

  if(checkWeapon(currentWeapon,weapon)== true)
    {
      removedWeapon = currentWeapon ^ uint(weapon);
 

    }

  if(checkWeapon(currentWeapon, weapon) == false)
    {
       removedWeapon = currentWeapon;
    }

  return removedWeapon;
  
}

// Turns weapon off if it is currently on and turns if on if weapon
// currently on.
uint8_t toggleWeapon(uint8_t currentWeapon, Weapon weapon)
{
  uint8_t toggledWeapon= currentWeapon ^ uint(weapon);
 
  displayWeapon(toggledWeapon);
  
  return toggledWeapon;
  
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
  

