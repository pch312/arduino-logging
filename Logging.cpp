/**
	Logging.c
	Copyright (c) Philippe Chataigner 2016
	Contact philippe@chataigner.com
	
	Cette librairie enregistre des logs sur la carte SD et les afficahge sur la sortie Serial.
	Les fichiers sont créés dans le dossier LOG à la racine de la carte SD avec la date du jour comme nom : jjmmaaaa.CSV .
	
	Format du fichier :
	[NIVEAU];jj/mm/aaaa hh:mm:ss;message

	les différents niveaux sont :
		DEBUG,
		INFO,
		WARN,
		ERROR,
		FATAL
	
	Pour fonctionner cette librairie a besoin du hardware suivant : une horloge RTC et un lecteur de carte SD.
	
	les librairies nécéssaires sont : 
		Wire.h
		SPI.h
		SD.h
		Time.h
		RTClib.h
	
	Testé sur une carte MEGA, une carte réseau/SD et un  RTC DS1307
	
	N'hésitez pas à me contacter pour des suggestions d'amélioration ou de correction.
	
	Ce programme est un logiciel libre ; 
	vous pouvez le redistribuer et/ou le modifier au titre des clauses de la Licence Publique Générale GNU, 
	telle que publiée par la Free Software Foundation ; 
	soit la version 2 de la Licence, ou (à votre discrétion) une version ultérieure quelconque. 
	Ce programme est distribué dans l'espoir qu'il sera utile, mais SANS AUCUNE GARANTIE ; 
	sans même une garantie implicite de COMMERCIABILITE ou DE CONFORMITE A UNE UTILISATION PARTICULIERE. 
	Voir la Licence Publique Générale GNU pour plus de détails. 
	Vous devriez avoir reçu un exemplaire de la Licence Publique Générale GNU avec ce programme ; 
	si ce n'est pas le cas, écrivez à la Free Software Foundation Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
	
	Version 1.0	- Version initiale
	
**/



#include "Logging.h"

RTC_DS1307 RTC1307;

/**
	Init : Initialisation de la librairie
	**/
void Logging::Init()
{
	Wire.begin();
	RTC1307.begin();
	if (!SD.begin(4)) 
	{
		Serial.println(F("Init Carte SD failed"));
	}
}

/**
	Fatal : Ecrit dans le log un message de type fatal
**/
void Logging::Fatal(String msg)
{
	print(LOG_LEVEL[LOG_LEVEL_FATAL],msg);
}

/**
	Error : Ecrit dans le log un message de type erreur
**/
void Logging::Error(String msg)
{
	print(LOG_LEVEL[LOG_LEVEL_ERROR],msg);
}

/**
	Warn : Ecrit dans le log un message de type attention
**/
void Logging::Warn(String msg)
{
	print(LOG_LEVEL[LOG_LEVEL_WARN],msg);
}

/**
	Info : Ecrit dans le log un message de type information
**/
void Logging::Info(String msg)
{
	print(LOG_LEVEL[LOG_LEVEL_INFO],msg);
}

/**
	Debug : Ecrit dans le log un message de type debogage
**/
void Logging::Debug(String msg)
{
	print(LOG_LEVEL[LOG_LEVEL_DEBUG],msg);
}

/**
	print : fonction privée ecrit dans le log un message avec le niveau.
**/
void Logging::print(String niveau, String msg) 
{
	DateTime lNow = RTC1307.now();
	String lMessage="["+niveau+"];"+printDigits(lNow.day())+"/"+printDigits(lNow.month())+"/"+String(lNow.year())+" "+printDigits(lNow.hour())+":"+printDigits(lNow.minute())+":"+printDigits(lNow.second())+";"+msg;
	if (!SD.exists("log"))
	{
		Serial.println(F("Création dossier"));
		if (!SD.mkdir("log"))
			Serial.println(F("Erreur Création dossier"));
		else
			Serial.println(F("Création dossier OK"));
			
	}
	String lNomFichier = "log/"+printDigits(lNow.day())+printDigits(lNow.month())+String(lNow.year())+".csv";
	lFichierLog = SD.open(lNomFichier,FILE_WRITE);
	if (lFichierLog)
		lFichierLog.println(lMessage);
	else
		Serial.println(F("Erreur ouverture fichier"));
	Serial.println(lMessage);
	lFichierLog.close();
 }
 
/**
	printdigits : fonction privée, rajoute un zero devant le jour et loe mois si inférieur à 10
**/
String Logging::printDigits(int digits)
{
	String retour = "";
	if (digits < 10)
		retour = "0";
	retour += String(digits,DEC)+"";
	return retour;
}

 Logging Log = Logging();