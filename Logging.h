/** 
	Logging.h
	Copyright (c) Philippe Chataigner 2016

**/
#ifndef LOGGING_H
#define LOGGING_H
#include <inttypes.h>
#include <stdarg.h>
#include <Wire.h>
#include <Time.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#define LOG_LEVEL_FATAL 0 
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_DEBUG 4
const String LOG_LEVEL[] = { "FATAL", "ERROR", "WARN", "INFO" , "DEBUG" };

class Logging 
{
private:
	File lFichierLog;
public:
    /*! 
	 * default Constructor
	 */
    Logging(){} ;

	void Init();
	void Fatal(String msg);
	void Error(String msg);
	void Warn(String msg);

	void Info(String msg);
	void Debug(String msg);
private:
    void print(String niveau, String msg);
    String printDigits(int digits);
};   


extern Logging Log;
#endif