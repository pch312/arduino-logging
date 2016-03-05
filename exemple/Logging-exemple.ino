#include <Logging.h>

void setup() 
{
  Serial.begin(9600);
  Log.Init();
  Log.Info("Initialisation de l'application");
  // initialisation
  Log.Info("Fin initialisation de l'application");
}
void loop() 
{
   Log.Debug("Message debogage");
   delay(5678);
   Log.Info("Message information");
   delay(1642);
   Log.Warn("Message attention");
   delay(4845);
   Log.Error("Message erreur");
   delay(2365);
   Log.Fatal("Message fatal");
   delay(2475);
}
