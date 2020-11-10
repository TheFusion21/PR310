#pragma once

#include "../entity/entity.h"
#include "../entity/entitycontext.h"
#include "componentarray.h"
#include <bitset>
#include <unordered_map>
#include "singleton.h"

typedef u64 ComponentType;

class ComponentContext
{
    DECLARE_SINGLETON(ComponentContext);

public:

    template<typename T>
    void RegisterComponent()
    {
        T::ID = nextComponentType++;
        componentArrays.insert({ T::ID, new ComponentArray<T> });
    }
    template <typename T>
    T* AddComponent(Entity ent)
    {
        if (EntityContext::GetInstance().GetEntityCount(ent) <= 0) return nullptr;
        EntityContext::GetInstance().SetSignature(ent, T::ID);
        return this->GetComponent<T>(ent);
    }
    template <typename T>
    T* GetComponent(Entity ent)
    {
        return &GetComponentArray<T>()->GetData(ent);
    }
private:

    ComponentType nextComponentType;

    template<typename T>
    ComponentArray<T>* GetComponentArray()
    {
        return reinterpret_cast<ComponentArray<T>*>(componentArrays[T::ID]);
    }

    std::unordered_map<ComponentType, IComponentArray*> componentArrays;

};