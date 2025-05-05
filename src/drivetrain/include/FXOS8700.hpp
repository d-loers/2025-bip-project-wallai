#include "IMagnometer.hpp"
#include "IAccelerometer.hpp"

class FXOS8700 : public IMagnometer, public IAccelerometer{
private:
public:
    FXOS8700();
    ~FXOS8700();
};
