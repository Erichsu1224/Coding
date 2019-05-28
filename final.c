/*
 \file		Final.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>

int main(void)
{
	//TODO Place here your variables

	InitEV3();
	initSensors();
	setAllSensorMode(US_DIST_MM, NO_SEN, NO_SEN, COL_COLOR);

	//TODO Place here your code
	while(1)
	{
		LcdPrintf(1, "%d   %.2f\n", readSensor(IN_4) , readSensor(IN_1) / 10.f);

		if(readSensor(IN_4) == 1)
		{
			OnFwdReg(OUT_B, 80); // 馬達 B，往前，速度 80
			OnFwdReg(OUT_A, 80); // 馬達 C，往前，速度 80

		}

		else
		{
			OnRevReg(OUT_B, 80); // 馬達 B，往後，速度 80
			OnRevReg(OUT_A, 80); // 馬達 C，往後，速度 80
			Wait(SEC_1);

			OnFwdReg(OUT_A, 80);
			OnRevReg(OUT_B, 80); // 馬達 B，往後，速度 80
			Wait(SEC_1);

		}

		if(ButtonIsDown(BTNEXIT))
			goto exit;

	}
	exit:
		FreeEV3();
		return 0;
}
