#include <level.h>

Level::Level() {} 

Level::~Level() {}

int Level::getId() const {
    return id;
}

void Level::setId(int id) {
    this->id = id;
}

std::string Level::getName() const {
    return name;
}

void Level::setName(const std::string& name) {
    this->name = name;
}

std::string Level::getPrompt() const {
    return prompt;
}

void Level::setPrompt(const std::string& prompt) {
    this->prompt = prompt;
}