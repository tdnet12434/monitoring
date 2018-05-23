/*
 * Monitor.h
 *
 *  Created on: Feb 5, 2018
 *      Author: matthias
 */

#ifndef SRC_MONITORS_MONITOR_H_
#define SRC_MONITORS_MONITOR_H_

#include "monitoring_msgs/MonitoringArray.h"
#include "ros/ros.h"

class Monitor {
public:
  Monitor(ros::NodeHandle &n, std::string monitorDescription);
  virtual ~Monitor();

  void addValue(std::string key, std::string value, std::string unit, float errorlevel);
  void addValue(std::string key, float value, std::string unit, float errorlevel);

	void publish();

	void resetMsg();

private:
	ros::Publisher pub;
  monitoring_msgs::MonitoringArray ma;
  std::string node_name_;
  std::string monitor_description_;
  int miIndex = 0;
};

#endif /* SRC_MONITORS_MONITOR_H_ */
