#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

enum class FeatureType { eUnknown, eCircle, eTriangle, eSquare };

class IShape
{
    public:
        IShape(int count) : poinstCount(count) {}

        virtual ~IShape() = default;
        virtual void draw(const vector<double> &points) const = 0;
        
    private:
        const int poinstCount;

    protected:
        bool isGoodSize() const 
        {
            if (size != poinstCount)          
                return false;

            return true;
        }

        const string msg = "points size don't equal "
            + std::to_string(poinstCount) + "!";

        mutable int size;
};

class Circle : public IShape
{
    public:
        Circle(int count = 3) : IShape(count) {}

        void draw(const vector<double>& points) const override
        {
            size = points.size();

            if (!isGoodSize())
            {
                cerr << msg << endl;
                return;
            }

            cout << "Draw circle!\n";
        }
        
        static std::shared_ptr<IShape> create()
        {
            return std::make_shared<Circle>();
        }
};

class Triangle : public IShape
{
    public:
        Triangle(int count = 6) : IShape(count) {}

        void draw(const vector<double>& points) const override 
        {
            size = points.size();

            if (!isGoodSize())
            {
                cerr << msg << endl;
                return;
            }    
            
            cout << "Draw triangle!\n";
        }
        
        static std::shared_ptr<IShape> create()
        {
            return std::make_shared<Triangle>();
        }
};

class Square : public IShape
{
    public:
        Square(int count = 8) : IShape(count) {}

        void draw(const vector<double>& points) const override 
        {
            size = points.size();

            if (!isGoodSize())
            {
                cerr << msg << endl;
                return;
            }
                        
            cout << "Draw square\n";
        }

        static std::shared_ptr<IShape> create()
        {
            return std::make_shared<Square>();;
        }
};

#endif // _SHAPE_H_