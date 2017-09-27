// this is just a test build

//#include <iostream>
//using namespace std;

namespace vwcn{
    
    class Quaternion {
        double x,y,z,w;
        public:
            Quaternion(double px,double py,double pz,double pw)
            {
                x = px;
                y = py;
                z = pz;
                w = pw;
            }
    };

}