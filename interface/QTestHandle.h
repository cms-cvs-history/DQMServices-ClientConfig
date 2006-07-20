#ifndef QTestHandle_H
#define QTestHandle_H

/** \class QTestHandle
 * *
 *  Handles quality tests (configuring, attaching to ME's, 
 *  subscribing to the ME's for which quality tests are requested).
 *
 *  $Date: 2006/05/22 10:20:33 $
 *  $Revision: 1.2 $
 *  \author Ilaria Segoni
  */
  
#include<string>
#include<vector>
#include<map>

class MonitorUserInterface;
class QTestConfigurationParser;
class QTestConfigure;
class QTestStatusChecker;

class QTestHandle{
  public:
	///Creator
	QTestHandle();
	///Destructor
	~QTestHandle();
	///Parses Config File and configures the quality tests
	bool configureTests(std::string configFile, MonitorUserInterface * mui);
	///Attaches the quality tests to the MonitorElement
	void attachTests(MonitorUserInterface * mui);
	///Checks global status of Quality Tests
	std::pair<std::string,std::string> checkGolbalQTStatus(MonitorUserInterface * mui) const;
	///Checks alarms for single MonitorElements
	std::map< std::string, std::vector<std::string> > checkDetailedQTStatus(MonitorUserInterface * mui) const;
  
  private:

	QTestConfigurationParser * qtParser;
	QTestConfigure * qtConfigurer;
	QTestStatusChecker * qtChecker;
	bool testsConfigured;


};


#endif
