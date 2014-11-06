
#include <stdint.h>


#ifndef __DRIVERTIVA_LIBCONFIGADC_H_
#define __DRIVERTIVA_LIBCONFIGSADC_H_

extern void InitSensorADC(void);
extern void ConfigSensorADC(int8_t Sensor);
extern int32_t TriggerADC(int8_t Sensor );
extern float LSBToVoltage(int32_t lsb);


#endif
