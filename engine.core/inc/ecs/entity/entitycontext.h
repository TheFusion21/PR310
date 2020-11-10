#pragma once

#include "../component/componentarray.h"
#include "entity.h"
#include "singleton.h"

#include <unordered_map>
#include <queue>
#include <array>


class EntityContext
{
    DECLARE_SINGLETON(EntityContext);

public:

    Entity CreateEntity(void)
    {
        auto Ent = NumEntities++;
        this->Entities.insert({ Ent, Signature() });
        return Ent;
    }
    std::vector<Entity> FilteredEntities(Signature& selectedSignature)
    {
        std::vector<Entity> selectedEntities;
        for (auto& pair : this->Entities)
        {
            if ((pair.second & selectedSignature) == selectedSignature)
                selectedEntities.push_back(pair.first);
        }
        return selectedEntities;
    }
    size_t GetEntityCount(Entity ent)
    {
        return this->Entities.count(ent);
    }
    void SetSignature(Entity ent, Signature sig)
    {
        this->Entities[ent] |= sig;
    }

private:

    size_t NumEntities = 0;
    std::unordered_map<Entity, Signature> Entities;

};
