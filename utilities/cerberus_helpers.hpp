#ifndef CERBERUS_HELPERS_H
#define CERBERUS_HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>  //for std::istringstream
#include "../cerberus_utilities/utf8.h"
#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/osrng.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/hex.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/regex.hpp>
#include <boost/unordered_map.hpp>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <crypto++/md5.h> 
#include <cstdio>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <cassert>
#include <string>
#include <iostream>
#include <zmq.hpp>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <sstream>
#include <syslog.h>


#define CPF_CLOEXEC 1

namespace UtfConverter
{
    std::wstring FromUtf8(const std::string& utf8string);
    std::string ToUtf8(const std::wstring& widestring);
}

const std::string encodedKey = "ADEF1E1A2B2CD1E433F01DE4E18A07AA32D5EA9DD488B7619D12DCA30FB573DB";
const std::string encodedIv = "F3375B4660BC1853F9986AA9643B71FD";

int write_to_disk_general(long int, std::string);
int write_to_disk_string(std::string, std::string);
extern std::string core_count();
extern std::string byte_conversion(long double );
extern std::string bit_conversion_sec(long double );
extern std::vector<std::string> read_tmp_stats(std::string , std::vector<std::string> );
extern std::string read_tmp_stats_oneline(std::string ); //modified this line AGAINARGHGHGHGHG
extern std::string encrypt(std::string, std::string, std::string);
extern std::string decrypt(std::string, std::string, std::string);
extern std::string md5value(std::string);
extern int createPidFile(pid_t, std::string);
#endif











