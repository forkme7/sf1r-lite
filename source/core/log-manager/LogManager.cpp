#include "LogManager.h"

#include "RDbConnection.h"
#include "SystemEvent.h"
#include "UserQuery.h"
#include "PropertyLabel.h"

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>

#include <util/ustring/algo.hpp>

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <signal.h>

using namespace std;
using namespace boost::filesystem;
using namespace boost::posix_time;

namespace sf1r
{
LogManager::LogManager() {}

bool LogManager::init(const std::string& pathParam, const std::string& language)
{
    if (!RDbConnection::instance().init(pathParam))
        return false;
    if (RDbConnection::instance().logServer())
        return true;
    SystemEvent::createTable();
    UserQuery::createTable();
    PropertyLabel::createTable();

    return true;
}

LogManager::~LogManager()
{
}

bool LogManager::del_database()
{
    //do not delete it on file
//          string order = "rm " + logPath;
//
//          RDbConnection::instance().close();
//          std::system(order.c_str());
//          if(!init(logPath))
//              return false;

    return true;
}

}//end -namespace sf1r
