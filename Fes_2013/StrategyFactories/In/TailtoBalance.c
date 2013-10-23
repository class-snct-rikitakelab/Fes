#include "TailtoBalance.h"
#include "Balancing.h"

void tailtobalance_init(){
	
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop=0;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =2000;
	balancing_requrement = 0;
	target_tail_angle=90;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&before,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);


	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =250;
	//switch_term.tail_angle=130;		//119;
	balancing_requrement = 0;
	target_tail_angle=113;

	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailtobalance1Method,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//tailBackRunningMethod

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =	1000;	//200;
	//switch_term.tail_angle=0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;		
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailtobalance2Method,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	tailtobalance_method_array[0] =before;
	tailtobalance_method_array[1] =tailtobalance1Method;
	tailtobalance_method_array[2]=tailtobalance2Method;

	int number_of_running_method=3;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection = &balancing;
	Section_init(&tailtobalance,nextSection,number_of_running_method,tailtobalance_method_array,target_values);


}