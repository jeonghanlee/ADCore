/*
 * plugintest.h
 *
 *  Created on: 8 Apr 2015
 *      Author: Ulrik Kofoed Pedersen, Diamond Light Source
 */

#ifndef ADAPP_PLUGINTESTS_TESTINGUTILITIES_H_
#define ADAPP_PLUGINTESTS_TESTINGUTILITIES_H_

// Newer version of boost requires this:
#if BOOST_VERSION > 105300
#define BOOST_MESSAGE(msg) BOOST_TEST_MESSAGE(msg)
#endif

#include <deque>
#include <string>
#include <vector>

#include <NDArray.h>
#include <asynPortClient.h>

void fillNDArrays(const std::vector<size_t>& dimensions, NDDataType_t dataType, std::vector<NDArray*>& arrays);
void fillNDArraysFromPool(const std::vector<size_t>& dimensions, NDDataType_t dataType, std::vector<NDArray*>& arrays, NDArrayPool *pNDArrayPool);
void uniqueAsynPortName(std::string& name);

// Mock simply stores all received NDArrays and provides them to a client on request.
class TestingPlugin : public asynGenericPointerClient {
public:
  TestingPlugin (const char *portName, int addr);
  ~TestingPlugin();
  void callback(NDArray *pArray);
  std::deque<NDArray *> arrays;
};


#endif /* ADAPP_PLUGINTESTS_TESTINGUTILITIES_H_ */
