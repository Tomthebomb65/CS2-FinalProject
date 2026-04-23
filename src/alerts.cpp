#include "alerts.h"
#include <cstring>

//Default Constructor
Alert::Alert () {
    id = 0;
    strcpy(message, "");
    timestamp = 0.0;
    severity = 0;
}
//Parameterized Constructor
Alert::Alert (int id, const char* message, double timestamp, int severity) {
    this->id = id;
    strncpy(this->message, message, 50);
    this->timestamp = timestamp;
    this->severity = severity;
}

//Destructor
Alert::~Alert () {}

//Getters
int Alert::getId() const {
    return id;
}
char* Alert::getMessage() const {
    return (char*)message;
}
double Alert::getTimestamp() const {
    return timestamp;
}
int Alert::getSeverity() const {
    return severity;
}

//Setters
void Alert::setId(int id) {
    this->id = id;
}
void Alert::setMessage(const char* message) {
    strncpy(this->message, message, 50);
}
void Alert::setTimestamp(double timestamp) {
    this->timestamp = timestamp;
}
void Alert::setSeverity(int severity) {
    this->severity = severity;
}