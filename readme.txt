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