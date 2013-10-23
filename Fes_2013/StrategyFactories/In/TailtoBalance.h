#ifndef _Tailtobalance_
#define _Tailtobalance_

#include "../../StrategyFactories/StrategyFactories_inculude.h"

Section tailtobalance;
RunningMethod before;
RunningMethod tailtobalance1Method;
RunningMethod tailtobalance2Method;

RunningMethod tailtobalance_method_array[3];

extern void tailtobalance_init();

#endif