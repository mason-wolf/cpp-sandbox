#include <event.h>

Event::Event() {} 

Event::~Event() {}

int Event::getId() const {
    return id;
}

void Event::setId(int id) {
    this->id = id;
}

std::string Event::getName() const {
    return name;
}

void Event::setName(const std::string& name) {
    this->name = name;
}

std::string Event::getPrompt() const {
    return prompt;
}

void Event::setPrompt(const std::string& prompt) {
    this->prompt = prompt;
}

std::vector<int> Event::getEventIds() {
    return eventIds;
}

void Event::setEventIds(const std::vector<int>& events) {
    this->eventIds = events;
}

void Event::addEvent(const Event& event) {
    this->events.push_back(event);
}

std::vector<Event> Event::getEvents() {
    return events;
}
