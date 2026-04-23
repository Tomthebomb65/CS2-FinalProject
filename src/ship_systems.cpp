#include "ship_systems.h"
#include <cstring>

// ============================================================================
// SHIP SYSTEMS IMPLEMENTATION
// ============================================================================

//Default Constructor
System::System() {
    id = 0;
    strncpy(name, "", 50);
    strncpy(status, "", 20);
}
//Parameterized Constructor
System::System(int id, const char* name, const char* status) {
    this->id = id;
    strncpy(this->name, name, 50);
    strncpy(this->status, status, 20);
}

//Destructor
System::~System() {}

//Getters
int System::getId() const {
    return id;
}
char* System::getName() const {
    return (char*)name;
}
char* System::getStatus() const {
    return (char*)status;
}

//Setters
void System::setId(int id) {
    this->id = id;
}
void System::setName(const char* name) {
    strncpy(this->name, name, 50);
}
void System::setStatus(const char* status) {
    strncpy(this->status, status, 20);
}

// ============================================================================
// LIFE SUPPORT IMPLEMENTATION
// ============================================================================

//Default Constructor
LifeSupport::LifeSupport() : System() {
    oxygenLevel = 0.0;
    temperature = 0.0;
    cabinPressure = 0.0;
    strncpy(co2Scrubbing, "", 20);
}
//Parameterized Constructor
LifeSupport::LifeSupport(int id, const char* name, const char* status,
double oxygenLevel, double temperature, double cabinPressure,
const char* co2Scrubbing) : System(id, name, status) {
    this->oxygenLevel = oxygenLevel;
    this->temperature = temperature;
    this->cabinPressure = cabinPressure;
    strncpy(this->co2Scrubbing, co2Scrubbing, 20);
}

//Destructor
LifeSupport::~LifeSupport() {}

//Getters
double LifeSupport::getOxygenLevel() const {
    return oxygenLevel;
}
double LifeSupport::getTemperature() const {
    return temperature;
}
double LifeSupport::getCabinPressure() const {
    return cabinPressure;
}
char* LifeSupport::getCo2Scrubbing() const {
    return (char*)co2Scrubbing;
}

//Setters
void LifeSupport::setOxygenLevel(double oxygenLevel) {
    this->oxygenLevel = oxygenLevel;
}
void LifeSupport::setTemperature(double temperature) {
    this->temperature = temperature;
}
void LifeSupport::setCabinPressure(double cabinPressure) {
    this->cabinPressure = cabinPressure;
}
void LifeSupport::setCo2Scrubbing(const char* co2Scrubbing) {
    strncpy(this->co2Scrubbing, co2Scrubbing, 20);
}

// ============================================================================
// POWER IMPLEMENTATION
// ============================================================================

//Default Constructor
Power::Power() : System() {
    energyProduction = 0.0;
    energyStorage = 0.0;
    powerUsage = 0.0;
}
//Parameterized Constructor
Power::Power(int id, const char* name, const char* status,
double energyProduction, double energyStorage, double powerUsage)
: System(id, name, status) {
    this->energyProduction = energyProduction;
    this->energyStorage = energyStorage;
    this->powerUsage = powerUsage;
}

//Destructor
Power::~Power() {}

//Getters
double Power::getEnergyProduction() const {
    return energyProduction;
}
double Power::getEnergyStorage() const {    
    return energyStorage;
}
double Power::getPowerUsage() const {
    return powerUsage;
}

//Setters
void Power::setEnergyProduction(double energyProduction) {
    this->energyProduction = energyProduction;
}
void Power::setEnergyStorage(double energyStorage) {
    this->energyStorage = energyStorage;
}
void Power::setPowerUsage(double powerUsage) {
    this->powerUsage = powerUsage;
}