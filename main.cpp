#include <memory>

#include "reader.hpp"
#include "shape.hpp"
#include "factory.hpp"

using std::unique_ptr;

class Feature
{
    map<FeatureType, std::shared_ptr<IShape>> mShapesCollection;

    unique_ptr<IReader> mReader;    
    Data mData;

public:
    Feature(const string& name)
    {
        mReader = std::make_unique<FileReader>(name);

        mShapesCollection[FeatureType::eCircle] = ShapesFactory::CreateShape(FeatureType::eCircle);        
        mShapesCollection[FeatureType::eTriangle] = ShapesFactory::CreateShape(FeatureType::eTriangle);
        mShapesCollection[FeatureType::eSquare] = ShapesFactory::CreateShape(FeatureType::eSquare);
    }

    void read()
    {
        if (!mReader->read(mData))
        {
            cerr << "Error open file!" << "!\n";
            return;
        }
    }
    
    void draw()
    {
        auto it = mShapesCollection.find(mData.type);

        if (it != mShapesCollection.end())
        {
            it->second->draw(mData.points);
        }
        else
            cerr << "Unknown figure!\n";
    }
};


int main()
{
    ShapesFactory::RegisterShape(FeatureType::eCircle, Circle::create);
    ShapesFactory::RegisterShape(FeatureType::eTriangle, Triangle::create);
    ShapesFactory::RegisterShape(FeatureType::eSquare, Square::create);

    Feature feature("points.txt");

    feature.read();
    feature.draw();

    return 0;
}