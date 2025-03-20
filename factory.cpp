#include "factory.hpp"

ShapesFactory::CallBackMap ShapesFactory::mShapes;

void ShapesFactory::RegisterShape(FeatureType type, CreateCallback cb) 
{
    mShapes[type] = cb;
}

void ShapesFactory::UnregisterShape(FeatureType type) 
{
    mShapes.erase(type);
}

std::shared_ptr<IShape> ShapesFactory::CreateShape(FeatureType type)
{
    CallBackMap::iterator it = mShapes.find(type);
    
    if (it != mShapes.end())
    {
        return (it->second)();
    }

    return nullptr;
}