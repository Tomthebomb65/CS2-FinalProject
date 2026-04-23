#ifndef ALERTS_H
#define ALERTS_H

class Alert {
    private:
        int id;
        char message[50];
        double timestamp;
        int severity;

    public:
        //Constructors and Destructor
        Alert();
        Alert(int id, const char* message,
            double timestamp, int severity);
        ~Alert();

        //Getters
        int getId() const;
        char* getMessage() const;
        double getTimestamp() const;
        int getSeverity() const;

        //Setters
        void setId(int id);
        void setMessage(const char* message);
        void setTimestamp(double timestamp);
        void setSeverity(int severity);
};
#endif