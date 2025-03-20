#ifndef _READER_H_
#define _READER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using std::cout;
using std::cerr;
using std::endl;

using std::istream;
using std::ifstream;

#include "shape.hpp"

struct Data
{
    FeatureType type;
    vector<double> points;
};

istream& operator>>(istream& is, Data& data)
{
    int type;
    is >> type;
    data.type = static_cast<FeatureType>(type);

    double point;
    while (is >> point)
        data.points.push_back(point);

    return is;
}

class IReader
{
    public:
        virtual ~IReader() = default;
        virtual bool read(Data&) = 0;
};

class FileReader : public IReader
{
    string mName;
    ifstream mFile;

    public:
        FileReader(const string& fileName) : mName(fileName)
        {
            mFile.open(fileName);
        }

        virtual ~FileReader() 
        {
            mFile.close();
        }

        bool read(Data& data) override
        {        
            if (!mFile.is_open())                           
                return false;

            mFile >> data;
            
            return true;
        }
};

#endif // _READER_H_