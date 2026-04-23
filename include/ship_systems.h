#ifndef SHIP_SYSTEMS_H
#define SHIP_SYSTEMS_H

class System {
    private:
        int id;
        char name[50];
        char status[20];

    public:
        //Constructors and Destructor
        System();
        System(int id, const char* name, const char* status);
        virtual ~System();

        //Getters
        int getId() const;
        char* getName() const;
        char* getStatus() const;

        //Setters
        void setId(int id);
        void setName(const char* name);
        void setStatus(const char* status);
};

class LifeSupport : public System {
    private:
        double oxygenLevel;
        double temperature;
        double cabinPressure;
        char co2Scrubbing[20];

    public:
        //Constructors and Destructor
        LifeSupport();
        LifeSupport(int id, const char* name, const char* status,
            double oxygenLevel, double temperature,
            double cabinPressure, const char* co2Scrubbing);
        ~LifeSupport();

        //Getters
        double getOxygenLevel() const;
        double getTemperature() const;
        double getCabinPressure() const;
        char* getCo2Scrubbing() const;

        //Setters
        void setOxygenLevel(double oxygenLevel);
        void setTemperature(double temperature);
        void setCabinPressure(double cabinPressure);
        void setCo2Scrubbing(const char* co2Scrubbing);
};

class Power : public System {
    private:
        double energyProduction;
        double energyStorage;
        double powerUsage;

    public:
        //Constructors and Destructor
        Power();
        Power(int id, const char* name, const char* status,
            double energyProduction, double energyStorage,
            double powerUsage);
        ~Power();

        //Getters
        double getEnergyProduction() const;
        double getEnergyStorage() const;
        double getPowerUsage() const;

        //Setters
        void setEnergyProduction(double energyProduction);
        void setEnergyStorage(double energyStorage);
        void setPowerUsage(double powerUsage);
};
#endif