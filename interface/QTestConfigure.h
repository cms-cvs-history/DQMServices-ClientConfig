#ifndef QTestConfigure_H
#define QTestConfigure_H

/** \class QTestConfigure
 * *
 *  Class that creates and defined quality tests based on
 *  the xml configuration file parsed by QTestConfigurationParser.
 *
 * 
 *  $Date: 2008/05/14 12:38:46 $
 *  $Revision: 1.9 $
 *  \author Ilaria Segoni
  */

#include "DQMServices/Core/interface/DQMStore.h"

#include<map>
#include<vector>
#include<iostream>


class QTestConfigure{

 public:
 
  ///Constructor
  QTestConfigure(){}
  ///Destructor
  ~QTestConfigure(){}
  ///Creates and defines quality tests
  bool enableTests(std::map<std::string, std::map<std::string, std::string> > tests, DQMStore * bei); 
  ///Disables the Quality Tests in the string list
  void disableTests(std::vector<std::string> testsOFFList, DQMStore * bei);
  ///Returns the vector containing the names of the quality tests that have been created
  std::vector<std::string> testsReady(){return testsConfigured;}
 
 private:

  ///Creates ContentsXRangeROOT test
  void EnableXRangeTest(std::string testName, 
                        std::map<std::string, std::string>params,DQMStore * bei); 
  ///Creates ContentsXRangeASROOT test
//  void EnableXRangeASTest(std::string testName, 
//                        std::map<std::string, std::string>params,DQMStore * bei); 
  ///Creates ContentsYRangeROOT test
  void EnableYRangeTest(std::string testName, 
                        std::map<std::string, std::string>params,DQMStore * bei); 
  ///Creates ContentsYRangeASROOT test
//  void EnableYRangeASTest(std::string testName, 
//                        std::map<std::string, std::string>params,DQMStore * bei); 
   ///Creates DeadChannelROOT test
  void EnableDeadChannelTest(std::string testName, 
                             std::map<std::string,std::string> params,DQMStore * bei); 
   ///Creates NoisyChannelROOT test
  void EnableNoisyChannelTest(std::string testName, 
                              std::map<std::string,std::string> params,DQMStore * bei);
    ///Creates MeanWithinExpectedROOT test
  void EnableMeanWithinExpectedTest(std::string testName, 
                                    std::map<std::string,std::string> params,DQMStore * bei);

  //===================== new quality tests in the parser =============================//
///Creates Comp2RefEqualH test
 void EnableComp2RefEqualHTest(std::string testName, 
                     std::map<std::string, std::string>params,DQMStore * bei); 

///Creates Comp2RefChi2 test
 void EnableComp2RefChi2Test(std::string testName, 
                     std::map<std::string, std::string>params,DQMStore * bei); 

 ///Creates EnableComp2RefKolmogorov test
 void EnableComp2RefKolmogorovTest(std::string testName, 
                     std::map<std::string, std::string>params,DQMStore * bei); 

  /*
    ///Creates MostProbableLandauROOT test
  void EnableMostProbableLandauTest( const std::string &roTEST_NAME,
                                     std::map<std::string, std::string> &roMParams, DQMStore *bei);
  */

    /// Creates ContentsWithinRangeROOT test
  void EnableContentsWithinExpectedTest(std::string testName,
                                        std::map<std::string,std::string> params,DQMStore * bei);

    /// Creates ContentsWithinRangeROOT test
//  void EnableContentsWithinExpectedASTest(std::string testName,
//                                        std::map<std::string,std::string> params,DQMStore * bei);

  ///Creates ValToMean test
  void EnableValToMeanTest(std::string testName,
                           std::map<std::string,std::string> params,DQMStore * bei); 

 private:
  std::vector<std::string> testsConfigured;
 

};


#endif

