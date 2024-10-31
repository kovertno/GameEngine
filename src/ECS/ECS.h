#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <algorithm>
#include <deque>

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

    Entity& operator =(const Entity& other) = default;
    bool operator==(const Entity& other)const { return id == other.id; };
    bool operator!=(const Entity& other)const { return id != other.id; };
    bool operator<(const Entity& other)const { return id < other.id; };
    bool operator>(const Entity& other)const { return id > other.id; };
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

////////////////////////////////////////////////////////////////////
// Pool
////////////////////////////////////////////////////////////////////
// A pool is just a vector (contiguous data) of objects of type T.
////////////////////////////////////////////////////////////////////
class IPool {
public:
    virtual ~IPool() = default;
};

template <typename T>
class Pool: public IPool{
private:
    static std::vector<T> data;

public:
    Pool(int size = 100) {
        data.resize(size);
    }

    virtual ~Pool() = default;

    bool isEmpty() const{
        return data.empty();
    }

    int getSize() const {
        return data.size();
    }

    void Resize(int n) {
        data.resize(n);
    }

    void Clear() {
        data.clear();
    }

    void Add(T obj) {
        data.push_back(obj);
    }

    void Set(int indx, T obj) {
        data[indx] = obj;
    }

    T& Get(int indx) const {
        return static_cast<T&>(data[indx]);
    }

    T& operator [](int indx) {
        return data[indx];
    }
};

////////////////////////////////////////////////////////////////////
// Registry
////////////////////////////////////////////////////////////////////
// The registry manages the creation and destruction of entities, add systems, add components.
////////////////////////////////////////////////////////////////////
class Registry {
private:
    int numEntities = 0;

    //vector of component pools. each pool contain all the data of a certain component type
    //vector indx = component type id
    //pool indx = entity id
    std::vector<IPool*> componentPools;
};

template <typename TComponent>
void System::requireComponent() {
    const auto componentId = Component<TComponent>::getId();
    componentSignature.set(componentId);
}

#endif