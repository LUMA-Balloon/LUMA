#include "core/modules/modules.h"
#include "data.h"

class VentDrop : Module {

public:

   
    // Tells the VENT/DROP module to set DROP to a specific command
    bool setDrop(DropState dropCommand);

    // Tells the VENT/DROP module to set VENT to a specific command
    bool setVent(VentState ventCommand);

    // Sets the state in data to match what VENT/DROP says
    // Returns true if data was received from VENT/DROP, false if not
    bool getState();

};

