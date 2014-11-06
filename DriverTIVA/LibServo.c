/*
 * LibServo.c
 *
 *  Created on: 20/10/2014
 *      Author: User
 */


#include "LibServo.h"
#include <stdbool.h>
#include "math.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/rom.h"
#include "Funciones.h"
#include "Configuration.h"



void WriteServo(int8_t servo,int16_t ang){
	if(ang <=180 && ang >=0){

		switch(servo){
#ifdef USEGENPWM0

#ifdef USEOUTPWM0
	    			case PWM0:{
	    				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, false);
	    				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, map(Min[0],Max[0],0,180,ang));
	    				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
	    				break;
	    		    }
#endif
#ifdef USEOUTPWM1
	    		    case PWM1:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, map(Min[1],Max[1],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
	    				break;
	    		    }
#endif
#ifdef USEOUTPWM2
	    		    case PWM2:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, map(Min[2],Max[2],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
	    				break;

	    		    }
#endif
#ifdef USEOUTPWM3
	    		    case PWM3:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, map(Min[3],Max[3],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, true);
	    				break;

	    		    }
#endif
#ifdef USEOUTPWM4
	    		    case PWM4:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, map(Min[4],Max[4],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM5
	    		    case PWM5:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, map(Min[5],Max[5],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM6
	    		    case PWM6:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, map(Min[6],Max[6],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM7
	    		    case PWM7:{
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7, map(Min[7],Max[7],0,180,ang));
	    		    	ROM_PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true);
	    		    	break;
	    		    }
#endif

#endif
#ifdef USEGENPWM1

#ifdef USEOUTPWM8
	    		    case PWM8:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, map(Min[8],Max[8],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
	    		    	break;

	    		    }
#endif
#ifdef USEOUTPWM9
	    		    case PWM9:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, map(Min[9],Max[9],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM10
	    		    case PWM10:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, map(Min[10],Max[10],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM11
	    		    case PWM11:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, map(Min[11],Max[11],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM12
	    		    case PWM12:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4, map(Min[12],Max[12],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM13
	    		    case PWM13:{
	    				PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, false);
	    				PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, map(Min[13],Max[13],0,180,ang));
	    				PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM14
	    		    case PWM14:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, map(Min[14],Max[14],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
	    		    	break;
	    		    }
#endif
#ifdef USEOUTPWM15
	    		    case PWM15:{
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, false);
	    		    	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, map(Min[15],Max[15],0,180,ang));
	    		    	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, true);
	    		    	break;
	    		    }
#endif

#endif
	    		     default:
	    		    	break;

	    	 }

	}
}




uint32_t GetAngServo(int8_t servo){
		switch(servo){
#ifdef USEGENPWM0

#ifdef USEOUTPWM0
		    	case PWM0:{
		    		return mapinv(0,180,Min[15],Max[15],(ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_0)) );
				}
#endif
#ifdef USEOUTPWM1
				case PWM1:{
					return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_1));
				}
#endif
#ifdef USEOUTPWM2
				case PWM2:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_2));
				}
#endif
#ifdef USEOUTPWM3
				case PWM3:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_3));
				}
#endif
#ifdef USEOUTPWM4
				case PWM4:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_4));
				}
#endif
#ifdef USEOUTPWM5
				case PWM5:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_5));
				}
#endif
#ifdef USEOUTPWM6
				case PWM6:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_6));
				}
#endif
#ifdef USEOUTPWM7
				case PWM7:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_7));
				}
#endif
#endif
#ifdef USEGENPWM1

#ifdef USEOUTPWM8
				case PWM8:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_0));
				}
#endif
#ifdef USEOUTPWM9
				case PWM9:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_1));
				}
#endif
#ifdef USEOUTPWM10
				case PWM10:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_2));
				}
#endif
#ifdef USEOUTPWM11
				case PWM11:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_3));
				}
#endif
#ifdef USEOUTPWM12
				case PWM12:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_4));
				}
#endif
#ifdef USEOUTPWM13
				case PWM13:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_5));
				}
#endif
#ifdef USEOUTPWM14
				case PWM14:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_6));
				}
#endif
#ifdef USEOUTPWM15
				case PWM15:{
			    	return mapinv(0,180,Min[15],Max[15],ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_7));
				}
#endif

#endif
				 default:
					break;

		    	 }
return 0;
}



void WriteServoInc(int8_t servo, int16_t inc){

	uint32_t temp = GetAngServo(servo);
	WriteServo(servo, temp+inc);


}




