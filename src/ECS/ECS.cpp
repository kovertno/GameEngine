#include "ECS.h"

int Entity::getId() const {
    return id;
}

void System::addEntityToSystem(Entity entity) {
    entities.push_back(entity);
}

void System::removeEntityFromSystem(Entity entity) {
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other){return entity == other;}), entities.end());
}

const Signature& System::getComponentSignature() const {
    return componentSignature;
}

const std::vector<Entity>& System::getEntities() const {
    return entities;
}