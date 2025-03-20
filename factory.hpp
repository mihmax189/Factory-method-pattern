#ifndef FACTORY_H_
#define FACTORY_H_

#include <memory>
#include <functional>
#include <map>
#include <memory>

using std::map;
using std::function;
using std::shared_ptr;

#include "shape.hpp"

class IShape;

class ShapesFactory 
{
    using CreateCallback = function<std::shared_ptr<IShape>()>;

public:
    static void RegisterShape(FeatureType type, CreateCallback cb);

    static void UnregisterShape(FeatureType type);

    static std::shared_ptr<IShape> CreateShape(FeatureType type);

private:
    using  CallBackMap = map<FeatureType, CreateCallback>;
    static CallBackMap mShapes;
};

#endif // FACTORY_H_