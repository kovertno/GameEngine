#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <algorithm>

const unsigned int MAX_COMPONENTS = 32;

////////////////////////////////////////////////////////////////////
// Signature
////////////////////////////////////////////////////////////////////
// We use bitset (1s and 0s) to keep track of which components an entity has,
// and also helps keep track of which entities a given system is interested in.
////////////////////////////////////////////////////////////////////
typedef std::bitset<MAX_COMPONENTS> Signature;

struct IComponent { //IComponent, because I stands for interaface
protected:
    static int nextId;
};

// Used to assign unique ID to a component type
template <typename T>
class Component: public IComponent {
    // Returns the unique ID of Component<T>
    static int getId() {
        static auto id = nextId++;
        return id;
    };
};

class Entity {
private:
    int id;

public:
    explicit Entity(int id) : id(id) {};

    int getId() const;
};

////////////////////////////////////////////////////////////////////
// System
////////////////////////////////////////////////////////////////////
// The system processes entities that contain a specific signature.
////////////////////////////////////////////////////////////////////
class System {
private:
    Signature componentSignature;
    std::vector<Entity> entities;

public:
    System() = default;
    virtual ~System() = default;
    void addEntityToSystem(Entity entity);
    void removeEntityFromSystem(Entity entity);
    const Signature& getComponentSignature() const;
    const std::vector<Entity>& getEntities() const;

    //Defines the component type that entities must have to be considered by the system.
    template <typename TComponent> void requireComponent();
};

class Registry {

};

template <typename TComponent>
void System::requireComponent() {
    const auto componentId = Component<TComponent>::getId();
    componentSignature.set(componentId);
}

#endif