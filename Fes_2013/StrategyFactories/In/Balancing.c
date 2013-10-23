#include "Balancing.h"
#include "BalanceStopFactory.h"

void balancing_init(){
	
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop=0;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	//beforelookupMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =	0;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	switch_term.distance_obstacle = 40;
	balancing_requrement = 1;
	target_tail_angle=80;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	RunningMethod_init(&balancingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,SonarSwitch_judge_switch_method,request_forced_stop,movementDirection);



	balanceing_method_array[0] = balancingMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 100;
	Section *nextSection = &balanceStop;
	Section_init(&balancing,nextSection,number_of_running_method,balanceing_method_array,target_values);


}