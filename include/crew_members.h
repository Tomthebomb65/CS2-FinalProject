#ifndef CREW_MEMBERS_H
#define CREW_MEMBERS_H

class CrewMember {
    private:
        int id;
        char name[50];
        char role[20];
        int heartRate;
        bool isSleeping;

    public:
        //Constructors and Destructor
        CrewMember();
        CrewMember(int id, const char* name, const char* role,
            int heartRate, bool isSleeping);
        ~CrewMember();

        //Getters
        int getId() const;
        char* getName() const;
        char* getRole() const;
        int getHeartRate() const;
        bool getIsSleeping() const;

        //Setters
        void setId(int id);
        void setName(const char* name);
        void setRole(const char* role);
        void setHeartRate(int heartRate);
        void setIsSleeping(bool isSleeping);
};
#endif