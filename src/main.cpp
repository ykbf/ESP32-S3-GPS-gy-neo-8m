#include <Arduino.h>
#include <ATGM336H_GPS.h>
#include <string.h>
#include <math.h>
float z;
float x;
char a[11];
char b[11];
void gps();
void setup() {
  Serial.begin(115200);
  GPS_BDS_Init();
}

void loop() {
 gps();
}


void gps(){
	 gpsRead();	//获取GPS数据
	parseGpsBuffer();//解析GPS数据

  // 判断解析是否成功
	if (Save_Data.isParseData)
	{
		Save_Data.isParseData = false;
		
    // 世界标准时间，即格林威治时间，全球根据所在时区调整。
		Serial.print("Save_Data.UTCTime = ");
		Serial.println(Save_Data.UTCTime);

		if(Save_Data.isUsefull)
		{
      // 打印经纬度信息 东西、南北半球信息
			Save_Data.isUsefull = false;
			Serial.print("Save_Data.latitude = ");     
			Serial.println(Save_Data.latitude);
				
					x=atof(Save_Data.latitude);
					
	x = x / pow(10, 2);
// x = roundf(x * 100.0f) / 100.0f;
Serial.println(x);
			Serial.print("Save_Data.N_S = ");
			Serial.println(Save_Data.N_S);
			Serial.print("Save_Data.longitude = ");
			Serial.println(Save_Data.longitude);
			z=atof(Save_Data.longitude);
			z = z / pow(10, 2);
			Serial.println(z);
			// float z = roundf(z * 100.0f) / 100.0f;
			// 	Serial.println(z);
			Serial.print("Save_Data.E_W = ");
			Serial.println(Save_Data.E_W);
			
		
			

		}
		else
		{
			Serial.println("GPS DATA is not usefull!");
		}
		
	}
}