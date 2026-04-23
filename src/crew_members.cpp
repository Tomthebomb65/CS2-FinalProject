#include "crew_members.h"
#include <cstring>

//Default Constructor
CrewMember::CrewMember() {
    id = 0;
    strncpy(name, "", 50);
    strncpy(role, "", 20);
    heartRate = 0;
    isSleeping = false;
}
//Parameterized Constructor
CrewMember::CrewMember(int id, const char* name, const char* role,
int heartRate, bool isSleeping) {
    this->id = id;
    strncpy(this->name, name, 50);
    strncpy(this->role, role, 20);
    this->heartRate = heartRate;
    this->isSleeping = isSleeping;
}

//Destructor
CrewMember::~CrewMember() {}

//Getters
int CrewMember::getId() const {
    return id;
}
char* CrewMember::getName() const {
    return (char*)name;
}
char* CrewMember::getRole() const {
    return (char*)role;
}
int CrewMember::getHeartRate() const {
    return heartRate;
}
bool CrewMember::getIsSleeping() const {
    return isSleeping;
}

//Setters
void CrewMember::setId(int id) {
    this->id = id;
}
void CrewMember::setName(const char* name) {
    strncpy(this->name, name, 50);
}
void CrewMember::setRole(const char* role) {
    strncpy(this->role, role, 20);
}
void CrewMember::setHeartRate(int heartRate) {
    this->heartRate = heartRate;
}
void CrewMember::setIsSleeping(bool isSleeping) {
    this->isSleeping = isSleeping;
}