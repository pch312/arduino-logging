	Logging.c
	Copyright (c) Philippe Chataigner 2016
	Contact philippe@chataigner.com
	
	Cette librairie enregistre des logs sur la carte SD et les afficahge sur la sortie Serial.
	Les fichiers sont cr��s dans le dossier LOG � la racine de la carte SD avec la date du jour comme nom : jjmmaaaa.CSV .
	
	Format du fichier :
	[NIVEAU];jj/mm/aaaa hh:mm:ss;message

	les diff�rents niveaux sont :
		DEBUG,
		INFO,
		WARN,
		ERROR,
		FATAL
	
	Pour fonctionner cette librairie a besoin du hardware suivant : une horloge RTC et un lecteur de carte SD.
	
	les librairies n�c�ssaires sont : 
		Wire.h
		SPI.h
		SD.h
		Time.h
		RTClib.h
	
	Test� sur une carte MEGA, une carte r�seau/SD et un  RTC DS1307
	
	N'h�sitez pas � me contacter pour des suggestions d'am�lioration ou de correction.
	
	Ce programme est un logiciel libre ; 
	vous pouvez le redistribuer et/ou le modifier au titre des clauses de la Licence Publique G�n�rale GNU, 
	telle que publi�e par la Free Software Foundation ; 
	soit la version 2 de la Licence, ou (� votre discr�tion) une version ult�rieure quelconque. 
	Ce programme est distribu� dans l'espoir qu'il sera utile, mais SANS AUCUNE GARANTIE ; 
	sans m�me une garantie implicite de COMMERCIABILITE ou DE CONFORMITE A UNE UTILISATION PARTICULIERE. 
	Voir la Licence Publique G�n�rale GNU pour plus de d�tails. 
	Vous devriez avoir re�u un exemplaire de la Licence Publique G�n�rale GNU avec ce programme ; 
	si ce n'est pas le cas, �crivez � la Free Software Foundation Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
	
	Version 1.0	- Version initiale