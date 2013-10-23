#include "CommonInitializeInterface.h"
#include "../../Factory.h"


//InCourse
#include "../In/StartUpFactory.h"
#include "../In/BalanceStopFactory.h"
#include "../In/LookUpGate.h"
#include "../In/LookUpGate2.h"
#include "../In/LookUpGate3.h"
#include "../In/LookUpGate4.h"
#include "../In/LookUpGate5.h"
#include "../In/GarageIn.h"
#include "../In/Stop.h"
#include "../In/Balancing.h"
#include "../In/TailtoBalance.h"


void strategies_init(){

	start_up__factory_init();
	
	look_up_factory_init();
	look_up2_factory_init();
	look_up3_factory_init();
	look_up4_factory_init();
	look_up5_factory_init();
	garage_factory_init();
	balance_stop_factory_init();
	stop_factory_init();
	balancing_init();
	tailtobalance_init();

	startSection = &startUp;
}

